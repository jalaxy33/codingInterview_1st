// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为0，可以看成任意数字。

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    // 五张牌组成顺子的条件：
    // 1）除大小王之外无重复，2）最大-最小<5
    bool isStraight( vector<int>& nums, bool use_sort = true ) {
        if ( nums.empty() ) return false;

        if ( use_sort )
            return withSort( nums );
        else
            return withSet( nums );
    }

   private:
    // 利用排序
    bool withSort( vector<int>& nums ) {
        int joker = 0;
        std::sort( nums.begin(), nums.end() );  // 对数组排序
        for ( int i = 0; i < 4; i++ ) {  // 因为要比较nums[i]和i+1，所以i只到3
            if ( nums[ i ] == 0 )
                joker++;  // 统计大小王数量
            else if ( nums[ i ] == nums[ i + 1 ] )
                return false;  // 如有重复则提前返回false
        }
        // 最大牌 - 最小牌 < 5 则可构成顺子
        return nums[ 4 ] - nums[ joker ] < 5;
    }

    // 利用集合
    bool withSet( vector<int>& nums ) {
        unordered_set<int> repeat;  // 用集合记录是否有重复
        int max_ = 0, min_ = 14;    // 记录最大和最小的牌
        for ( int num : nums ) {
            if ( num == 0 ) continue;  // 跳过大小王
            max_ = std::max( max_, num );
            min_ = std::min( min_, num );
            if ( repeat.find( num ) != repeat.end() )
                return false;  // 如有重复则提前返回false
            repeat.insert( num );
        }
        return max_ - min_ < 5;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums,
                      bool expected ) {
        cout << testName;
        bool result = solution.isStraight( nums );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        vector<int> nums{ 1, 3, 2, 5, 4 };
        checkResult( "Test1", nums, true );
    }

    void Test2() {
        vector<int> nums{ 1, 3, 2, 6, 4 };
        checkResult( "Test2", nums, false );
    }

    void Test3() {
        vector<int> nums{ 0, 3, 2, 6, 4 };
        checkResult( "Test3", nums, true );
    }

    void Test4() {
        vector<int> nums{ 0, 3, 1, 6, 4 };
        checkResult( "Test4", nums, false );
    }

    void Test5() {
        vector<int> nums{ 1, 3, 0, 5, 0 };
        checkResult( "Test5", nums, true );
    }

    void Test6() {
        vector<int> nums{ 1, 3, 0, 7, 0 };
        checkResult( "Test6", nums, false );
    }

    void Test7() {
        vector<int> nums{ 1, 0, 0, 5, 0 };
        checkResult( "Test7", nums, true );
    }

    void Test8() {
        vector<int> nums{ 1, 0, 0, 7, 0 };
        checkResult( "Test8", nums, false );
    }

    void Test9() {
        vector<int> nums{ 3, 0, 0, 0, 0 };
        checkResult( "Test9", nums, true );
    }

    void Test10() {
        vector<int> nums{ 0, 0, 0, 0, 0 };
        checkResult( "Test10", nums, true );
    }

    // 有对子
    void Test11() {
        vector<int> nums{ 1, 0, 0, 1, 0 };
        checkResult( "Test11", nums, false );
    }

    // 鲁棒性测试
    void Test12() {
        vector<int> nums;
        checkResult( "Test12", nums, false );
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
        Test12();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
