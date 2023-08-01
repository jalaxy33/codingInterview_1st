// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。你需要用一个浮点数数组返回答案，
// 其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 动态规划
    vector<double> dicesProbability( int n ) {
        if ( n < 1 ) return vector<double>();

        // 由于dp[i]仅由dp[i-1]推导得到，用两个一维数组替代二维dp数组
        // 结果由这两个数组交替前进得到
        vector<double> dp( FACES, 1.0 / FACES );  // 一个骰子共6面
        for ( int i = 2; i <= n; i++ ) {          // i 表示第i个骰子
            // n枚骰子的点数范围是[n, FACES*n], 数量为 FACES*n - n + 1种
            vector<double> tmp( FACES * i - i + 1, 0 );
            for ( int j = 0; j < dp.size(); j++ ) {  // 第j面
                for ( int k = 0; k < FACES; k++ )
                    // 转移函数，累计骰子各面对最终结果的点数
                    tmp[ j + k ] += dp[ j ] / FACES;
            }
            dp = tmp;
        }
        return dp;
    }

   private:
    const int FACES = 6;  // 骰子面数
};

class Test {
   public:
    void checkResult( const string testName, int n ) {
        if ( !testName.empty() ) cout << testName << ", ";
        cout << "n=" << n << ": [ ";
        vector<double> results = solution.dicesProbability( n );
        for ( double r : results ) cout << r << ", ";
        cout << "]\n\n";
    }

    void runTest() {
        checkResult( "Test1", 1 );
        checkResult( "Test2", 2 );
        checkResult( "Test3", 3 );
        checkResult( "Test4", 4 );
        checkResult( "Test5", 11 );
        checkResult( "Test6", 0 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}