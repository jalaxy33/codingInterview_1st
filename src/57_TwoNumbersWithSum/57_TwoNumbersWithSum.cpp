// 面试题57：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    // nums是有序列表，可以用双指针法，空间复杂度为O(1)。
    // 无序列表可用哈希表法遍历数组找到组合，时空复杂度均为O(n)。
    vector<int> twoSum( vector<int>& nums, int target, bool use_twop = true ) {
        if ( nums.empty() ) return {};

        if ( use_twop )
            return withTwoPointers( nums, target );
        else
            return withHash( nums, target );
    }

   private:
    // 双指针法。指针i和j分别位于数组左右，
    // 根据比较nums[i]+nums[j]与target的大小，调整i和j的位置
    vector<int> withTwoPointers( vector<int>& nums, int target ) {
        int i = 0, j = nums.size() - 1;
        while ( i < j ) {
            int s = nums[ i ] + nums[ j ];
            if ( s < target )
                i++;
            else if ( s > target )
                j--;
            else
                return { nums[ i ], nums[ j ] };
        }
        return {};
    }

    // 哈希表法
    vector<int> withHash( vector<int>& nums, int target ) {
        unordered_map<int, bool> dic;
        // 第一次遍历存表
        for ( int num : nums ) dic[ num ] = true;
        // 第二次遍历查表
        for ( int num : nums ) {
            if ( dic[ target - num ] ) return { num, target - num };
        }
        return {};
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums, int target,
                      bool valid ) {
        cout << testName;
        vector<int> result = solution.twoSum( nums, target );

        if ( result.size() == 2 && valid ) {
            int sum = getSum( result );
            if ( sum == target )
                cout << " passed.\n";
            else
                cout << " failed.\n";
        } else if ( result.empty() && !valid )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 存在和为s的两个数字，这两个数字位于数组的中间
    void Test1() {
        vector<int> nums{ 1, 2, 4, 7, 11, 15 };
        checkResult( "Test1", nums, 15, true );
    }

    // 存在和为s的两个数字，这两个数字位于数组的两段
    void Test2() {
        vector<int> nums{ 1, 2, 4, 7, 11, 16 };
        checkResult( "Test2", nums, 17, true );
    }

    // 不存在和为s的两个数字
    void Test3() {
        vector<int> nums{ 1, 2, 4, 7, 11, 16 };
        checkResult( "Test3", nums, 10, false );
    }

    // 鲁棒性测试
    void Test3() {
        vector<int> nums;
        checkResult( "Test4", nums, 0, false );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test3();
    }

   private:
    Solution solution;

    int getSum( vector<int> nums ) {
        int sum = 0;
        for ( int num : nums ) sum += num;
        return sum;
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
