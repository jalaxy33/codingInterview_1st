// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow( const vector<int>& nums, int k ) {
        if ( nums.size() < k || k < 1 ) return vector<int>{};

        deque<int> index;  // 用于存放可能的窗口最大值的序号
        // 未形成窗口时
        for ( int i = 0; i < k; i++ ) {
            while ( !index.empty() && nums[ index.back() ] < nums[ i ] )
                index.pop_back();
            index.push_back( i );
        }

        // 形成窗口后
        vector<int> results{ nums[ index.front() ] };
        for ( int i = k; i < nums.size(); i++ ) {
            // 当队列首位的序号不在窗口中时，推出该序号
            if ( !index.empty() && index.front() <= ( i - k ) )
                index.pop_front();
            // 推出队列内不比当前入窗元素大的元素
            while ( !index.empty() && nums[ i ] >= nums[ index.back() ] )
                index.pop_back();
            index.push_back( i );  // 将当前入窗元素推入队列
            // 每次将队列首个元素推入结果列表
            results.push_back( nums[ index.front() ] );
        }
        return results;
    }
};

class Test {
   public:
    void checkResult( const string testName, const vector<int>& nums, int k,
                      const vector<int>& expected ) {
        if ( !testName.empty() ) cout << testName;

        vector<int> results = solution.maxSlidingWindow( nums, k );

        auto iter_results = results.begin();
        auto iter_expected = expected.begin();
        while ( iter_results < results.end() &&
                iter_expected < expected.end() ) {
            if ( *iter_results != *iter_expected ) break;
            ++iter_results;
            ++iter_expected;
        }

        if ( iter_results == results.end() && iter_expected == expected.end() )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        vector<int> nums{ 2, 3, 4, 2, 6, 2, 5, 1 };
        vector<int> expected{ 4, 4, 6, 6, 6, 5 };
        int k = 3;
        checkResult( "Test1", nums, k, expected );
    }

    void Test2() {
        vector<int> nums{ 1, 3, -1, -3, 5, 3, 6, 7 };
        vector<int> expected{ 3, 3, 5, 5, 6, 7 };
        int k = 3;
        checkResult( "Test2", nums, k, expected );
    }

    // 输入数组单调递增
    void Test3() {
        vector<int> nums{ 1, 3, 5, 7, 9, 11, 13, 15 };
        vector<int> expected{ 7, 9, 11, 13, 15 };
        int k = 4;
        checkResult( "Test3", nums, k, expected );
    }

    // 输入数组单调递减
    void Test4() {
        vector<int> nums{ 16, 14, 12, 10, 8, 6, 4 };
        vector<int> expected{ 16, 14, 12 };
        int k = 5;
        checkResult( "Test4", nums, k, expected );
    }

    // 滑动窗口的大小为1
    void Test5() {
        vector<int> nums{ 10, 14, 12, 11 };
        vector<int> expected{ 10, 14, 12, 11 };
        int k = 1;
        checkResult( "Test5", nums, k, expected );
    }

    // 滑动窗口的大小等于数组的长度
    void Test6() {
        vector<int> nums{ 10, 14, 12, 11 };
        vector<int> expected{ 14 };
        int k = 4;
        checkResult( "Test6", nums, k, expected );
    }

    // 滑动窗口的大小为0
    void Test7() {
        vector<int> nums{ 10, 14, 12, 11 };
        vector<int> expected;
        int k = 0;
        checkResult( "Test7", nums, k, expected );
    }

    // 滑动窗口的大小大于输入数组的长度
    void Test8() {
        vector<int> nums{ 10, 14, 12, 11 };
        vector<int> expected;
        int k = 5;
        checkResult( "Test8", nums, k, expected );
    }

    // 输入数组为空
    void Test9() {
        vector<int> nums;
        vector<int> expected;
        int k = 5;
        checkResult( "Test9", nums, k, expected );
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
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
