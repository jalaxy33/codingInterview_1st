// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool g_InvalidInput = false;  // 与测试函数相关的全局变量

class Solution {
   public:
    int maxSubArray( const vector<int>& nums ) {
        if ( nums.empty() ) {
            g_InvalidInput = true;
            return 0;
        }
        g_InvalidInput = false;
        int result = nums[ 0 ], pre = 0;
        for ( int x : nums ) {
            pre = std::max( pre + x, x );
            result = std::max( result, pre );
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, const vector<int> nums,
                      int expected, bool expectedFlag ) {
        if ( !testName.empty() ) cout << testName;

        int result = solution.maxSubArray( nums );
        if ( result == expected && expectedFlag == g_InvalidInput )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 1, -2, 3, 10, -4, 7, 2, -5
    void Test1() {
        vector<int> nums{ 1, -2, 3, 10, -4, 7, 2, -5 };
        checkResult( "Test1", nums, 18, false );
    }

    // 所有数字都是负数
    // -2, -8, -1, -5, -9
    void Test2() {
        vector<int> nums{ -2, -8, -1, -5, -9 };
        checkResult( "Test2", nums, -1, false );
    }

    // 所有数字都是正数
    // 2, 8, 1, 5, 9
    void Test3() {
        vector<int> nums{ 2, 8, 1, 5, 9 };
        checkResult( "Test3", nums, 25, false );
    }

    // 无效输入
    void Test4() {
        vector<int> nums;
        checkResult( "Test4", nums, 0, true );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
