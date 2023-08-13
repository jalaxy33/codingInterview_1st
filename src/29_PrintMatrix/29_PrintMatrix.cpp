// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Vec1d = vector<int>;
using Vec2d = vector<Vec1d>;

class Solution {
   public:
    Vec1d spiralOrder( Vec2d& matrix ) {
        if ( matrix.empty() ) return {};

        int l = 0, r = matrix[ 0 ].size() - 1, t = 0, b = matrix.size() - 1;
        Vec1d result;
        while ( true ) {
            // left -> right
            for ( int i = l; i <= r; i++ ) result.push_back( matrix[ t ][ i ] );
            if ( ++t > b ) break;
            // top -> bottom
            for ( int i = t; i <= b; i++ ) result.push_back( matrix[ i ][ r ] );
            if ( --r < l ) break;
            // right -> left
            for ( int i = r; i >= l; i-- ) result.push_back( matrix[ b ][ i ] );
            if ( --b < t ) break;
            // bottom -> top
            for ( int i = b; i >= t; i-- ) result.push_back( matrix[ i ][ l ] );
            if ( ++l > r ) break;
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, int rows, int cols ) {
        cout << "==== " << testName << " ====\n";
        Vec2d matrix = createMatrix( rows, cols );
        Vec1d resultVec = solution.spiralOrder( matrix );
        cout << "[ ";
        for ( int num : resultVec ) cout << num << ", ";
        cout << "]\n\n";
    }

    void runTest() {
        /*
        1
        */
        checkResult( "Test1", 1, 1 );

        /*
        1    2
        3    4
        */
        checkResult( "Test2", 2, 2 );

        /*
        1    2    3    4
        5    6    7    8
        9    10   11   12
        13   14   15   16
        */
        checkResult( "Test3", 4, 4 );

        /*
        1    2    3    4    5
        6    7    8    9    10
        11   12   13   14   15
        16   17   18   19   20
        21   22   23   24   25
        */
        checkResult( "Test4", 5, 5 );

        /*
        1
        2
        3
        4
        5
        */
        checkResult( "Test5", 1, 5 );

        /*
        1    2
        3    4
        5    6
        7    8
        9    10
        */
        checkResult( "Test6", 2, 5 );

        /*
        1    2    3
        4    5    6
        7    8    9
        10   11   12
        13   14   15
        */
        checkResult( "Test7", 3, 5 );

        /*
        1    2    3    4
        5    6    7    8
        9    10   11   12
        13   14   15   16
        17   18   19   20
        */
        checkResult( "Test8", 4, 5 );

        /*
        1    2    3    4    5
        */
        checkResult( "Test9", 5, 1 );

        /*
        1    2    3    4    5
        6    7    8    9    10
        */
        checkResult( "Test10", 5, 2 );

        /*
        1    2    3    4    5
        6    7    8    9    10
        11   12   13   14    15
        */
        checkResult( "Test11", 5, 3 );

        /*
        1    2    3    4    5
        6    7    8    9    10
        11   12   13   14   15
        16   17   18   19   20
        */
        checkResult( "Test12", 5, 4 );
    }

   private:
    Solution solution;

    Vec2d createMatrix( int rows, int cols ) {
        Vec2d matrix;
        for ( int i = 0; i < rows; i++ ) {
            Vec1d arr;
            for ( int j = 0; j < cols; j++ ) arr.push_back( i * cols + j + 1 );
            matrix.push_back( arr );
        }
        return matrix;
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
