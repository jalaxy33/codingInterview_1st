// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
// 能使用atoi或者其他类似的库函数。
// 在任何情况下，若函数不能进行有效的转换时，请返回 0。

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

enum Status { sValid, sInvalid };
int g_status = sValid;  // 全局标记，用来标记转换是否成功

class Solution {
   public:
    int strToInt( string str ) {
        g_status = sInvalid;

        int result = 0, boundary = INT32_MAX / 10;
        int i = 0, sign = 1, length = str.length();
        if ( length == 0 ) return 0;
        // 忽略开头的空格
        while ( str[ i ] == ' ' )
            if ( ++i == length ) return 0;
        // 处理正负号
        if ( str[ i ] == '-' ) sign = -1;
        if ( str[ i ] == '-' || str[ i ] == '+' ) i++;
        // 处理其他字符
        bool hasDigit = false;
        for ( int j = i; j < length; j++ ) {
            if ( str[ j ] < '0' || str[ j ] > '9' ) break;
            // INT_MAX 最后一位为7
            if ( result > boundary || result == boundary && str[ j ] > '7' ) {
                g_status = sValid;
                return sign == 1 ? INT32_MAX : INT32_MIN;
            }
            result = result * 10 + ( str[ j ] - '0' );
            hasDigit = true;
        }
        if ( hasDigit ) g_status = sValid;
        return sign * result;
    }
};

class Test {
   public:
    void checkResult( const string str ) {
        int result = solution.strToInt( str );
        if ( result == 0 && g_status == sInvalid )
            cout << "the input " << str << " is invalid.\n";
        else
            cout << "number for " << str << " is " << result << endl;
    }

    void runTest() {
        checkResult( "" );

        checkResult( "123" );

        checkResult( "+123" );

        checkResult( "-123" );

        checkResult( "1a33" );

        checkResult( "+0" );

        checkResult( "-0" );

        // 有效的最大正整数, 0x7FFFFFFF
        checkResult( "+2147483647" );

        checkResult( "-2147483647" );

        checkResult( "+2147483648" );

        // 有效的最小负整数, 0x80000000
        checkResult( "-2147483648" );

        checkResult( "+2147483649" );

        checkResult( "-2147483649" );

        checkResult( "+" );

        checkResult( "-" );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
