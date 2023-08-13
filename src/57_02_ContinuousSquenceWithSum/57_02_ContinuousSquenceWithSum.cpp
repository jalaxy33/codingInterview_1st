// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

using Vec1d = vector<int>;
using Vec2d = vector<Vec1d>;

class Solution {
   public:
    Vec2d findContinuousSequence( int target, int which_solution = 1 ) {
        if ( target < 3 ) return {};  // 至少两个元素

        if ( which_solution == 1 )
            return withSumFormula( target );
        else if ( which_solution == 2 )
            return withSlidingWindow( target );
        else
            throw invalid_argument( "Invalid solution selection!" );
    }

   private:
    // 利用求和公式
    Vec2d withSumFormula( int target ) {
        // 设连续序列的左右边界为i和j，求和公式为
        // target = (i+j) * (j-i+1) / 2
        // 解方程得：
        // j = 1/2 * ( -1 + sqrt( 1 + 4( 2target + i^2 - i ) ) )

        long i = 1;  // i^2 可能很大
        double j = 2.0;
        Vec2d results;
        Vec1d ans;
        while ( i < j ) {
            j = ( -1 + std::sqrt( 1 + 4 * ( 2 * target + i * i - i ) ) ) / 2;
            if ( j == int( j ) ) {
                ans.clear();
                for ( int k = i; k <= int( j ); k++ ) ans.push_back( k );
                results.push_back( ans );
            }
            i++;
        }
        return results;
    }

    // 滑动窗口（双指针）
    Vec2d withSlidingWindow( int target ) {
        // i和j确定窗口边界，s记录窗内元素和
        // 通过比较s和target的大小来调整i和j的位置

        int i = 1, j = 2, s = 3;
        Vec2d results;
        Vec1d ans;
        while ( i < j ) {
            if ( s == target ) {
                ans.clear();
                for ( int k = i; k <= j; k++ ) ans.push_back( k );
                results.push_back( ans );
            }
            // 找到一组了也可以继续往后找
            if ( s >= target ) {
                s -= i;
                i++;
            } else {
                j++;
                s += j;
            }
        }
        return results;
    }
};

class Test {
   public:
    void checkResult( const string testName, int target ) {
        cout << "==== " << testName << " ====\n";
        Vec2d result = solution.findContinuousSequence( target );
        cout << "[ ";
        for ( Vec1d arr : result ) {
            cout << "[ ";
            for ( int num : arr ) cout << num << ", ";
            cout << " ], ";
        }
        cout << " ]\n\n";
    }

    void runTest() {
        checkResult( "Test1", 1 );
        checkResult( "Test2", 3 );
        checkResult( "Test3", 4 );
        checkResult( "Test4", 9 );
        checkResult( "Test5", 15 );
        checkResult( "Test6", 100 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
