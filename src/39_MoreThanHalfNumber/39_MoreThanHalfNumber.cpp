// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 全局标记，应对可能的不合法输入
bool g_InvalidFlag = false;
int invalidReturn = 0;

class Solution {
   public:
    int majorityElement( vector<int>& nums, int which_solution = 3 ) {
        if ( nums.empty() ) {
            g_InvalidFlag = true;
            return invalidReturn;
        }

        g_InvalidFlag = false;
        if ( which_solution == 1 )
            return withHash( nums );
        else if ( which_solution == 2 )
            return withSort( nums );
        else if ( which_solution == 3 )
            return withVoting( nums );
        else
            throw invalid_argument( "Invalid solution selection!" );
    }

   private:
    // 哈希表统计法
    int withHash( vector<int>& nums ) {
        unordered_map<int, int> dic;  // 哈希表统计出现次数
        for ( int num : nums ) {
            if ( dic.find( num ) == dic.end() )
                dic[ num ] = 1;
            else
                dic[ num ]++;
        }
        int half = nums.size() >> 1;
        for ( auto kv : dic ) {
            int num = kv.first, cnt = kv.second;
            if ( cnt > half ) return num;
        }
        g_InvalidFlag = true;
        return invalidReturn;
    }

    // 数组排序法。将数组排序，众数一定是数组的中位数。
    int withSort( vector<int>& nums ) {
        std::sort( nums.begin(), nums.end() );
        int middle = nums.size() >> 1;
        int result = nums[ middle ], count = 0;
        // 确认是否为众数
        for ( int num : nums ) {
            if ( num == result ) count++;
        }
        if ( count <= middle ) {
            g_InvalidFlag = true;
            return invalidReturn;
        }
        return result;
    }

    // 摩尔投票法，本题的最优解。核心理念是票数正负抵消。
    // 先假设一个众数，开始遍历数组。遇到该数票数+1，不是该数票数-1.
    // 当票数为0时，则将假设的众数换成其他数。
    int withVoting( vector<int>& nums ) {
        int result = 0, votes = 0;
        for ( int num : nums ) {
            if ( votes == 0 ) result = num;
            votes += ( num == result ? 1 : -1 );
        }
        // 确认是否为众数
        int half = nums.size() >> 1, count = 0;
        for ( int num : nums ) {
            if ( num == result ) count++;
        }
        if ( count <= half ) {
            g_InvalidFlag = true;
            return invalidReturn;
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums, int expected,
                      bool invalid ) {
        cout << testName;
        int result = solution.majorityElement( nums );
        if ( result == expected && g_InvalidFlag == invalid )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 存在出现次数超过数组长度一半的数字
    void Test1() {
        vector<int> nums{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
        checkResult( "Test1", nums, 2, false );
    }

    // 不存在出现次数超过数组长度一半的数字
    void Test2() {
        vector<int> nums{ 1, 2, 3, 2, 4, 2, 5, 2, 3 };
        checkResult( "Test2", nums, invalidReturn, true );
    }

    // 出现次数超过数组长度一半的数字都出现在数组的前半部分
    void Test3() {
        vector<int> nums{ 2, 2, 2, 2, 2, 1, 3, 4, 5 };
        checkResult( "Test3", nums, 2, false );
    }

    // 出现次数超过数组长度一半的数字都出现在数组的后半部分
    void Test4() {
        vector<int> nums{ 1, 3, 4, 5, 2, 2, 2, 2, 2 };
        checkResult( "Test4", nums, 2, false );
    }

    // 数组只有一个元素
    void Test5() {
        vector<int> nums{ 1 };
        checkResult( "Test5", nums, 1, false );
    }

    // 输入空数组
    void Test6() {
        vector<int> nums;
        checkResult( "Test6", nums, invalidReturn, true );
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
