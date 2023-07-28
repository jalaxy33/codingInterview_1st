// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are
// happy.”， 则输出“We%20are%20happy.”。

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string replaceSpace( string s ) {
        // 初始化
        // 由于直接使用string，因此无需判断边界条件
        int blanks = 0, len = s.size();

        // 先遍历统计空格数量
        for ( char c : s )
            if ( c == ' ' ) blanks++;

        // 根据空格数修改字符串长度
        // 每个空格转换为%20，因此+2
        s.resize( len + 2 * blanks );

        // 倒序遍历修改
        for ( int i = len - 1, j = s.size() - 1; i >= 0 && j > i; i--, j-- ) {
            if ( s[ i ] != ' ' )
                s[ j ] = s[ i ];
            else {
                s[ j - 2 ] = '%';
                s[ j - 1 ] = '2';
                s[ j ] = '0';
                j -= 2; // 由于修改了 3 个元素，因此需要 j -= 2
            }
        }
        return s;
    }
};

class Test {
  public:
    void testMain( string testName, string inputStr, string expectedStr ) {
        if ( !testName.empty() ) cout << testName << " begins: ";

        string resultStr = soultion.replaceSpace( inputStr );

        // cout << "input: " << inputStr << "|result: " << resultStr
        //      << "|expected: " << expectedStr << "|";

        if ( expectedStr.empty() && resultStr.empty() )
            cout << "passed." << endl;
        else if ( expectedStr.empty() && resultStr.empty() )
            cout << "failed." << endl;
        else if ( expectedStr.compare( resultStr ) == 0 )
            cout << "passed." << endl;
        else
            cout << "failed." << endl;
    }

    // 空格在句子中间
    void Test1() {
        string str = "hello world";
        testMain( "Test1", str, "hello%20world" );
    }

    // 空格在句子开头
    void Test2() {

        string str = " helloworld";
        testMain( "Test2", str, "%20helloworld" );
    }

    // 空格在句子末尾
    void Test3() {

        string str = "helloworld ";
        testMain( "Test3", str, "helloworld%20" );
    }

    // 连续有两个空格
    void Test4() {

        string str = "hello  world";
        testMain( "Test4", str, "hello%20%20world" );
    }

    // 传入空字符串
    void Test5() { testMain( "Test5", "", "" ); }

    // 传入内容为空的字符串
    void Test6() {

        string str = "";
        testMain( "Test6", str, "" );
    }

    // 传入内容为一个空格的字符串
    void Test7() {

        string str = " ";
        testMain( "Test7", str, "%20" );
    }

    // 传入的字符串没有空格
    void Test8() {

        string str = "helloworld";
        testMain( "Test8", str, "helloworld" );
    }

    // 传入的字符串全是空格
    void Test9() {

        string str = "   ";
        testMain( "Test9", str, "%20%20%20" );
    }

    void runTests() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
        Test8();
        Test9();
    }

  private:
    Solution soultion;
};

int main() {

    Test test = Test();
    test.runTests();
    return 0;
}
