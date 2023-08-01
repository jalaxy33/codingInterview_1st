// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 从右往左逐位取余
    int translateNum( int num ) {
        if ( num < 0 ) return 0;

        // dp[i]表示从右往左以第i个数字开头的翻译方案数
        // a=dp[i-1], b=dp[i-2]
        // x是数字的十位，y是数字的个位
        int a = 1, b = 1, x, y = num % 10;
        while ( num > 9 ) {
            num /= 10;
            x = num % 10;
            int tmp = 10 * x + y;
            // 判断末两位是否在[10, 25]范围内，若是则dp[i]=a+b，否则dp[i]=a
            int c = ( tmp >= 10 && tmp <= 25 ) ? a + b : a;
            b = a;  // dp[i-2] = dp[i-1]
            a = c;  // dp[i-1] = dp[i]
            y = x;  // 个位=十位
        }
        return a;
    }
};

class Test {
   public:
    void checkResult( const string testName, int num, int expected ) {
        if ( !testName.empty() ) cout << testName;

        if ( solution.translateNum( num ) == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 0, 1 );
        checkResult( "Test2", 10, 2 );
        checkResult( "Test3", 125, 3 );
        checkResult( "Test4", 126, 2 );
        checkResult( "Test5", 426, 1 );
        checkResult( "Test6", 100, 2 );
        checkResult( "Test7", 101, 2 );
        checkResult( "Test8", 12258, 5 );
        checkResult( "Test9", -100, 0 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}