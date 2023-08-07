// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool g_InvalidInput = false;

bool equal( double m, double n ) { return std::abs( m - n ) < 1e-9; }

class Solution {
   public:
    // 快速幂：x^n = x^(n/2) * x^(n/2)。利用分治实现
    double myPow( double x, int n, bool use_iter = false ) {
        // 令n/2为整数，根据奇偶分两种情况
        // x^n = (x^2)^(n//2)  --n为偶数
        //     = x(x^2)^(n//2) --n为奇数

        // 处理不合规的输入
        if ( equal( x, 0. ) && n < 0 ) {
            g_InvalidInput = true;
            return 0.0;
        }

        g_InvalidInput = false;
        if ( use_iter )
            return powIter( x, n );
        else
            return powRecur( x, n );
    }

   private:
    // 迭代实现。
    double powIter( double x, long n ) {
        // 为了防止指数-n溢出，隐式转换为long类型
        if ( n == 0 ) return 1.0;
        if ( equal( x, 0 ) ) return 0.0;

        // 处理负指数
        if ( n < 0 ) {
            x = 1.0 / x;
            n = -n;
        }

        double result = 1.0;
        while ( n > 0 ) {
            if ( n & 0x01 ) result *= x;
            x *= x;
            n >>= 1;
        }
        return result;
    }

    // 递归实现
    double powRecur( double x, long n ) {
        // 为了防止指数-n溢出，隐式转换为long类型
        if ( n == 0 ) return 1.0;
        if ( n < 0 ) return 1.0 / powRecur( x, -n );
        if ( n & 0x01 )
            return x * powRecur( x * x, n >> 1 );
        else
            return powRecur( x * x, n >> 1 );
    }
};

class Test {
   public:
    void checkResult( const string testName, double x, int n, double expected,
                      bool expectedFlag ) {
        cout << testName;
        double result = solution.myPow( x, n );
        if ( equal( result, expected ) && expectedFlag == g_InvalidInput )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        // 底数、指数都为正数
        checkResult( "Test1", 2, 3, 8, false );

        // 底数为负数、指数为正数
        checkResult( "Test2", -2, 3, -8, false );

        // 指数为负数
        checkResult( "Test3", 2, -3, 0.125, false );

        // 指数为0
        checkResult( "Test4", 2, 0, 1, false );

        // 底数、指数都为0
        checkResult( "Test5", 0, 0, 1, false );

        // 底数为0、指数为正数
        checkResult( "Test6", 0, 4, 0, false );

        // 底数为0、指数为负数
        checkResult( "Test7", 0, -4, 0, true );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}