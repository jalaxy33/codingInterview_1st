// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数、小数和空格）。例如，
// 字符串“+100”、“5e2”、“  -123”、“3.1416”及“-1E-16 ”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isNumber( string s ) {
        // s为空对象或长度为0（空字符串）时，不能表示数值
        if ( s.empty() || s.length() == 0 ) return false;
        // 标记位
        bool isDigit = false, isDot = false, isE = false;

        string str = s;
        // 去除首尾的空格
        str.erase( 0, str.find_first_not_of( " " ) );
        str.erase( str.find_last_not_of( " " ) + 1 );

        // 遍历每个字符
        for ( int i = 0; i < str.length(); i++ ) {
            char c = str[ i ];
            if ( c >= '0' && c <= '9' )
                // 遇到数字
                isDigit = true;
            else if ( c == '.' ) {
                // 遇到小数点，则之前不能有小数点或幂符号
                if ( isDot || isE ) return false;
                isDot = true;  // 标记遇到小数点
            } else if ( c == 'e' || c == 'E' ) {
                // 遇到幂符号，则之前必须有数字，且不能重复有幂符号
                if ( !isDigit || isE ) return false;
                isE = true;       // 标记遇到幂符号
                isDigit = false;  // 重置数字标记，e后必须是数字
            } else if ( c == '+' || c == '-' ) {
                // 遇到正负号，只能出现在首位，或在e后的第一个位置
                if ( i != 0 && str[ i - 1 ] != 'e' && str[ i - 1 ] != 'E' )
                    return false;
            } else {
                // 其他情况均非法
                return false;
            }
        }
        return isDigit;
    }
};

class Test {
   public:
    void checkResult( string testName, string str, bool expected ) {
        if ( !testName.empty() ) cout << testName;

        if ( solution.isNumber( str ) == expected )
            cout << " pased.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", "100", true );
        checkResult( "Test2", "123.45e+6  ", true );
        checkResult( "Test3", "+500   ", true );
        checkResult( "Test4", " 5e2", true );
        checkResult( "Test5", "3.1416", true );
        checkResult( "Test6", "  600.", true );
        checkResult( "Test7", "-.123", true );
        checkResult( "Test8", "-1E-16  ", true );
        checkResult( "Test9", "1.79769313486232E+308", true );

        cout << "\n\n";

        checkResult( "Test10", "12e", false );
        checkResult( "Test11", "1a3.14", false );
        checkResult( "Test12", "1+23", false );
        checkResult( "Test13", "1.2.3", false );
        checkResult( "Test14", "+-5", false );
        checkResult( "Test15", "12e+5.4", false );
        checkResult( "Test16", ".", false );
        checkResult( "Test17", ".e1", false );
        checkResult( "Test18", "e1", false );
        checkResult( "Test19", "+.", false );
        checkResult( "Test20", "", false );
        checkResult( "Test21", "   ", false );
        checkResult( "Test22", " .  ", false );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
