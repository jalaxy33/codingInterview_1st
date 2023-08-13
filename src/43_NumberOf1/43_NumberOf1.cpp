
// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // 从低位到高位遍历数字的各位，每次将数字分为 high | cur | low 三部分。
    // 例如2314，遍历到十位时，high=23，cur=1，low=4。
    // 统计各位上1的个数。
    int countDigitOne( int n ) {
        // digit用以表示当前遍历的数位，初始为个位，后续会*10。
        long digit = 1, result = 0;
        int high = n / 10, cur = n % 10, low = 0;

        // cur数值的不同，决定了该位上1的数量：
        // 1）当cur为0时，如2304的十位，十位为1的数字可能是 0010~2219，
        // 只看高低位 000~229，共230种可能性。此时1的个数 = high * digit,
        // 只由高位决定。
        // 2）当cur为1时，如2314的十位，十位为1的数字可能是 0010~2314，
        // 共 234-0+1=235 种可能。也可以理解为 2304+14，比第一种情况要多算
        // 10~14 的情况。1的个数 = high * digit + low + 1。
        // 3）当cur为2~9时，如2324的十位，十位为1的数字的可能是 0010~2319，
        // 共 239-0+1=240 种可能。也可以理解为 2304+19，比第一种情况要多算
        // 10~19 的情况。1的个数 = high * digit + digit = (high + 1) * digit

        // digit从低位到高位进行遍历，直到 high==0 && cur==0
        while ( high || cur ) {
            // 算result
            if ( cur == 0 )
                result += high * digit;
            else if ( cur == 1 )
                result += high * digit + low + 1;
            else
                result += ( high + 1 ) * digit;
            // 左移数位，更新digit, high, cur, low
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, int n, int expected ) {
        cout << testName;
        int result = solution.countDigitOne( n );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed\n";
    }

    void runTest() {
        checkResult( "Test1", 1, 1 );
        checkResult( "Test2", 5, 1 );
        checkResult( "Test3", 10, 2 );
        checkResult( "Test4", 55, 16 );
        checkResult( "Test5", 99, 20 );
        checkResult( "Test6", 10000, 4001 );
        checkResult( "Test7", 21345, 18821 );
        checkResult( "Test8", 0, 0 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}