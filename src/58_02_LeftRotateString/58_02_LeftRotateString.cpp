// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string reverseLeftWords( string s, int n, bool use_slice = false ) {
        if ( use_slice )
            return reverse_slicing( s, n );
        else
            return reverse_3times( s, n );
    }

    // 利用三次翻转
    string reverse_3times( string s, int n ) {
        if ( s.empty() ) return "";
        std::reverse( s.begin(), s.begin() + n );
        std::reverse( s.begin() + n, s.end() );
        std::reverse( s.begin(), s.end() );
        return s;
    }

    // 利用字符串切片
    string reverse_slicing( string s, int n ) {
        if ( s.empty() ) return "";
        return s.substr( n ) + s.substr( 0, n );
    }
};

class Test {
   public:
    void checkResult( const string testName, const string input, int num,
                      const string expected ) {
        if ( !testName.empty() > 0 ) cout << testName;

        string result = solution.reverseLeftWords( input, num );

        // cout << "input: " << input << "|result: " << result
        //      << "|expected: " << expected;

        if ( ( input.empty() && expected.empty() ) ||
             ( !input.empty() && result.compare( expected ) == 0 ) )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 功能测试
    void Test1() {
        string input = "abcdefg";
        string expected = "cdefgab";

        checkResult( "Test1", input, 2, expected );
    }

    // 边界值测试
    void Test2() {
        string input = "abcdefg";
        string expected = "bcdefga";

        checkResult( "Test2", input, 1, expected );
    }

    // 边界值测试
    void Test3() {
        string input = "abcdefg";
        string expected = "gabcdef";

        checkResult( "Test3", input, 6, expected );
    }

    // 鲁棒性测试
    void Test3() { checkResult( "Test4", "", 6, "" ); }

    // 鲁棒性测试
    void Test4() {
        string input = "abcdefg";
        string expected = "abcdefg";

        checkResult( "Test5", input, 0, expected );
    }

    // 鲁棒性测试
    void Test6() {
        string input = "abcdefg";
        string expected = "abcdefg";

        checkResult( "Test6", input, 7, expected );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test3();
        Test4();
        Test6();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
