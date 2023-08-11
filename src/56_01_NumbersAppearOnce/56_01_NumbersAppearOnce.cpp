// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 利用异或
    vector<int> singleNumbers( vector<int>& nums ) {
        if ( nums.size() < 2 ) return {};

        // 由于数组里除了两个数字之外,其余只出现了两次
        // 有 a [xor] a ... [xor] x [xor] y = x [xor] y
        int n = 0;
        for ( int num : nums ) n ^= num;  // n = x [xor] y

        if ( n == 0 ) return {};  // 处理无单独数字的情况

        // 接下来从n中拆分x和y. 若x xor y的某位为1, 说明xy该位不同.
        // 找到某个为1的二进制位, 据此将数组拆分为两组.
        // 再次遍历数组, 按照该位的分类对x或y进行异或, 遍历完所有数字即得到x和y

        int index = 1;
        while ( ( n & index ) == 0 ) index <<= 1;  // 找到n中为1的最低位

        int x = 0, y = 0;
        for ( int num : nums ) {  // 分组遍历
            if ( num & index )
                x ^= num;
            else
                y ^= num;
        }
        return { x, y };
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums, int expected1,
                      int expected2, bool valid ) {
        cout << testName;
        vector<int> results = solution.singleNumbers( nums );
        if ( results.size() == 2 && results[ 0 ] != results[ 1 ] && valid ) {
            bool find1 = std::find( results.begin(), results.end(),
                                    expected1 ) != results.end();
            bool find2 = std::find( results.begin(), results.end(),
                                    expected2 ) != results.end();
            if ( find1 && find2 )
                cout << " passed.\n";
            else
                cout << " failed.\n";
        } else if ( ( results.size() < 2 || results[ 0 ] == results[ 1 ] ) &&
                    !valid )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        vector<int> nums{ 2, 4, 3, 6, 3, 2, 5, 5 };
        checkResult( "Test1", nums, 4, 6, true );
    }

    void Test2() {
        vector<int> nums{ 4, 6 };
        checkResult( "Test2", nums, 4, 6, true );
    }

    void Test3() {
        vector<int> nums{ 4, 6, 1, 1 };
        checkResult( "Test3", nums, 4, 6, true );
    }

    void Test4() {
        vector<int> nums{ 4 };
        checkResult( "Test4", nums, -1, -1, false );
    }

    void Test5() {
        vector<int> nums{ 1, 1, 1, 1 };
        checkResult( "Test5", nums, -1, -1, false );
    }

    void Test6() {
        vector<int> nums;
        checkResult( "Test6", nums, -1, -1, false );
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