// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 所给序列即0,1,2,...排列得到的序列。
    // 按照位数将序列分段，先确定所求数位的所在数字的位数，
    // 然后确认其在哪个数字的第几位。
    int findNthDigit( int n ) {
        if ( n < 0 ) return -1;
        if ( n == 0 ) return 0;

        // 一位数 (1~9) 的数位数量为9，二位数 (10~99)的数位数量为2*9*10=180
        // 三位数 (100~999)的数位数量为3*9*100。可推知
        // 当前位数的数字数量 count = 9 * i(位数) * digit(10^位数)

        long i = 1, digit = 1, count = 9;  // 从一位数开始
        // 1）确认n所在数字的位数
        while ( n > count ) {
            n -= count;  // n 减去已经判断过的位数的数字数量
            // 增加位数
            digit *= 10;
            i += 1;
            // 计算新的位数下有多少数字
            count = 9 * i * digit;
        }
        // 2）确认n所在的数字，此时n已经减过之前分段的数字数量了。
        // 每一段的数字从digit开始。
        long num = digit + ( n - 1 ) / i;
        // 3）所求数位是所在数字的第 (n-1)%i 位，先将数字转换为字符串，
        // 方便索引求得数位值，然后再转换为整型
        return std::to_string( num )[ ( n - 1 ) % i ] - '0';
    }
};

class Test {
   public:
    void checkResult( const string testName, int n, int expected ) {
        cout << testName;
        int result = solution.findNthDigit( n );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 0, 0 );
        checkResult( "Test2", 1, 1 );
        checkResult( "Test3", 9, 9 );
        checkResult( "Test4", 10, 1 );
        checkResult( "Test5", 189, 9 );   // 数字99的最后一位，9
        checkResult( "Test6", 190, 1 );   // 数字100的第一位，1
        checkResult( "Test7", 1000, 3 );  // 数字370的第一位，3
        checkResult( "Test8", 1001, 7 );  // 数字370的第二位，7
        checkResult( "Test9", 1002, 0 );  // 数字370的第三位，0
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
