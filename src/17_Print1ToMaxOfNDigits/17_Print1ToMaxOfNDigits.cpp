// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。
// 用返回一个整数列表来代替打印

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 由于要求返回整数列表，因此可以不考虑大数越界问题，
    // 可以先求最大值然后逐个输出。
    // 常规做法是先表示为字符串，然后考虑各位，最后转换为整数
    vector<int> printNumbers( int n, bool with_recur = false ) {
        intResult.clear();
        if ( n <= 0 ) return intResult;

        if ( with_recur )
            return printWithRecur( n );
        else
            return printWithIter( n );
    }

   private:
    vector<int> intResult;     // 保存所有最终整数结果
    vector<string> strResult;  // 将中间结果保存为字符串

    // 递归法，常规做法
    // 先表示为字符串，考虑各位，最后转换为整数
    vector<int> printWithRecur( int n ) {
        strResult.clear();

        recur( n, 0, "" );
        // 最后将所有字符串数字转为整数，并输出
        for ( auto iter = strResult.begin(); iter != strResult.end(); iter++ ) {
            intResult.push_back( std::stoi( *iter ) );
        }
        return intResult;
    }

    // 递归处理，count表示下一位要处理第几位
    void recur( int n, int count, string number ) {
        // 终止条件：处理到最后一位
        if ( count == n ) {
            // 不保存高位是零的数
            if ( number[ 0 ] != '0' ) strResult.push_back( number );
            return;
        }

        for ( int index = 0; index <= 9; index++ ) {
            // 一位数单独处理，从而避免高位有零的情况
            if ( !number.empty() && number[ 0 ] == '0' )  // 处理非零一位数
                recur( n, count + 1, std::to_string( index ) );
            else  // 处理其他情况：0以及多位数。由于高位肯定非零，直接拼接即可
                recur( n, count + 1, number + std::to_string( index ) );
        }
    }

    // 迭代法,先求最大值
    vector<int> printWithIter( int n ) {
        int end = std::pow( 10, n );
        for ( int i = 1; i < end; i++ ) intResult.push_back( i );
        return intResult;
    }
};

class Test {
   public:
    void checkResult( const string testName, int n ) {
        cout << "==== " << testName << " ====\n";
        cout << "n=" << n << endl;
        vector<int> result = solution.printNumbers( n );
        cout << "[ ";
        for ( int r : result ) cout << r << ", ";
        cout << "]\n\n";
    }

    void runTest() {
        checkResult( "Test1", 1 );
        checkResult( "Test2", 2 );
        checkResult( "Test3", 3 );
        checkResult( "Test4", 0 );
        checkResult( "Test5", -1 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}