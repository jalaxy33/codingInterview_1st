// 面试题14（二）：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 本题与第（一）题基本一致，但是需要考虑大数求余问题。
    int cuttingRope( int n ) {
        if ( n <= 3 ) return n - 1;
        int a = n / 3, b = n % 3, p = int( 1e9 + 7 );
        // 返回值需要取模，需要考虑大数求余的情况。
        // 即返回值中的 3^a 需要对p取余
        if ( b == 0 )
            return int( remainder( 3, a, p ) );
        else if ( b == 1 )
            return int( remainder( 3, a - 1, p ) * 4 % p );
        else
            return int( remainder( 3, a, p ) * 2 % p );
    }

   private:
    // 求 (x^a) % p —— 快速幂求余。
    long remainder( int x, int a, int p ) {
        // (x^a) % p = (x^2)^(a//2) % p
        // 当a为偶数，rem = (x^2)^(a//2) % p
        // 当a为奇数，rem = [(x % p)(x^(a-1) % p)] % p
        //               = [x * (x^2 % p)^(a//2)] % p
        //               = rem * x % p

        // 换个角度，就是将指数a表示为二进制形式，
        // 从低位到高位逐位计算，每一轮将底数平方，模数减半。
        // 当指数最低位为0时，结果不需要计算该位；
        // 当指数最低位为1时，需要计算该位，将上一轮结果与底数相乘。

        long rem = 1, base = x;  // 使用更大的数据类型防止溢出
        // 快速幂
        while ( a > 0 ) {
            if ( a & 1 ) rem = ( rem * base ) % p;
            base = ( base * base ) % p;  // 底数平方
            a >>= 1;                     // 模数减半/右移一位
        }
        return rem;
    }
};

class Test {
   public:
    void checkResult( const string testName, int n, int expected ) {
        cout << testName;
        int result = solution.cuttingRope( n );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 1, 0 );
        checkResult( "Test2", 2, 1 );
        checkResult( "Test3", 3, 2 );
        checkResult( "Test4", 4, 4 );
        checkResult( "Test5", 5, 6 );
        checkResult( "Test6", 6, 9 );
        checkResult( "Test7", 7, 12 );
        checkResult( "Test8", 8, 18 );
        checkResult( "Test9", 9, 27 );
        checkResult( "Test10", 10, 36 );
        checkResult( "Test11", 50, 86093442 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}