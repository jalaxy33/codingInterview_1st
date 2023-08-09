// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
// 数组可能存在 重复 元素值

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 二分查找
    int minArray( vector<int>& numbers, bool use_strat1 = false ) {
        if ( numbers.empty() ) return 0;

        int i = 0, j = numbers.size() - 1;  // 设置两个指针，分别指向首尾
        while ( i < j ) {
            // 每轮比较中点m和右端点j
            // 为什么不和i比：开始时,j肯定位于右排序序列，
            // 而i不一定位于左排序序列(如初始数组单调递增的情况)
            int m = ( i + j ) / 2;
            // 中点更大,说明右半不是单调递增,旋转点在右半
            if ( numbers[ m ] > numbers[ j ] )
                i = m + 1;
            else if ( numbers[ m ] < numbers[ j ] )
                j = m;
            else {
                // 当相等时,不能直接判断.有两种策略:
                // 1) j-=1, 缩小判断范围
                // 2) 放弃二分, 改为线性查找
                if ( use_strat1 )
                    j--;
                else {
                    int x = i;  // x记录可能的旋转点
                    for ( int k = i + 1; k < j; k++ ) {
                        if ( numbers[ k ] < numbers[ x ] ) x = k;
                    }
                    return numbers[ x ];
                }
            }
        }
        return numbers[ i ];
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& numbers,
                      int expected ) {
        cout << testName;
        int result = solution.minArray( numbers );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 典型输入，单调升序的数组的一个旋转
    void Test1() {
        vector<int> numbers{ 3, 4, 5, 1, 2 };
        checkResult( "Test1", numbers, 1 );
    }

    // 有重复数字，并且重复的数字刚好的最小的数字
    void Test2() {
        vector<int> numbers{ 3, 4, 5, 1, 1, 2 };
        checkResult( "Test2", numbers, 1 );
    }

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    void Test3() {
        vector<int> numbers{ 3, 4, 5, 1, 2, 2 };
        checkResult( "Test3", numbers, 1 );
    }

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    void Test4() {
        vector<int> numbers{ 1, 0, 1, 1, 1 };
        checkResult( "Test4", numbers, 0 );
    }

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    void Test5() {
        vector<int> numbers{ 1, 2, 3, 4, 5 };
        checkResult( "Test5", numbers, 1 );
    }

    // 数组中只有一个数字
    void Test6() {
        vector<int> numbers{ 2 };
        checkResult( "Test6", numbers, 2 );
    }

    // 输入空数组
    void Test7() {
        vector<int> numbers;
        checkResult( "Test7", numbers, 0 );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
