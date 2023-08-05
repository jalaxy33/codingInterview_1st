// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> permutation( string s, bool use_dfs = true ) {
        result.clear();  // 清空旧数据
        if ( use_dfs )
            dfs( s, 0 );
        else
            withStd( s );
        return result;
    }

   private:
    vector<string> result;

    // 使用递归
    void dfs( string s, int index ) {
        // 终止条件：index来到最后一位，此时只有一种可能
        if ( index == s.size() - 1 ) {
            result.push_back( s );
            return;
        }

        set<int> st;  // 用集合来避免重复
        // 不断交换index与后续位置的字符，寻找不同的组合
        for ( int i = index; i < s.size(); i++ ) {
            if ( st.find( s[ i ] ) != st.end() ) continue;  // 该字符重复，跳过
            st.insert( s[ i ] );
            std::swap( s[ i ], s[ index ] );  // 交换两个位置的字符
            dfs( s, index + 1 );              // 开启下一位置的寻找
            std::swap( s[ i ], s[ index ] );  // 恢复原来的位置
        }
    }

    // 使用std库函数
    void withStd( string s ) {
        std::sort( s.begin(), s.end() );  // 先进行排序
        do {
            result.push_back( s );
        } while (
            std::next_permutation( s.begin(), s.end() ) );  // 探索下一组合
    }
};

class Test {
   public:
    void checkResult( const string testName, string s ) {
        cout << "==== " << testName << " ====\n";
        cout << s << endl;

        vector<string> result = solution.permutation( s );
        cout << "[ ";
        for ( string s_ : result ) cout << s_ << ", ";
        cout << "]\n\n";
    }

    void runTest() {
        checkResult( "Test1", "" );
        checkResult( "Test2", "a" );
        checkResult( "Test3", "ab" );
        checkResult( "Test4", "abc" );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
