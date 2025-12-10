#include "HumanPyramids.h"
#include "error.h"
#include <vector>
#include <cmath>
using namespace std;


double weightOnBackOfplus(int row, int col, int pyramidHeight,vector<vector<double>>& memo) {
    static double single = 160.0;
    double now= 0.0;
    if(row<0||col<0||col>row||row>=pyramidHeight)
        error("请重新输入");
    if (!std::isnan(memo[row][col])) {
        return memo[row][col];
    }
    if(row==0){
        memo[row][col]=0.0;
        return 0.0;
    }
    // 来自左上方 (row-1, col-1) 的贡献（如果存在）
    // 该左上方的人将其自身的一半重量以及其肩上承受重量的一半，分摊到右下和左下两个人身上。
    if(col>0)
        now+=(single+ weightOnBackOfplus(row-1, col-1, pyramidHeight,memo))*0.5;
    // 来自右上方 (row-1, col) 的贡献（如果存在）
    if(col<row)
        now+=(single+ weightOnBackOfplus(row-1, col, pyramidHeight,memo))*0.5;
    memo[row][col]=now;
    return now;
}

double weightOnBackOf(int row, int col, int pyramidHeight){
    vector<vector<double>> memo(pyramidHeight,vector<double>(pyramidHeight,NAN));
    return weightOnBackOfplus(row,col,pyramidHeight,memo);
}


/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */



/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */
    //SHOW_ERROR("This test is configured to always fail until you delete this line from\n         HumanPyramids.cpp. Once you have implemented memoization and want\n         to check whether it works correctly, remove the indicated line.");

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
