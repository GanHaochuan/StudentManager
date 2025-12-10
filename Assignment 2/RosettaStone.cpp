#include "RosettaStone.h"
#include "GUI/SimpleTest.h"
#include "priorityqueue.h"
using namespace std;

/*
     * Operator: []
     * Usage: map[key]
     * ---------------
     * Selects the value associated with <code>key</code>.  This syntax
     * makes it easy to think of a map as an "associative array"
     * indexed by the key type.  If <code>key</code> is already present
     * in the map, this function returns a reference to its associated
     * value.  If key is not present in the map, a new entry is created
     * whose value is set to the default for the value type.
     */  //key 已经在 map 中，返回该 key 对应的 value 的引用；key 不存在，会自动在 map 中插入一条新记录，value = 默认值（数值类型默认是 0）
//ValueType& operator [](const KeyType& key);

/*
     * Method: containsKey
     * Usage: if (map.containsKey(key)) ...
     * ------------------------------------
     * Returns <code>true</code> if there is an entry for <code>key</code>
     * in this map.
     */
//bool containsKey(const KeyType& key) const;

/*
     * Method: put
     * Usage: map.put(key, value);
     * ---------------------------
     * Associates <code>key</code> with <code>value</code> in this map.
     * Any previous value associated with <code>key</code> is replaced
     * by the new value.
     */
//void put(const KeyType& key, const ValueType& value);

//string substr (size_t pos, size_t len) const;
/*pos：要截取的起始位置（从 0 开始）
len：要截取的长度（字符个数）
返回一个新的字符串，包含 str[pos] 开始的 len 个字符。*/

/*
     * Method: get
     * Usage: ValueType value = map.get(key);
     * --------------------------------------
     * Returns the value associated with <code>key</code> in this map.
     * If <code>key</code> is not found, <code>get</code> returns the
     * default value for <code>ValueType</code>.
     */ //✔ 如果 key 存在，返回它对应的 value   ✔ 如果 key 不存在，返回 ValueType 的默认值，但 不会向 map 中插入新键
//ValueType get(const KeyType& key) const;

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a structure called a <b><i>priority&nbsp;queue</i></b>
 * in which values are processed in order of priority.  As in conventional
 * English usage, lower priority numbers correspond to higher effective
 * priorities, so that a priority 1 item takes precedence over a
 * priority 2 item.
 */  //priority 越小 → 越先弹出；priority 越大 → 越晚弹出


Map<string, double> kGramsIn(const string& str, int kGramLength) {
    Map<string,double>res={};
    if(kGramLength<0){
        error("错误，请输入恰当的正数");
        return {};
    }
    else if(kGramLength==0){
        error("错误，请输入恰当的正数");
        return {};
    }
    else if(kGramLength<=str.length()){
        int now=0;
        while(now+kGramLength<=str.length()){
            string tem=str.substr(now,kGramLength);
            res[tem] += 1;
            /*if(res.containsKey(tem))//判断当前子串 tem 是否已经出现过
                res[tem]++;//出现过 → 计数 +1
            else
                res.put(tem,1);//第一次出现 → 插入 map 并设置计数为 1*/
            now++;
        }
    }
    return res;
    (void) str;
    (void) kGramLength;
    return {};
}

Map<string, double> normalize(const Map<string, double>& input) {
    double sum = 0;
    bool allZero = true;

    if (input.isEmpty()) {
        error("input is empty");
        return {};
    }

    for (const string& key : input.keys()) {
        double v = input.get(key);
        if (v != 0)
            allZero = false;
        sum += v * v;
    }

    if (allZero) {
        error("all values are zero");
        return {};
    }

    double norm = sqrt(sum);
    Map<string, double> ans = input;

    for (const string& key : ans.keys()) {
        ans[key] /= norm;
    }
    return ans;
    (void) input;
    return {};
}

