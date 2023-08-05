// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
// 坐标值在1到100之间，0<=k<=20.

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int movingCount( int m, int n, int k, bool use_dfs = false ) {

        Mat visited( m, Vec( n, false ) );  // 记录坐标是否被访问过
        if ( use_dfs )
            return dfs( 0, 0, m, n, k, visited );
        else
            return bfs( m, n, k, visited );
    }

   private:
    using Vec = vector<bool>;
    using Mat = vector<Vec>;

    // 深度优先遍历。
    int dfs( int i, int j, int m, int n, int k, Mat& visited ) {
        // 终止条件：1) 越界，2) 数位和超出限制，3) 当前坐标已被访问
        if ( i >= m || j >= n || visited[ i ][ j ] || digitSum( i, j ) > k )
            return 0;

        visited[ i ][ j ] = true;  // 标记当前位置为已访问
        // 向下向右访问，由于会回溯，因此最终能访问所有坐标
        int result = 1 + dfs( i + 1, j, m, n, k, visited ) +
                     dfs( i, j + 1, m, n, k, visited );
        return result;
    }

    // 广度优先遍历,利用队列实现
    int bfs( int m, int n, int k, Mat& visited ) {
        using VecQ = vector<int>;

        int result = 0;
        queue<VecQ> q;
        int i = 0, j = 0;
        q.push( { i, j } );  // 将起点入队
        while ( !q.empty() ) {
            // 将队首单元格出队
            VecQ x = q.front();
            i = x[ 0 ], j = x[ 1 ];
            q.pop();
            // 判断是否跳过该单元格
            if ( i >= m || j >= n || visited[ i ][ j ] || digitSum( i, j ) > k )
                continue;
            // 标记当前单元格，更新步长
            visited[ i ][ j ] = true;
            result++;
            // 将下方和右方单元格入队，以继续遍历
            q.push( { i + 1, j } );
            q.push( { i, j + 1 } );
        }
        return result;
    }

    // 计算数位和
    int digitSum( int i, int j ) {
        // 由于i,j只有两位数，可以用下面的式子算数位和
        return i % 10 + i / 10 + j % 10 + j / 10;
    }
};

class Test {
   public:
    void checkResult( string testName, int m, int n, int k, int expected ) {
        if ( !testName.empty() ) cout << testName;

        int result = solution.movingCount( m, n, k );
        // cout << " result=" << result << ", expected=" << expected;
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        // 方格多行多列
        checkResult( "Test1", 10, 10, 5, 21 );
        // 方格多行多列
        checkResult( "Test2", 20, 20, 15, 359 );
        // 方格只有一行，机器人只能到达部分方格
        checkResult( "Test3", 1, 100, 10, 29 );
        // 方格只有一行，机器人能到达所有方格
        checkResult( "Test4", 1, 10, 10, 10 );
        // 方格只有一列，机器人只能到达部分方格
        checkResult( "Test5", 100, 1, 15, 79 );
        // 方格只有一列，机器人能到达所有方格
        checkResult( "Test6", 10, 1, 15, 10 );
        // 方格只有一行一列
        checkResult( "Test7", 1, 1, 15, 1 );
        // 方格只有一行一列
        checkResult( "Test8", 1, 1, 0, 1 );
        // 机器人不能进入任意一个方格
        checkResult( "Test9", 10, 10, -10, 0 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
