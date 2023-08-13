// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 动态规划，利用取余
    int lastRemaining( int n, int m ) {
        // 记此问题的解为f(n,m)。
        // 第一个被删除的数字是 k=(m-1)%n，删除后的n-1个数字为
        // 0,1,...,k-1,k+1,...,m，之后从k+1开始计数，
        // 若想使从k+1开始的序列映射为从0到n-2的序列，有如下映射关系：
        // k+1->0, k+2->1, ..., 0->n-k-1,..., k-1->n-2
        // 将该映射定义为p，有p(x) = (x-k-1)%n
        // 逆映射为：p-1(x) = (x+k+1)%n
        // 映射后的序列与原序列都是从0开始的连续序列，可以表示为f(n-1,m)
        // 若已知f(n-1,m)，根据逆映射可推知：
        // f(n,m) = p-1[f(n-1,m)] = (f(n-1,m) + k + 1) % n
        // (代入 k= (m-1)%n )     = (f(n-1,m) + m) % n
        // 而当n=1时，f(n,m)=0.
        // 以上过程本质上就是得到动态规划的转移方程和初始状态。

        if ( n < 1 || m < 1 ) return -1;

        // 从 f(1,m) 递推 f(n,m)
        int ans = 0;
        for ( int i = 2; i <= n; i++ ) ans = ( ans + m ) % i;
        return ans;
    }
};

class Test {
   public:
    void checkResult( const string testName, int n, int m, int expected ) {
        cout << testName;
        int result = solution.lastRemaining( n, m );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 5, 3, 3 );
        checkResult( "Test2", 5, 2, 2 );
        checkResult( "Test3", 6, 7, 4 );
        checkResult( "Test4", 6, 6, 3 );
        checkResult( "Test5", 0, 0, -1 );
        checkResult( "Test6", 4000, 997, 1027 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}