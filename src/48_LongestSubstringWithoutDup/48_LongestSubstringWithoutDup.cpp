// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    // 动态规划+哈希表
    int lengthOfLongestSubstring( string s ) {
        unordered_map<char, int> dic;  // 用来保存字符上次出现的序号
        // i用于指示字符上次出现的位置，result表示不重复的最长长度
        // i初始化为-1：当只有一个字符时，最大距离为1
        int i = -1, result = 0;
        for ( int j = 0; j < s.size(); j++ ) {
            // 如果当前字符在之前出现过，就更新i指针为最近的位置
            if ( dic.find( s[ j ] ) != dic.end() )
                i = std::max( i, dic.find( s[ j ] )->second );
            dic[ s[ j ] ] = j;  // 记录当前字符的位置

            // 转移方程
            // j-i表示字符两次出现的距离，保持result为离得最远的字符的距离
            result = std::max( result, j - i );
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, const string& s, int expected ) {
        if ( !testName.empty() ) cout << testName << " for ";
        cout << "input " << s;

        int result = solution.lengthOfLongestSubstring( s );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", "abcacfrar", 4 );
        checkResult( "Test2", "acfrarabc", 4 );
        checkResult( "Test3", "arabcacfr", 4 );
        checkResult( "Test4", "aaaa", 1 );
        checkResult( "Test5", "abcdefg", 7 );
        checkResult( "Test6", "aaabbbccc", 2 );
        checkResult( "Test7", "abcdcba", 4 );
        checkResult( "Test8", "abcdaef", 6 );
        checkResult( "Test9", "a", 1 );
        checkResult( "Test10", "", 0 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
