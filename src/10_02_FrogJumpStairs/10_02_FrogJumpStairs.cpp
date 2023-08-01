// 面试题10-02. 青蛙跳台阶问题
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
// 求该青蛙跳上一个 n 级的台阶总共有多少种跳法。答案需要取模 1e9+7（1000000007）

#include <iostream>

using namespace std;

class Solution {
   public:
    // 动态规划，本质上就是起点不同的斐波那契数列
    int numWays( int n ) {
        if ( n < 2 ) return 1;
        int a = 1, b = 1, sum;
        for ( int i = 0; i < n; i++ ) {
            sum = ( a + b ) % MOD;
            a = b;
            b = sum;
        }
        return a;
    }

   private:
    const int MOD = int( 1e9 + 7 );
};

class Test {
   public:
    void checkResult( int n, int expected ) {
        int result = solution.numWays( n );

        cout << "Test for " << n;
        // cout << ", result is " << result;
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( 0, 1 );
        checkResult( 1, 1 );
        checkResult( 2, 2 );
        checkResult( 3, 3 );
        checkResult( 4, 5 );
        checkResult( 5, 8 );
        checkResult( 6, 13 );
        checkResult( 7, 21 );
        checkResult( 8, 34 );
        checkResult( 9, 55 );
        checkResult( 10, 89 );
        checkResult( 40, 165580141 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}