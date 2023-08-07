
// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int reversePairs( vector<int>& nums ) {
        if ( nums.empty() ) return 0;
        vector<int> tmp( nums.size() );
        return mergeSort( 0, nums.size() - 1, nums, tmp );
    }

   private:
    // 通过归并排序成正序，统计其中的逆序对数。
    // l,r是左右端点序号，tmp暂存归并结果
    int mergeSort( int l, int r, vector<int>& nums, vector<int>& tmp ) {
        // 终止条件：l>=r
        if ( l >= r ) return 0;
        // 划分&递归
        int m = ( l + r ) >> 1;
        int result =
            mergeSort( l, m, nums, tmp ) + mergeSort( m + 1, r, nums, tmp );
        // 合并&统计逆序对
        // 1) 将nums[l..r]暂存到tmp对应位置
        for ( int k = l; k <= r; k++ ) tmp[ k ] = nums[ k ];
        // 2) i,j指针表示指向当前左右数组的位置
        int i = l, j = m + 1;
        // 3）循环归并，依次取出左右数组中的较小者，并统计逆序对数
        for ( int k = l; k <= r; k++ ) {
            // 当i==m+1时，说明此时左边已经归并完毕，此时只看右边即可
            if ( i == m + 1 ) nums[ k ] = tmp[ j++ ];
            // 当j==r+1时，说明右边已经归并完毕，此时只看左边即可
            // 另外，当左边<右边时，此时是正序对。这两种情况都是添加左边
            else if ( j == r + 1 || tmp[ i ] <= tmp[ j ] )
                nums[ k ] = tmp[ i++ ];
            // 逆序的情况，即右边<左边时。
            // 由于归并后的左右数组均是正序的，因此新增逆序对数为 m-i+1.
            // 即[i,m]间的元素数
            else {
                nums[ k ] = tmp[ j++ ];
                result += m - i + 1;
            }
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums, int expected ) {
        cout << testName;
        int result = solution.reversePairs( nums );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        vector<int> nums{ 1, 2, 3, 4, 7, 6, 5 };
        int expected = 3;
        checkResult( "Test1", nums, expected );
    }

    void Test2() {
        vector<int> nums{ 6, 5, 4, 3, 2, 1 };
        int expected = 15;
        checkResult( "Test2", nums, expected );
    }

    void Test3() {
        vector<int> nums{ 1, 2, 3, 4, 5, 6 };
        int expected = 0;
        checkResult( "Test3", nums, expected );
    }

    void Test4() {
        vector<int> nums{ 1 };
        int expected = 0;
        checkResult( "Test4", nums, expected );
    }

    void Test5() {
        vector<int> nums{ 1, 2 };
        int expected = 0;
        checkResult( "Test5", nums, expected );
    }

    void Test6() {
        vector<int> nums{ 2, 1 };
        int expected = 1;
        checkResult( "Test6", nums, expected );
    }

    void Test7() {
        vector<int> nums{ 1, 2, 1, 2, 1 };
        int expected = 3;
        checkResult( "Test7", nums, expected );
    }

    void Test8() {
        vector<int> nums;
        int expected = 0;
        checkResult( "Test8", nums, expected );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
        Test8();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}