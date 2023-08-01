// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第n个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 动态规划
    int nthUglyNumber( int n ) {
        if ( n < 1 ) return 0;  // 处理边界值

        int a = 0, b = 0, c = 0;  // a,b,c分别是指向2, 3, 5倍数的序号
        vector<int> dp( n );      // dp[i]表示第i个丑数
        dp[ 0 ] = 1;              // 1是第一个丑数
        for ( int i = 1; i < n; i++ ) {
            // 得到2,3,5最近的倍数，取其中较小值为dp[i]
            int n2 = dp[ a ] * 2, n3 = dp[ b ] * 3, n5 = dp[ c ] * 5;
            dp[ i ] = std::min( std::min( n2, n3 ), n5 );
            if ( dp[ i ] == n2 ) a++;
            if ( dp[ i ] == n3 ) b++;
            if ( dp[ i ] == n5 ) c++;
        }
        return dp[ n - 1 ];
    }
};

class Test {
   public:
    void checkResult( const string testName, int n, int expected ) {
        if ( !testName.empty() ) cout << testName;

        int result = solution.nthUglyNumber( n );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 1, 1 );
        checkResult( "Test2", 2, 2 );
        checkResult( "Test3", 3, 3 );
        checkResult( "Test4", 4, 4 );
        checkResult( "Test5", 5, 5 );
        checkResult( "Test6", 6, 6 );
        checkResult( "Test7", 7, 8 );
        checkResult( "Test8", 8, 9 );
        checkResult( "Test9", 9, 10 );
        checkResult( "Test10", 10, 12 );
        checkResult( "Test11", 11, 15 );
        checkResult( "Test12", 1500, 859963392 );
        checkResult( "Test13", 0, 0 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
