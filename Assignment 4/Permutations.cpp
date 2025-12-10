#include "Permutations.h"
using namespace std;

/* Returns all permutations of the given input string.
 *
 * NOTE: THE INITIAL IMPLEMENTATION PROVIDED HERE IS INCORRECT. You will need
 * to isolate the bug by using the debugger, then answer some questions about
 * why this code is incorrect. Remember that the error consists purely of the
 * addition of a single extra character; you shouldn't need to do any major
 * surgery to repair this function.
 *
 * Should we have used pass-by-const-reference here? Probably. That itself
 * isn't the error, but it is related to what went wrong here.
 */
/*
 * 递归生成字符串的所有排列。
 *
 * 参数说明：
 * - str：还未选择的“剩余字符”
 * - chosen：已经选好的字符（按顺序累加，最终形成一个完整排列）
 */
/*substr(pos, len)
从 pos 位置开始（从 0 开始计数）
取 len 个字符
返回一个新的字符串*/
/*substr(pos)
从 pos 开始，一直到字符串末尾*/
Set<string> permutationsRec(string str, string chosen) {
    /* Base Case: If there are no remaining characters left to consider, then
     * the only permutation possible is the single permutation consisting of
     * what we already committed to.
     */
    //在已选前缀 chosen 的基础上，排列剩下的字符 str，并把所有可能结果返回
    if (str == "") {
        return { chosen };
    }
    /* Recursive Case: Some character has to be the next one in the permutation.
     * Which one should it be? Let's try all possible options and see what we
     * find.
     */
    else {
        /* Hold all permutations we find. */
        Set<string> result;
        for (int i = 0; i < str.size(); i++) {
            /* Form a new string of all the remaining letters by grabbing everything
             * up to but not including the current character, then everything after
             * the current character.
             */
            char ch = str[i];
            string remaining = str.substr(0, i) + str.substr(i + 1);

            /* Find all permutations we can make with this choice and add them into
             * the result.
             */
            Set<string> thisOption = permutationsRec(remaining, chosen + ch);//❌chosen += ch
            result += thisOption;
        }

        /* We've now tried all options, so let's return what we came up with. */
        return result;
    }
}

Set<string> permutationsOf(const string& str) {
    return permutationsRec(str, "");
}

/*第一层调用：
permutationsRec("abc", "")
三个分支：
选 a → permutationsRec("bc", "a")
选 b → permutationsRec("ac", "b")
选 c → permutationsRec("ab", "c")

跑分支 1：选 a
permutationsRec("bc", "a")
又有两种选择：
选 b → permutationsRec("c", "ab")
选 c → permutationsRec("b", "ac")

跑分支 1.1：选 b
permutationsRec("c", "ab")
再选：
剩下只有 c → permutationsRec("", "abc")
返回 {"abc"}

跑分支 1.2：选 c
permutationsRec("b", "ac")
再选：
剩下只有 b → permutationsRec("", "acb")
返回 {"acb"}

所以分支 1 最终产生两种排列：
{"abc", "acb"}

同理分支 2 & 3：
分支 2 选 b → 得到：
{"bac", "bca"}

分支 3 选 c → 得到：
{"cab", "cba"}*/
