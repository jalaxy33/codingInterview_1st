// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isMatch( string s, string p ) {
        int m = s.size() + 1, n = p.size() + 1;
        // 定义转移矩阵dp，dp[i][j]表示s的前i-1和p的前j-1个字符是否能匹配
        Mat dp( m, Vec( n, false ) );
        dp[ 0 ][ 0 ] = true;  // 两个空字符串匹配

        // 初始化首行
        // 首行s为空字符串，只有p的偶数位为*才能匹配上，即让奇数位字符出现0次，
        // 以保持p是空字符串。遍历p字符串，步长为偶数（只看偶数位）。
        for ( int j = 2; j < n; j += 2 )
            dp[ 0 ][ j ] = dp[ 0 ][ j - 2 ] && p[ j - 1 ] == '*';

        // 状态转移
        for ( int i = 1; i < m; i++ ) {
            for ( int j = 1; j < n; j++ ) {
                bool condition = false;
                // 根据p的j-1位是否为'*'分类讨论
                if ( p[ j - 1 ] == '*' ) {
                    // 在以下情况condition为true
                    // 1) s[:i)==p[:j-2), p的第i-1位重复0次
                    condition = dp[ i ][ j - 2 ];
                    // 2) s[:i-1)==p[:j) 且 (p[j-2]字符再出现一次，或为'.')
                    condition |=
                        ( dp[ i - 1 ][ j ] &&
                          ( p[ j - 2 ] == s[ i - 1 ] || p[ j - 2 ] == '.' ) );
                } else {
                    // 在以下情况condition为true
                    // s[:i-1)==p[:j-1) 且
                    // (s的第i-1和p的第j-1个字符相同，或p[j-1]为'.')
                    condition = dp[ i - 1 ][ j - 1 ];
                    condition &=
                        ( s[ i - 1 ] == p[ j - 1 ] || p[ j - 1 ] == '.' );
                }

                dp[ i ][ j ] = condition;
            }
        }

        return dp[ m - 1 ][ n - 1 ];  // 返回矩阵右下角结果
    }

   private:
    using Vec = vector<bool>;
    using Mat = vector<Vec>;
};

class Test {
   public:
    void checkResult( const string testName, const string s, const string p,
                      bool expected ) {
        if ( !testName.empty() ) cout << testName;

        if ( solution.isMatch( s, p ) == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test01", "", "", true );
        checkResult( "Test02", "", ".*", true );
        checkResult( "Test03", "", ".", false );
        checkResult( "Test04", "", "c*", true );
        checkResult( "Test05", "a", ".*", true );
        checkResult( "Test06", "a", "a.", false );
        checkResult( "Test07", "a", "", false );
        checkResult( "Test08", "a", ".", true );
        checkResult( "Test09", "a", "ab*", true );
        checkResult( "Test10", "a", "ab*a", false );
        checkResult( "Test11", "aa", "aa", true );
        checkResult( "Test12", "aa", "a*", true );
        checkResult( "Test13", "aa", ".*", true );
        checkResult( "Test14", "aa", ".", false );
        checkResult( "Test15", "ab", ".*", true );
        checkResult( "Test16", "ab", ".*", true );
        checkResult( "Test17", "aaa", "aa*", true );
        checkResult( "Test18", "aaa", "aa.a", false );
        checkResult( "Test19", "aaa", "a.a", true );
        checkResult( "Test20", "aaa", ".a", false );
        checkResult( "Test21", "aaa", "a*a", true );
        checkResult( "Test22", "aaa", "ab*a", false );
        checkResult( "Test23", "aaa", "ab*ac*a", true );
        checkResult( "Test24", "aaa", "ab*a*c*a", true );
        checkResult( "Test25", "aaa", ".*", true );
        checkResult( "Test26", "aab", "c*a*b", true );
        checkResult( "Test27", "aaca", "ab*a*c*a", true );
        checkResult( "Test28", "aaba", "ab*a*c*a", false );
        checkResult( "Test29", "bbbba", ".*a*a", true );
        checkResult( "Test30", "bcbbabab", ".*a*a", false );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}