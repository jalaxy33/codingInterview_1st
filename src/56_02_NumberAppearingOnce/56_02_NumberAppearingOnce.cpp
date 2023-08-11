// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 对于出现三次的数字，其各二进制位出现的次数都是3的倍数。
    // 因此，可以统计各位中1出现的次数，并对3求余，结果为只出现一次的数字。
    int singleNumber( vector<int>& nums, bool use_stateMachine = false ) {
        if ( use_stateMachine )
            return stateMachine( nums );
        else
            return iterCount( nums );
    }

   private:
    // 利用有限状态自动机
    int stateMachine( vector<int>& nums ) {
        // 各位中1的次数对3的余数，有三种状态：0，1，2.
        // 各位余数的状态转换规律为： 1）当输入位为0时，余数不变；
        // 2）当输入位为1时，按 0->1->2->0 的规律转换。

        // 使用两个二进制位 two one 表示各位的余数
        // 变化规律表示为：00->01->10->00

        // 各位one的计算方法（n表示输入数字的某位）：
        // if (two==0): one = one ^ n
        // if (two==1): one = 0
        // 合并起来表示为：one = one ^ n & (~two)
        // 类似的，各位two的计算方法为：
        // two = two ^ n & (~one)

        // twos, ones 代表各位的余数情况，同时计算
        int ones = 0, twos = 0;
        for ( int num : nums ) {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        // 由于数列中只存在出现1次或3次的数字，因此遍历完成后
        // 只会有00和01两种状态，此时ones即为所求数字
        return ones;
    }

    // 遍历统计各位1的数量，分别对3求余得到所求数字的各位。
    // 好理解，但是效率更差。
    int iterCount( vector<int>& nums ) {
        vector<int> counts( 32, 0 );  // 计数数组
        for ( int num : nums ) {
            // 由低到高遍历各位
            for ( int i = 0; i < 32; i++ ) {
                counts[ i ] += num & 1;
                num >>= 1;  // 每轮缩减位数
            }
        }

        // 获得只出现一次的数字，由高位到低位进行恢复
        int result = 0, m = 3;
        for ( int i = 31; i >= 0; i-- ) {
            result <<= 1;
            result |= counts[ i ] % m;  // 恢复第i位
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums, int expected ) {
        cout << testName;
        int result = solution.singleNumber( nums );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 所有数字都是正数，唯一的数字是最小的
    void Test1() {
        vector<int> nums{ 1, 1, 2, 2, 2, 1, 3 };
        int expected = 3;
        checkResult( "Test1", nums, expected );
    }

    // 所有数字都是正数，唯一的数字的大小位于中间
    void Test2() {
        vector<int> nums{ 4, 3, 3, 2, 2, 2, 3 };
        int expected = 4;
        checkResult( "Test2", nums, expected );
    }

    // 所有数字都是正数，唯一的数字是最大的
    void Test3() {
        vector<int> nums{ 4, 4, 1, 1, 1, 7, 4 };
        int expected = 7;
        checkResult( "Test3", nums, expected );
    }

    // 唯一的数字是负数
    void Test4() {
        vector<int> nums{ -10, 214, 214, 214 };
        int expected = -10;
        checkResult( "Test4", nums, expected );
    }

    // 除了唯一的数字，其他数字都是负数
    void Test5() {
        vector<int> nums{ -209, 3467, -209, -209 };
        int expected = 3467;
        checkResult( "Test5", nums, expected );
    }

    // 重复的数字有正数也有负数
    void Test6() {
        vector<int> nums{ 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
        int expected = 1023;
        checkResult( "Test6", nums, expected );
    }

    // 所有数字都是负数
    void Test7() {
        vector<int> nums{ -1024, -1024, -1024, -1023 };
        int expected = -1023;
        checkResult( "Test7", nums, expected );
    }

    // 唯一的数字是0
    void Test8() {
        vector<int> nums{ -23, 0, 214, -23, 214, -23, 214 };
        int expected = 0;
        checkResult( "Test8", nums, expected );
    }

    // 除了唯一的数字，其他数字都是0
    void Test9() {
        vector<int> nums{ 0, 3467, 0, 0, 0, 0, 0, 0 };
        int expected = 3467;
        checkResult( "Test9", nums, expected );
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
