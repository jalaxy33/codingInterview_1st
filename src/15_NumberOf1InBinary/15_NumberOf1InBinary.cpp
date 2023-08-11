// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
// 本题中输入是一个无符号整数。

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Solution {
   public:
    // 3种解法
    int hammingWeight( uint32_t n, uint32_t which_solution = 3 ) {
        if ( which_solution == 1 )
            return solution1( n );
        else if ( which_solution == 2 )
            return solution2( n );
        else if ( which_solution == 3 )
            return solution3( n );
        else
            throw invalid_argument( "Invalid solution selection!" );
    }

   private:
    // 从高位到低位逐位判断，常规做法。
    // 输入是无符号数，因此无需对符号进行特殊处理。
    int solution1( uint32_t n ) {
        uint32_t result = 0;
        while ( n ) {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }

    // 在输入有符号数的情况下，解法1可能会导致死循环。
    // 改进方法为定义一个变量，从低位到高位逐位判断。
    int solution2( uint32_t n ) {
        uint32_t result = 0, flag = 1;
        while ( flag ) {
            if ( n & flag ) result++;
            flag <<= 1;
        }
        return result;
    }

    // 利用 n&(n-1) 将n最右边的1变成0.
    // 循环消去所有1, 可以减少循环次数
    int solution3( uint32_t n ) {
        uint32_t result = 0;
        while ( n ) {
            result++;
            n &= ( n - 1 );
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, uint32_t n, int expected ) {
        cout << testName;
        int result = solution.hammingWeight( n );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 0, 0 );
        checkResult( "Test2", 1, 1 );
        checkResult( "Test3", 11, 3 );
        checkResult( "Test4", 128, 1 );
        checkResult( "Test5", 0x7FFFFFFF, 31 );
        checkResult( "Test6", 0xFFFFFFFF, 32 );
        checkResult( "Test7", 0x80000000, 1 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}