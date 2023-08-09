// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 排序数组中的搜索问题，首先想到 二分法 解决.
    // 二分法分别找到左右边界, 次数=right-left+1.
    // 先找右边界, 再找左边界.
    int search( vector<int>& nums, int target ) {
        if ( nums.empty() ) return 0;

        int right = findBoundary( nums, target );         // 寻找右边界
        int left = findBoundary( nums, target - 1 ) + 1;  // 寻找左边界
        return right - left + 1;
    }

   private:
    // 用于寻找边界的辅助函数, 二分查找边界
    int findBoundary( vector<int>& nums, int target ) {
        int i = 0, j = nums.size() - 1;
        while ( i <= j ) {
            int m = ( i + j ) / 2;
            if ( nums[ m ] <= target )  // 注意这里是<=
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums, int target,
                      int expected ) {
        cout << testName;
        int result = solution.search( nums, target );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 查找的数字出现在数组的中间
    void Test1() {
        vector<int> nums{ 1, 2, 3, 3, 3, 3, 4, 5 };
        checkResult( "Test1", nums, 3, 4 );
    }

    // 查找的数组出现在数组的开头
    void Test2() {
        vector<int> nums{ 3, 3, 3, 3, 4, 5 };
        checkResult( "Test2", nums, 3, 4 );
    }

    // 查找的数组出现在数组的结尾
    void Test3() {
        vector<int> nums{ 1, 2, 3, 3, 3, 3 };
        checkResult( "Test3", nums, 3, 4 );
    }

    // 查找的数字不存在
    void Test4() {
        vector<int> nums{ 1, 3, 3, 3, 3, 4, 5 };
        checkResult( "Test4", nums, 2, 0 );
    }

    // 查找的数字比第一个数字还小，不存在
    void Test5() {
        vector<int> nums{ 1, 3, 3, 3, 3, 4, 5 };
        checkResult( "Test5", nums, 0, 0 );
    }

    // 查找的数字比最后一个数字还大，不存在
    void Test6() {
        vector<int> nums{ 1, 3, 3, 3, 3, 4, 5 };
        checkResult( "Test6", nums, 6, 0 );
    }

    // 数组中的数字从头到尾都是查找的数字
    void Test7() {
        vector<int> nums{ 3, 3, 3, 3 };
        checkResult( "Test7", nums, 3, 4 );
    }

    // 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
    void Test8() {
        vector<int> nums{ 3, 3, 3, 3 };
        checkResult( "Test8", nums, 4, 0 );
    }

    // 数组中只有一个数字，是查找的数字
    void Test9() {
        vector<int> nums{ 3 };
        checkResult( "Test9", nums, 3, 1 );
    }

    // 数组中只有一个数字，不是查找的数字
    void Test10() {
        vector<int> nums{ 3 };
        checkResult( "Test10", nums, 4, 0 );
    }

    // 鲁棒性测试，空数组
    void Test11() {
        vector<int> nums;
        checkResult( "Test11", nums, 0, 0 );
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
        Test9();
        Test10();
        Test11();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
