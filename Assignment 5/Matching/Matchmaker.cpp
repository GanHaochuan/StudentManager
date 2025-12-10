#include "Matchmaker.h"
#include "Matching/graphtypes.h"
#include <limits>
using namespace std;
/*fastMaxWeightMatching 函数通过将给定的 links（一个描述各个对象之间关系的加权图）转化为图的边，然后使用 EdRothberg::WeightedMatch 来计算加权匹配（最大权重匹配）。*/
Set<Pair> fastMaxWeightMatching(const Map<string, Map<string, int>>& links) {
    /* Linearize links into a predictable order. */
    //通过将 links 中的对象按顺序编号，生成 order 和 toIndex 映射
    //时间复杂度为 O(n)，其中 n 是 links 中节点的数量
    Map<int, string> order;
    Map<string, int> toIndex;
    for (string name: links) {
        int index = order.size() + 1;
        order[index] = name;
        toIndex[name] = index;
    }

    /* Build the graph. */
    //使用 EdRothberg::NewGraph 创建一个图对象，并将每对有连接的节点（即 src 和 dst）添加边。边的权重由 links[src][dst] 提供
    //时间复杂度是 O(e)，其中 e 是边的数量
    auto graph = EdRothberg::NewGraph(links.size());
    for (const auto& src: links) {
        for (const auto& dst: links[src]) {
            if (toIndex[src] < toIndex[dst]) {
                EdRothberg::AddEdge(graph, toIndex[src], toIndex[dst], links[src][dst]);
            }
        }
    }

    /* Run the matching. */
    //使用 EdRothberg::WeightedMatch 算法计算最大加权匹配
    //时间复杂度为 O(V^3)（通常这种算法基于图的大小，V 是节点数）
    auto matching = EdRothberg::WeightedMatch(graph);
    EdRothberg::FreeGraph(graph);

    /* Convert to pairs. */
    //将匹配结果转化为 Set<Pair> 格式并返回
    //时间复杂度为 O(m)，其中 m 是匹配的数量
    Set<Pair> result;
    for (const auto& entry: matching) {
        result.add({ order[entry.first], order[entry.second] });
    }

    return result;
}

namespace {\
//fastMaxCardinalityMatching 函数计算一个 最大基数匹配，即匹配的边数最大。它将输入的 links 转换为一个所有边权重为 1 的图，并使用 fastMaxWeightMatching 函数来计算该图的最大权重匹配
    Set<Pair> fastMaxCardinalityMatching(const Map<string, Set<string>>& links) {
        /* Transform to a graph where each edge has cost 1. */
        //将 links 中所有的边的权重设置为 1，形成一个新的 newLinks 图
        Map<string, Map<string, int>> newLinks;
        for (const auto& src: links) {
            for (const auto& dst: links[src]) {
                newLinks[src][dst] = 1;
            }
        }

        /* Now find a maximum-weight matching in this new graph. */
        //使用 fastMaxWeightMatching 来计算这个新图的最大权重匹配（由于所有边权重为 1，实际上是计算最大基数匹配）
        return fastMaxWeightMatching(newLinks);
    }
}

//hasPerfectMatching 函数判断给定的 possibleLinks 是否具有 完美匹配，即是否可以为每个节点找到一对匹配。若匹配的数量等于 possibleLinks.size()，则认为是完美匹配
bool hasPerfectMatching(const Map<string, Set<string>>& possibleLinks, Set<Pair>& matching) {
    matching = fastMaxCardinalityMatching(possibleLinks);
    return matching.size() * 2 == possibleLinks.size();
}
// 计算最大加权匹配，并且考虑最大化匹配的边数
Set<Pair> fastMWMCMatching(const Map<string, Map<string, int>>& possibleLinks) {
    /* Artificially boost all the edge costs by an amount such that it is always better to
     * have more edges than fewer edges.
     */
    int maxEdge = 0;
    // 找到所有边中的最大权重
    for (const string& src: possibleLinks) {
        for (const string& dst: possibleLinks[src]) {
            maxEdge = max(maxEdge, possibleLinks[src][dst]);
        }
    }
    // 创建新的图，所有边的权重都被增强
    Map<string, Map<string, int>> newLinks;
    for (const string& src: possibleLinks) {
        for (const string& dst: possibleLinks[src]) {
            /* Each edge is boosted by the score you'd get if everything was paired at the
             * maximum value. Now, any matching has to include the maximum number of edges.
             */
            // 创建新的图，所有边的权重都被增强
            newLinks[src][dst] = possibleLinks[src][dst] + (maxEdge + 1) * possibleLinks.size();
        }
    }
    // 在增强后的图中计算最大权重匹配
    return fastMaxWeightMatching(newLinks);
}
//时间复杂度主要是 O(e + V³ + m)，其中：
//e 是边的数量
//V 是节点的数量
//m 是匹配的数量
