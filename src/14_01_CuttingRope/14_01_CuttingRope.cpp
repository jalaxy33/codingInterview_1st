// 面试题14（一）：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 根据算术几何不等式：(n1+...+nk)/k >= sqrt[k](n1...nk)。
    int cuttingRope( int n ) {
        // 两个推论：
        // 1）以相等长度分段时，乘积最大；
        // 2）对式子两边同时求导，当长度为e=2.7..时乘积最大，约等于3

        // 切分规则：
        // 1）最优：将绳子尽可能切分为多个长度为3的片段；
        // 2）次优：若最后一段长度为2，则保留；
        // 3）最差：若最后一段长度为1，则把一份1+3替换为2+2

        // 当n<=3时，由于最少要剪出一段长度为1的绳子，返回n-1。
        if ( n <= 3 ) return n - 1;

        int a = n / 3, b = n % 3;
        if ( b == 0 )
            return std::pow( 3, a );
        else if ( b == 1 )
            return std::pow( 3, a - 1 ) * 4;
        else
            return std::pow( 3, a ) * 2;
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