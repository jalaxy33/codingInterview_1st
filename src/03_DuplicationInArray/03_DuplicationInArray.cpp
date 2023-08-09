// 面试题3：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,
// 3, 1, 0, 2, 5, 3}， 那么对应的输出是重复的数字2或者3。

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
   public:
    int findRepeatNumber( vector<int>& nums, bool use_hash = false ) {
        if ( use_hash )
            return withHash( nums );
        else
            return withSwap( nums );
    }

   private:
    // 利用哈希表
    int withHash( vector<int>& nums ) {
        unordered_map<int, bool> dic;  // 用哈希表存储每个数是否存在
        for ( int num : nums ) {
            if ( dic[ num ] ) return num;  // 如果有重复数字，则提前返回
            dic[ num ] = true;
        }
        return -1;  // 如果无重复数字，则返回-1
    }

    // 原地交换。由于注意到数组长为n，而数字的取值范围都是[0,n-1]。
    // 说明数组元素的索引和值是一对多关系。
    // 通过遍历数组并通过交换操作，使元素与值一一对应。
    // 此时通过索引映射对应的值，起到与哈希表等价的作用
    int withSwap( vector<int>& nums ) {
        int i = 0;
        while ( i < nums.size() ) {
            // 此时数字已在索引位置，使索引后移，并跳过余下过程
            if ( nums[ i ] == i ) {
                i++;
                continue;
            }
            // 索引nums[i]和索引i的值相同，且两个索引不同，说明重复，返回
            if ( nums[ nums[ i ] ] == nums[ i ] ) return nums[ i ];
            // 其余情况交换索引nums[i]和i的值
            std::swap( nums[ i ], nums[ nums[ i ] ] );
        }
        return -1;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums,
                      vector<int>& expected ) {
        cout << testName;
        int result = solution.findRepeatNumber( nums );
        if ( contain( expected, result ) )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 重复的数字是数组中最小的数字
    void Test1() {
        vector<int> nums{ 2, 1, 3, 1, 4 };
        vector<int> expected{ 1 };
        checkResult( "Test1", nums, expected );
    }

    // 重复的数字是数组中最大的数字
    void Test2() {
        vector<int> nums{ 2, 4, 3, 1, 4 };
        vector<int> expected{ 4 };
        checkResult( "Test2", nums, expected );
    }

    // 数组中存在多个重复的数字
    void Test3() {
        vector<int> nums{ 2, 4, 2, 1, 4 };
        vector<int> expected{ 2, 4 };
        checkResult( "Test3", nums, expected );
    }

    // 没有重复的数字
    void Test4() {
        vector<int> nums{ 2, 1, 3, 0, 4 };
        vector<int> expected{ -1 };  // not in use in the test function
        checkResult( "Test4", nums, expected );
    }

    // 没有重复的数字
    void Test5() {
        vector<int> nums{ 2, 1, 3, 5, 4, 0 };
        vector<int> expected{ -1 };  // not in use in the test function
        checkResult( "Test5", nums, expected );
    }

    // 无效的输入
    void Test6() {
        vector<int> nums;
        vector<int> expected{ -1 };  // not in use in the test function
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

    bool contain( vector<int>& nums, int num ) {
        for ( int n : nums ) {
            if ( num == n ) return true;
        }
        return false;
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}