Map<string, double> topKGramsIn(const Map<string, double>& source, int numToKeep) {
    if (numToKeep < 0) {
        error("negative");
        return {};
    }

    PriorityQueue<string> minHeap;   // priority 越小 -> 越优先出队

    for (const string& key : source) {
        double freq = source.get(key);

        // 入堆
        minHeap.enqueue(key, freq);

        // 如果堆的大小超过 k，说明里面装了太多元素
        // 此时 PQ 会把优先级最小的（也就是 freq 最小的）元素放在堆顶
        // 我们将它弹出，从而始终保持堆中是频率最大的 k 个 key
        if (minHeap.size() > numToKeep) {
            minHeap.dequeue();
        }
    }

    // 堆中即保留了 Top-K 最大元素
    Map<string, double> result;
    while (!minHeap.isEmpty()) {
        string s = minHeap.dequeue();
        result.put(s, source.get(s));// 注意：这里取出的顺序不保证从大到小，但对 Map 来说无影响
    }
    return result;
    (void) source;
    (void) numToKeep;
    return {};
}

double cosineSimilarityOf(const Map<string, double>& lhs, const Map<string, double>& rhs) {
    // 如果任一 map 为空，则没有共同 key，相似度为 0
    if (lhs.isEmpty() || rhs.isEmpty()) {
        return 0.0;
    }

    double sum = 0.0;

    /* 为了提升效率：遍历较小的 map，减少 containsKey() 查询次数 */
    const Map<string, double>& small  = (lhs.size() < rhs.size()) ? lhs : rhs;
    const Map<string, double>& large  = (lhs.size() < rhs.size()) ? rhs : lhs;

    // 遍历较小的 map，检查哪些 key 在 large 中也存在
    for (const string& key : small) {

        // 如果 large 中也有这个 key，则相似度增加它们频率的乘积
        if (large.containsKey(key)) {   //containsKey(key) 用来判断 map 是否包含某个 key
            double v1 = small.get(key);
            double v2 = large.get(key);
            sum += v1 * v2;
        }
    }
    return sum;   // 已归一化，无需除以模长
    (void) lhs;
    (void) rhs;
    return {};
}

string guessLanguageOf(const Map<string, double>& textProfile,
                       const Set<Corpus>& corpora) {
    if (corpora.isEmpty()) {
        error("没有语料库可以比较");
    }

    string bestLanguage;       // 当前最可能的语言
    double bestScore = -1;     // 记录最大余弦相似度（合法范围 0～1）

    // 遍历每一个语料库
    for (const Corpus& corpus : corpora) {

        // corpus.profile 已经是归一化 & 截断过的
        double score = cosineSimilarityOf(textProfile, corpus.profile);

        // 如果分数更高 → 更新最高分
        if (score > bestScore) {
            bestScore = score;
            bestLanguage = corpus.name;
        }
    }
    // 返回最高分对应的语言名称
    return bestLanguage;
    (void) textProfile;
    (void) corpora;
    return "";
}




/* * * * *   Test Cases Below This Point   * * * * */




PROVIDED_TEST("kGramsIn works when the text length exactly matches the k-gram length.") {
    Map<string, double> expected = {
        { "^_^", 1 }
    };

    EXPECT_EQUAL(kGramsIn("^_^", 3), expected);
}

PROVIDED_TEST("kGramsIn works when the text length is one more than the k-gram length.") {
    Map<string, double> expected = {
        { "the", 1 },
        { "hem", 1 }
    };

    EXPECT_EQUAL(kGramsIn("them", 3), expected);
}

PROVIDED_TEST("kGramsIn works when the text length is one more than the k-gram length.") {
    /* First check: when no k-grams are repeated. */
    Map<string, double> expected = {
        { "the", 1 },
        { "hem", 1 }
    };

    EXPECT_EQUAL(kGramsIn("them", 3), expected);

    /* Next check: when the k-grams are repeated. */
    expected = {
        { "aaa", 2 }
    };

    EXPECT_EQUAL(kGramsIn("aaaa", 3), expected);
}

PROVIDED_TEST("kGramsIn works on a sample when k = 1.") {
    Map<string, double> expected = {
        { "A", 7 },
        { "B", 2 },
        { "D", 1 },
        { "N", 4 },
    };

    EXPECT_EQUAL(kGramsIn("ABANANABANDANA", 1), expected);
}

PROVIDED_TEST("kGramsIn works on a sample when k = 2.") {
    Map<string, double> expected = {
        { "AB", 2 },
        { "AN", 4 },
        { "BA", 2 },
        { "DA", 1 },
        { "NA", 3 },
        { "ND", 1 }
    };

    EXPECT_EQUAL(kGramsIn("ABANANABANDANA", 2), expected);
}

