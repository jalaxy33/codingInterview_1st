// 面试题10-01：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
// 答案需要取模 1e9+7（1000000007）

#include <iostream>

using namespace std;

class Solution {
   public:
    // 动态规划法
    int fib( int n ) {
        if ( n < 2 ) return n;
        int a = 0, b = 1, sum;
        for ( int i = 0; i < n; i++ ) {
            // 需要考虑大数越界问题，对1000000007(1e9+7,
            // 8个0，最小的十位质数)取余
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
        int result = solution.fib( n );

        cout << "Test for " << n;
        if ( expected == result )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( 0, 0 );
        checkResult( 1, 1 );
        checkResult( 2, 1 );
        checkResult( 3, 2 );
        checkResult( 4, 3 );
        checkResult( 5, 5 );
        checkResult( 6, 8 );
        checkResult( 7, 13 );
        checkResult( 8, 21 );
        checkResult( 9, 34 );
        checkResult( 10, 55 );
        checkResult( 40, 102334155 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}