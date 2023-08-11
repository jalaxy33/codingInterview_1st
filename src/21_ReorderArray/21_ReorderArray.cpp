
// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 双指针：i从左向右找偶数，j从右向左找奇数，
    // 然后交换两指针
    vector<int> exchange( vector<int>& nums ) {
        int i = 0, j = nums.size() - 1;
        while ( i < j ) {
            while ( i < j && ( nums[ i ] & 1 ) == 1 ) i++;
            while ( i < j && ( nums[ j ] & 1 ) == 0 ) j--;
            std::swap( nums[ i ], nums[ j ] );
        }
        return nums;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& nums ) {
        cout << "==== " << testName << " ====\n";
        cout << "original:\n";
        printArray( nums );

        vector<int> result = solution.exchange( nums );
        cout << "exchanged:\n";
        printArray( result );
        cout << endl;
    }

    void Test1() {
        vector<int> nums{ 1, 2, 3, 4, 5, 6, 7 };
        checkResult( "Test1", nums );
    }

    void Test2() {
        vector<int> nums{ 2, 4, 6, 1, 3, 5, 7 };
        checkResult( "Test2", nums );
    }

    void Test3() {
        vector<int> nums{ 1, 3, 5, 7, 2, 4, 6 };
        checkResult( "Test3", nums );
    }

    void Test4() {
        vector<int> nums{ 1 };
        checkResult( "Test4", nums );
    }

    void Test5() {
        vector<int> nums{ 2 };
        checkResult( "Test5", nums );
    }

    void Test6() {
        vector<int> nums;
        checkResult( "Test6", nums );
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

    void printArray( const vector<int>& nums ) {
        cout << "[ ";
        for ( int num : nums ) cout << num << " ";
        cout << "]\n";
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}