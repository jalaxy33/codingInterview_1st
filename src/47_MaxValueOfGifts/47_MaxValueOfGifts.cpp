// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Vec = vector<int>;
using Mat = vector<Vec>;

class Solution {
   public:
    // 动态规划
    int maxValue( Mat& grid ) {
        if ( grid.empty() ) return 0;

        // dp[i,j]为从(0,0)开始到(i,j)的最大累计价值
        int m = grid.size(), n = grid[ 0 ].size();

        // 为减少冗余判断，首先初始化首行首列
        for ( int j = 1; j < n; j++ ) grid[ 0 ][ j ] += grid[ 0 ][ j - 1 ];
        for ( int i = 1; i < m; i++ ) grid[ i ][ 0 ] += grid[ i - 1 ][ 0 ];

        // dp[i,j] = max(dp[左边], dp[上边]) + grid[i,j]
        for ( int i = 1; i < m; i++ ) {
            for ( int j = 1; j < n; j++ ) {
                grid[ i ][ j ] +=
                    std::max( grid[ i ][ j - 1 ], grid[ i - 1 ][ j ] );
            }
        }
        return grid[ m - 1 ][ n - 1 ];
    }
};

class Test {
   public:
    void checkResult( const string testName, Mat& grid, int expected ) {
        if ( !testName.empty() ) cout << testName;

        if ( solution.maxValue( grid ) == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        Mat grid{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int expected = 29;
        checkResult( "Test1", grid, expected );
    }

    void Test2() {
        Mat grid{ { 1, 10, 3, 8 },
                  { 12, 2, 9, 6 },
                  { 5, 7, 4, 11 },
                  { 3, 7, 16, 5 } };
        int expected = 53;
        checkResult( "Test2", grid, expected );
    }

    void Test3() {
        Mat grid{ { 1, 10, 3, 8 } };
        int expected = 22;
        checkResult( "Test3", grid, expected );
    }

    void Test4() {
        Mat grid{ { 1 }, { 12 }, { 5 }, { 3 } };
        int expected = 21;
        checkResult( "Test4", grid, expected );
    }

    void Test5() {
        Mat grid{ { 3 } };
        int expected = 3;
        checkResult( "Test5", grid, expected );
    }

    void Test6() {
        Mat grid;
        int expected = 0;
        checkResult( "Test6", grid, expected );
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
