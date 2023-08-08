// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。
// 输出结果可能非常大，所以你需要返回一个字符串而不是整数
// 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string minNumber( vector<int>& nums, bool use_myQsort = false ) {
        // 为避免大数越界问题，将整数转换为字符串
        vector<string> strs;
        for ( int num : nums ) strs.push_back( std::to_string( num ) );

        // 对字符串列表排序
        // 排序规则为 x+y < y+x，则x应该排在y前
        if ( use_myQsort )
            quickSort( strs, 0, strs.size() - 1 );  // 自己实现的快速排序
        else
            // 使用库函数
            std::sort( strs.begin(), strs.end(),
                       []( string& x, string& y ) { return x + y < y + x; } );

        // 拼接得到最小数字
        string result;
        for ( string s : strs ) result += s;
        return result;
    }

   private:
    // 对字符串列表排序
    // 排序规则为 x+y < y+x，则x应该排在y前
    void quickSort( vector<string>& strs, int l, int r ) {
        // partition
        if ( l >= r ) return;
        int i = l, j = r;
        while ( i < j ) {
            while ( i < j && strs[ j ] + strs[ l ] >= strs[ l ] + strs[ j ] )
                j--;
            while ( i < j && strs[ i ] + strs[ l ] <= strs[ l ] + strs[ i ] )
                i++;
            std::swap( strs[ i ], strs[ j ] );
        }
        std::swap( strs[ i ], strs[ l ] );
        // recur
        quickSort( strs, l, i - 1 );
        quickSort( strs, i + 1, r );
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums,
                      string expected ) {
        cout << testName;
        string result = solution.minNumber( nums );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        vector<int> nums{ 3, 5, 1, 4, 2 };
        string expected = "12345";
        checkResult( "Test1", nums, expected );
    }

    void Test2() {
        vector<int> nums{ 3, 32, 321 };
        string expected = "321323";
        checkResult( "Test2", nums, expected );
    }

    void Test3() {
        vector<int> nums{ 3, 323, 32123 };
        string expected = "321233233";
        checkResult( "Test3", nums, expected );
    }

    void Test4() {
        vector<int> nums{ 1, 11, 111 };
        string expected = "111111";
        checkResult( "Test4", nums, expected );
    }

    void Test5() {
        vector<int> nums{ 321 };
        string expected = "321";
        checkResult( "Test5", nums, expected );
    }

    void Test6() {
        vector<int> nums;
        string expected = "";
        checkResult( "Test6", nums, expected );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
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
