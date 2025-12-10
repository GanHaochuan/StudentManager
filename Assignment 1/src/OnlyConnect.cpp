/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;

//判断一个字符是否为辅音（保留 Y/y）
static bool isConsonant(char ch) {
    if (!isalpha(ch))
        return false;           // 不是字母 → 不是辅音
    char upper = toUpperCase(ch);
    return upper != 'A' && upper != 'E' && upper != 'I'
           && upper != 'O' && upper != 'U';     // Y 保留
}
string onlyConnectize(string phrase) {
    if (phrase.empty()) {
        return "";
    }

    char first = phrase[0];
    string rest = phrase.substr(1);
    //string substr (size_t pos = 0, size_t len = npos) const;
    //从字符串的第 pos 个位置开始，取长度为 len 的子字符串
    if (isConsonant(first)) {
        return charToString(toUpperCase(first)) + onlyConnectize(rest);
    } else {
        return onlyConnectize(rest);
    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

/*Input:  ganhaochuan2025212219C++
Output: GNHCHNC*/

/*Input:  asjdgbhxilaibg     1654    DCMNKLSDHN
Output: SJDGBHXLBGDCMNKLSDHN*/

/*Input:  ，。//。，’；‘’+
Output: */