PROVIDED_TEST("kGramsIn handles non-English strings.") {
    /* The characters in these strings are expressed in UTF-8. This
     * means that splitting the string into k-grams will produce some
     * k-grams containing fragments of individual characters. See
     * the assignment description for more details about what's
     * going on here.
     */
    string devanagari = "दे";
    Map<string, double> expected = {
      {"\244\246\340", 1},
      {"\246\340\245", 1},
      {"\340\244\246", 1},
      {"\340\245\207", 1}
    };
    EXPECT_EQUAL(kGramsIn(devanagari, 3), expected);

    string ktavAshuri = "דָג";
    expected = {
        {"\223\326\270", 1},
        {"\270\327\222", 1},
        {"\326\270\327", 1},
        {"\327\223\326", 1}
    };
    EXPECT_EQUAL(kGramsIn(ktavAshuri, 3), expected);
}

PROVIDED_TEST("kGramsIn works when the input is shorter than the k-gram length.") {
    EXPECT_EQUAL(kGramsIn("ABANANABANDANA", 137), {});
}

PROVIDED_TEST("kGramsIn reports errors on bad inputs.") {
    EXPECT_ERROR(kGramsIn("Oops, negative", -137));
    EXPECT_ERROR(kGramsIn("Oops, zero",     0));
}

PROVIDED_TEST("normalize does not add or remove keys.") {
    Map<string, double> incomplete = {
        { "C", 1 },
        { "O", 1 },
        { "N", 1 },
        { "E", 1 }
    };

    auto result = normalize(incomplete);
    EXPECT(result.containsKey("C"));
    EXPECT(result.containsKey("O"));
    EXPECT(result.containsKey("N"));
    EXPECT(result.containsKey("E"));
    EXPECT_EQUAL(result.size(), 4);
}

PROVIDED_TEST("normalize works on positive numbers.") {
    Map<string, double> scores = {
        { "C", 1 },
        { "O", 1 },
        { "N", 1 },
        { "E", 1 },
    };
    Map<string, double> expected = {
        { "C", 0.5 },
        { "O", 0.5 },
        { "N", 0.5 },
        { "E", 0.5 },
    };

    EXPECT_EQUAL(normalize(scores), expected);
}

PROVIDED_TEST("normalize works on negative numbers.") {
    Map<string, double> scores = {
        { "C", -1 },
        { "O", -1 },
        { "N", -1 },
        { "E", -1 },
    };
    Map<string, double> expected = {
        { "C", -0.5 },
        { "O", -0.5 },
        { "N", -0.5 },
        { "E", -0.5 },
    };

    EXPECT_EQUAL(normalize(scores), expected);
}

PROVIDED_TEST("normalize works on unequal values.") {
    Map<string, double> scores = {
        { "O",  3 },
        { "N", -4 },
    };
    Map<string, double> expected = {
        { "O",  0.6 },
        { "N", -0.8 },
    };

    EXPECT_EQUAL(normalize(scores), expected);
}

PROVIDED_TEST("normalize works on huge numbers.") {
    /* As mentioned in the assignment description, the int type
     * is (usually) limited to a range of roughly negative two
     * billion to roughly positive two billion. The double type,
     * however, can handle this just fine. This test case checks
     * to make sure that large numbers are processed correctly.
     * If you store any intermediary calculation values in an
     * int rather than a double, it may cause this test
     * to fail.
     */
    Map<string, double> scores = {
        { "singleton", 1e18 }
    };

    auto result = normalize(scores);
    EXPECT_EQUAL(result.size(), 1);
    EXPECT(result.containsKey("singleton"));

    /* doubles store rounded values, so with large values being
     * calculated we may end up with a value that's slightly
     * wrong. These error bounds should catch this.
     */
    EXPECT_LESS_THAN_OR_EQUAL_TO(result["singleton"], 10);
    EXPECT_GREATER_THAN_OR_EQUAL_TO(result["singleton"], 0.0);
}

