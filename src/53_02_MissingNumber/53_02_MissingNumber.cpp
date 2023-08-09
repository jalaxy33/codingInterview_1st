// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 有序列表的搜索问题, 首先考虑二分查找.
    // 将数组分为"nums[i]==i"和"nums[i]!=i"两部分,
    // 缺失的数字等于右边数组的首位元素的索引
    int missingNumber( vector<int>& nums ) {
        if ( nums.empty() ) return -1;
        
        int i = 0, j = nums.size() - 1;
        while ( i <= j ) {
            int m = ( i + j ) / 2;
            if ( nums[ m ] == m )
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums, int expected ) {
        cout << testName;
        int result = solution.missingNumber( nums );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 缺失的是第一个数字0
    void Test1() {
        vector<int> nums{ 1, 2, 3, 4, 5 };
        int expected = 0;
        checkResult( "Test1", nums, expected );
    }

    // 缺失的是最后一个数字
    void Test2() {
        vector<int> nums{ 0, 1, 2, 3, 4 };
        int expected = 5;
        checkResult( "Test2", nums, expected );
    }

    // 缺失的是中间某个数字0
    void Test3() {
        vector<int> nums{ 0, 1, 2, 4, 5 };
        int expected = 3;
        checkResult( "Test3", nums, expected );
    }

    // 数组中只有一个数字，缺失的是第一个数字0
    void Test4() {
        vector<int> nums{ 1 };
        int expected = 0;
        checkResult( "Test4", nums, expected );
    }

    // 数组中只有一个数字，缺失的是最后一个数字1
    void Test5() {
        vector<int> nums{ 0 };
        int expected = 1;
        checkResult( "Test5", nums, expected );
    }

    // 空数组
    void Test6() {
        vector<int> nums;
        int expected = -1;
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