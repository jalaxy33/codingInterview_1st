// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。规定最大利润为负时不得完成交易，利润为0.

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 动态规划
    int maxProfit( vector<int>& prices ) {
        if ( prices.size() < 2 ) return 0;

        // dp[i]为以prices[i]为结尾的子数组的最大利润
        // 转移方程为 dp[i] = max( dp[i-1] , prices[i]-min(prices[0:i]) )
        // 降低时间复杂度：用一个变量记录每日的最低价格cost
        // 降低空间复杂度：dp[i]只与当前与前一位置相关，用一个变量profit替代整个dp列表
        // 转移方程简化为 profit = max( profit , prices[i]-min(cost,prices[i-1])
        // )
        int cost = INT32_MAX, profit = INT32_MIN;
        for ( int price : prices ) {
            profit = std::max( profit, price - cost );
            cost = std::min( cost, price );
        }
        // 利润为负时不交易，利润返回0
        return profit < 0 ? 0 : profit;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& prices,
                      int expected ) {
        if ( !testName.empty() ) cout << testName;

        int result = solution.maxProfit( prices );
        // cout << ", result=" << result << ", expected=" << expected;
        if ( result == expected )
            cout << " passed.\n";
        else if ( expected < 0 && result == 0 )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        vector<int> numbers{ 4, 1, 3, 2, 5 };
        checkResult( "Test1", numbers, 4 );
    }

    // 价格递增
    void Test2() {
        vector<int> numbers{ 1, 2, 4, 7, 11, 16 };
        checkResult( "Test2", numbers, 15 );
    }

    // 价格递减
    void Test3() {
        vector<int> numbers{ 16, 11, 7, 4, 2, 1 };
        checkResult( "Test3", numbers, -1 );
    }

    // 价格全部相同
    void Test4() {
        vector<int> numbers{ 16, 16, 16, 16, 16 };
        checkResult( "Test4", numbers, 0 );
    }

    void Test5() {
        vector<int> numbers{ 9, 11, 5, 7, 16, 1, 4, 2 };
        checkResult( "Test5", numbers, 11 );
    }

    void Test6() {
        vector<int> numbers{ 2, 4 };
        checkResult( "Test6", numbers, 2 );
    }

    void Test7() {
        vector<int> numbers{ 4, 2 };
        checkResult( "Test7", numbers, -2 );
    }

    void Test8() {
        vector<int> numbers;
        checkResult( "Test8", numbers, 0 );
    }

    void Test9() {
        vector<int> numbers{ 7, 6, 4, 3, 1 };
        checkResult( "Test9", numbers, -1 );
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