PROVIDED_TEST("normalize reports errors on inputs that are all zero.") {
    EXPECT_ERROR(normalize({}));
    EXPECT_ERROR(normalize({{"A", 0}, {"C", 0}, {"E", 0}}));
}

PROVIDED_TEST("topKGramsIn finds the most frequent k-gram.") {
    Map<string, double> input = {
        { "A", 10 },
        { "B", 30 },
        { "C", 20 }
    };

    Map<string, double> expected = {
        { "B", 30 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 1), expected);
}

PROVIDED_TEST("topKGramsIn finds the top two k-grams.") {
    Map<string, double> input = {
        { "A", 10 },
        { "B", 30 },
        { "C", 20 }
    };

    Map<string, double> expected = {
        { "B", 30 },
        { "C", 20 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 2), expected);
}

PROVIDED_TEST("topKGramsIn works if all k-grams are requested.") {
    Map<string, double> input = {
        { "A", 10 },
        { "B", 30 },
        { "C", 20 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 3), input);
}

PROVIDED_TEST("topKGramsIn works if more k-grams are requested than exist.") {
    Map<string, double> input = {
        { "A", 10 },
        { "B", 30 },
        { "C", 20 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 137), input);
}

PROVIDED_TEST("topKGramsIn works if no k-grams are requested.") {
    Map<string, double> input = {
        { "A", 10 },
        { "B", 30 },
        { "C", 20 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 0), {});
}

PROVIDED_TEST("topKGramsIn reports errors on bad inputs.") {
    Map<string, double> input = {
        { "A", 10 },
        { "B", 30 },
        { "C", 20 }
    };

    EXPECT_ERROR(topKGramsIn(input, -137));
}

PROVIDED_TEST("topKGramsIn works even if frequencies are negative.") {
    Map<string, double> input = {
        { "A",  2 },
        { "B",  1 },
        { "C",  0 },
        { "D", -1 },
        { "E", -2 },
        { "F", -3 },
        { "G", -4 },
        { "H", -5 }
    };

    Map<string, double> expected = {
        { "A",  2 },
        { "B",  1 },
        { "C",  0 },
        { "D", -1 },
        { "E", -2 },
    };

    EXPECT_EQUAL(topKGramsIn(input, 5), expected);
}

PROVIDED_TEST("topKGramsIn works with fractional weights.") {
    Map<string, double> input = {
        { "A", 10.1 },
        { "B", 10.2 },
        { "C", 10.3 }
    };
    Map<string, double> expected = {
        { "C", 10.3 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 1), expected);

    input = {
        { "A", 10.3 },
        { "B", 10.2 },
        { "C", 10.1 }
    };
    expected = {
        { "A", 10.3 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 1), expected);

    input = {
        { "A", 10.2 },
        { "B", 10.3 },
        { "C", 10.1 }
    };
    expected = {
        { "B", 10.3 }
    };

    EXPECT_EQUAL(topKGramsIn(input, 1), expected);
}

PROVIDED_TEST("cosineSimilarityOf works with one shared key.") {
    Map<string, double> one = {
        { "A",  1 },
    };
    Map<string, double> two = {
        { "A",  1 },
    };
    EXPECT_EQUAL(cosineSimilarityOf(one, two), 1);
}

PROVIDED_TEST("cosineSimilarityOf works with two maps with non-overlapping keys.") {
    Map<string, double> one = {
        { "A",  1 },
    };
    Map<string, double> two = {
        { "B",  1 },
    };
    EXPECT_EQUAL(cosineSimilarityOf(one, two), 0);
}

PROVIDED_TEST("cosineSimilarityOf works where keys are present in RHS but not LHS.") {
    /* Yes, we know these aren't normalized and that we promised that we would normalize
     * all inputs to cosineSimilarityOf. This is just for testing purposes.
     */
    Map<string, double> one = {
        { "O",  1 },
        { "C",  2 },
        { "E",  3 },
        { "A",  4 },
        { "N",  5 },
    };
    Map<string, double> two = {
        { "C", -2 },
        { "E", -3 },
        { "A", -4 },
        { "N", -5 },
    };
    EXPECT_EQUAL(cosineSimilarityOf(one, two), -54);
}

