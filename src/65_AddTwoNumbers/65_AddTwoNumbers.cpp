// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
// 四则运算符号。

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 位运算替代加法.
    // 非进位和——异或；进位——与运算+左移。
    // 由于数字以补码形式存储，因此加减法的过程是相同的。
    int add( int a, int b ) {
        while ( b ) {
            int c = ( a & b ) << 1;  // 计算进位
            a = a ^ b;               // 计算无进位和
            b = c;                   // 将进位c赋值给b，继续循环
        }
        return a;
    }
};

class Test {
   public:
    void checkResult( const string testName, int a, int b, int expected ) {
        cout << testName;
        int result = solution.add( a, b );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 1, 2, 3 );
        checkResult( "Test2", 111, 899, 1010 );
        checkResult( "Test3", -1, 2, 1 );
        checkResult( "Test4", 1, -2, -1 );
        checkResult( "Test5", 3, 0, 3 );
        checkResult( "Test6", 0, -4, -4 );
        checkResult( "Test7", -2, -8, -10 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
