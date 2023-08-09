// 面试题50：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。如果没有，返回一个单空格。 s 只包含小写字母。

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    char firstUniqChar( string s, bool use_common_hash = true ) {
        if ( s.empty() ) return ' ';

        if ( use_common_hash )
            return withCommonHash( s );
        else
            return withLinkedHash( s );
    }

   private:
    // 普通哈希表,两轮遍历
    char withCommonHash( string s ) {
        unordered_map<char, bool> dic;  // 建立哈希表, 查询字符是否只有一个
        // 当dic包含c,则dic[c]=false; 当dic不包含c,则dic[c]=true
        for ( char c : s ) dic[ c ] = ( dic.find( c ) == dic.end() );
        for ( char c : s ) {
            if ( dic[ c ] ) return c;
        }
        return ' ';  // 其余情况返回空格
    }

    // 有序哈希表, 键值对按插入顺序排序.
    // 优点是由于哈希表是去重的, 键值对数量 <= 字符串长度.
    // 当字符串很长(重复字符串很多)时, 第二轮遍历的效率更高.
    // C++未提供链式哈希表, 因此需要借助vector存储dic的键.
    char withLinkedHash( string s ) {
        vector<char> keys;
        unordered_map<char, bool> dic;
        for ( char c : s ) {
            if ( dic.find( c ) == dic.end() ) keys.push_back( c );
            dic[ c ] = ( dic.find( c ) == dic.end() );
        }
        for ( char c : keys ) {
            if ( dic[ c ] ) return c;
        }
        return ' ';
    }
};

class Test {
   public:
    void checkResult( const string testName, string s, char expected ) {
        cout << testName;
        char result = solution.firstUniqChar( s );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", "google", 'l' );
        checkResult( "Test2", "aabccdbd", ' ' );
        checkResult( "Test3", "abcdefg", 'a' );
        checkResult( "Test4", "", ' ' );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}