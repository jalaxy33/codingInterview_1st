// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 快慢指针
    string reverseWords( string s ) {
        if ( s.empty() ) return "";
        string result;
        int left = 0, right = s.size() - 1;
        // 去掉两端空格
        while ( right > left && s[ right ] == ' ' ) right--;
        while ( right > left && s[ left ] == ' ' ) left++;

        while ( right >= left ) {
            int end = right;
            // 从右往左搜索首个空格，并添加单词
            while ( right >= left && s[ right ] != ' ' ) right--;
            result += s.substr( right + 1, end - right );
            result += ' ';  // 单词间需要有空格
            // 跳过单词间原有的空格
            while ( right >= left && s[ right ] == ' ' ) right--;
        }
        result.pop_back();  // 去掉最后添加的空格
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, string s, string expected ) {
        cout << testName;
        string result = solution.reverseWords( s );

        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 功能测试，句子中有多个单词
    void Test1() {
        string s = "I am a student.";
        string expected = "student. a am I";

        checkResult( "Test1", s, expected );
    }

    // 功能测试，句子中只有一个单词
    void Test2() {
        string s = "Wonderful";
        string expected = "Wonderful";

        checkResult( "Test2", s, expected );
    }

    // 边界值测试，测试空字符串
    void Test3() { checkResult( "Test3", "", "" ); }

    // 边界值测试，字符串中只有空格
    void Test4() {
        string s = "   ";
        string expected = "";
        checkResult( "Test4", s, expected );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
