// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右非递减的顺序排序，每一列都按
// 照从上到下非递减的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Vec = vector<int>;
using Mat = vector<Vec>;

class Solution {
   public:
    // 矩阵的右上角或左下角可被选为标志。以右上角数字为例，
    // 如果该数字==要查找的数字，则查找结束；
    // 如果>，则剔除这个数字所在的列；
    // 如果<，则剔除这个数字所在的行。
    bool findNumberIn2DArray( Mat& matrix, int target ) {
        if ( matrix.empty() || matrix[ 0 ].empty() ) return false;
        int rows = matrix.size(), cols = matrix[ 0 ].size();
        int i = 0, j = cols - 1;  // 选矩阵右上角为标志
        while ( i < rows && j >= 0 ) {
            if ( matrix[ i ][ j ] > target )
                j--;
            else if ( matrix[ i ][ j ] < target )
                i++;
            else
                return true;
        }
        return false;
    }
};

class Test {
   public:
    void checkResult( const string testName, Mat& matrix, int target,
                      bool expected ) {
        cout << testName;
        bool result = solution.findNumberIn2DArray( matrix, target );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    //  1   2   8   9
    //  2   4   9   12
    //  4   7   10  13
    //  6   8   11  15
    // 要查找的数在数组中
    void Test1() {
        Mat matrix{
            Vec{ 1, 2, 8, 9 },
            Vec{ 2, 4, 9, 12 },
            Vec{ 4, 7, 10, 13 },
            Vec{ 6, 8, 11, 15 },
        };
        checkResult( "Test1", matrix, 7, true );
    }

    //  1   2   8   9
    //  2   4   9   12
    //  4   7   10  13
    //  6   8   11  15
    // 要查找的数不在数组中
    void Test2() {
        Mat matrix{
            Vec{ 1, 2, 8, 9 },
            Vec{ 2, 4, 9, 12 },
            Vec{ 4, 7, 10, 13 },
            Vec{ 6, 8, 11, 15 },
        };
        checkResult( "Test2", matrix, 5, false );
    }

    //  1   2   8   9
    //  2   4   9   12
    //  4   7   10  13
    //  6   8   11  15
    // 要查找的数是数组中最小的数字
    void Test3() {
        Mat matrix{
            Vec{ 1, 2, 8, 9 },
            Vec{ 2, 4, 9, 12 },
            Vec{ 4, 7, 10, 13 },
            Vec{ 6, 8, 11, 15 },
        };
        checkResult( "Test3", matrix, 1, true );
    }

    //  1   2   8   9
    //  2   4   9   12
    //  4   7   10  13
    //  6   8   11  15
    // 要查找的数是数组中最大的数字
    void Test4() {
        Mat matrix{
            Vec{ 1, 2, 8, 9 },
            Vec{ 2, 4, 9, 12 },
            Vec{ 4, 7, 10, 13 },
            Vec{ 6, 8, 11, 15 },
        };
        checkResult( "Test4", matrix, 15, true );
    }

    //  1   2   8   9
    //  2   4   9   12
    //  4   7   10  13
    //  6   8   11  15
    // 要查找的数比数组中最小的数字还小
    void Test5() {
        Mat matrix{
            Vec{ 1, 2, 8, 9 },
            Vec{ 2, 4, 9, 12 },
            Vec{ 4, 7, 10, 13 },
            Vec{ 6, 8, 11, 15 },
        };
        checkResult( "Test5", matrix, 0, false );
    }

    //  1   2   8   9
    //  2   4   9   12
    //  4   7   10  13
    //  6   8   11  15
    // 要查找的数比数组中最大的数字还大
    void Test6() {
        Mat matrix{
            Vec{ 1, 2, 8, 9 },
            Vec{ 2, 4, 9, 12 },
            Vec{ 4, 7, 10, 13 },
            Vec{ 6, 8, 11, 15 },
        };
        checkResult( "Test6", matrix, 16, false );
    }

    // 鲁棒性测试，输入空指针
    void Test7() {
        Mat matrix;
        checkResult( "Test7", matrix, 16, false );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}