PROVIDED_TEST("cosineSimilarityOf works where keys are present in LHS but not RHS.") {
    /* Yes, we know these aren't normalized and that we promised that we would normalize
     * all inputs to cosineSimilarityOf. This is just for testing purposes.
     */
    Map<string, double> one = {
        { "C",  2 },
        { "E",  3 },
        { "A",  4 },
        { "N",  5 },
    };
    Map<string, double> two = {
        { "O",  1 },
        { "C", -2 },
        { "E", -3 },
        { "A", -4 },
        { "N", -5 },
    };
    EXPECT_EQUAL(cosineSimilarityOf(one, two), -54);
}

PROVIDED_TEST("cosineSimilarityOf works with keys missing from both sides.") {
    /* Yes, we know these aren't normalized and that we promised that we would normalize
     * all inputs to cosineSimilarityOf. This is just for testing purposes.
     */
    Map<string, double> one = {
        { "C",  2 },
        { "E",  3 },
        { "A",  4 },
    };
    Map<string, double> two = {
        { "O",  1 },
        { "E", -3 },
        { "A", -4 },
    };
    EXPECT_EQUAL(cosineSimilarityOf(one, two), -25);
}

PROVIDED_TEST("guessLanguageOf works with perfect similarity.") {
    Corpus o = { "Language O", {{ "O", 1 }} },
           c = { "Language C", {{ "C", 1 }} },
           e = { "Language E", {{ "E", 1 }} },
           a = { "Language A", {{ "A", 1 }} },
           n = { "Language N", {{ "N", 1 }} };

    EXPECT_EQUAL(guessLanguageOf({{ "O", 1 }}, {o, c, e, a, n}), o.name);
    EXPECT_EQUAL(guessLanguageOf({{ "C", 1 }}, {o, c, e, a, n}), c.name);
    EXPECT_EQUAL(guessLanguageOf({{ "E", 1 }}, {o, c, e, a, n}), e.name);
    EXPECT_EQUAL(guessLanguageOf({{ "A", 1 }}, {o, c, e, a, n}), a.name);
    EXPECT_EQUAL(guessLanguageOf({{ "N", 1 }}, {o, c, e, a, n}), n.name);
}

PROVIDED_TEST("guessLanguageOf works with imperfect similarity.") {
    Corpus o = { "Language O", {{ "O", 2 }, {"C", 1}} },
           c = { "Language C", {{ "C", 2 }, {"E", 1}} },
           e = { "Language E", {{ "E", 2 }, {"A", 1}} },
           a = { "Language A", {{ "A", 2 }, {"N", 1}} },
           n = { "Language N", {{ "N", 2 }, {"O", 1}} };

    EXPECT_EQUAL(guessLanguageOf({{"O", 1}}, {o, c, e, a, n}), o.name);
    EXPECT_EQUAL(guessLanguageOf({{"C", 1}}, {o, c, e, a, n}), c.name);
    EXPECT_EQUAL(guessLanguageOf({{"E", 1}}, {o, c, e, a, n}), e.name);
    EXPECT_EQUAL(guessLanguageOf({{"A", 1}}, {o, c, e, a, n}), a.name);
    EXPECT_EQUAL(guessLanguageOf({{"N", 1}}, {o, c, e, a, n}), n.name);
}

PROVIDED_TEST("guessLanguageOf works on more complex inputs.") {
    Corpus karel  = { "Karel",  {{"R", 1}, {"O", 2}, {"B", 1}, {"T", 1}} };
    Corpus trisha = { "Trisha", {{"T", 1}, {"R", 1}, {"I", 1}, {"S", 1}, {"H", 1}, {"A", 1}} };
    Corpus chris  = { "Chris",  {{"C", 1}, {"H", 1}, {"R", 1}, {"I", 1}, {"S", 1}} };
    Corpus jerry  = { "Jerry",  {{"J", 1}, {"E", 1}, {"R", 2}, {"Y", 1}} };

    EXPECT_EQUAL(guessLanguageOf({{"R", 1}}, {karel, trisha, chris, jerry}), jerry.name);
}

PROVIDED_TEST("guessLanguageOf reports errors if no corpora are provided.") {
    EXPECT_ERROR(guessLanguageOf({}, {}));
    EXPECT_ERROR(guessLanguageOf({{"C", -1}}, {}));
}
