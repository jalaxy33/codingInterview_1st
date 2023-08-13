// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Vec = vector<int>;

class Solution {
   public:
    Vec constructArr( Vec& A ) {
        // 由于不能使用除法，可以将B视为一个nxn矩阵
        // B[0] = 1    A[1] A[2] ... A[n]
        // B[1] = A[0] 1    A[2] ... A[n]
        // ...
        // B[n] = A[0] A[1] A[2] ... 1
        // 可以分为上下三角两部分，分别计算两部分结果即可

        if ( A.empty() ) return {};
        int length = A.size();
        Vec B( length, 1 );
        // 从上到下计算下三角部分
        for ( int i = 1; i < length; i++ ) B[ i ] = B[ i - 1 ] * A[ i - 1 ];
        // 从下到上计算上三角部分和B
        int tmp = 1;
        for ( int i = length - 2; i >= 0; i-- ) {
            tmp *= A[ i + 1 ];  // 上三角
            B[ i ] *= tmp;      // 上三角*下三角
        }
        return B;
    }
};

class Test {
   public:
    void checkResult( const string testName, Vec& A, Vec& expected ) {
        cout << testName;
        Vec B = solution.constructArr( A );
        if ( equalArrays( B, expected ) )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 输入数组中没有0
    void Test1() {
        Vec A{ 1, 2, 3, 4, 5 };
        Vec expected{ 120, 60, 40, 30, 24 };
        checkResult( "Test1", A, expected );
    }

    // 输入数组中有一个0
    void Test2() {
        Vec A{ 1, 2, 0, 4, 5 };
        Vec expected{ 0, 0, 40, 0, 0 };
        checkResult( "Test2", A, expected );
    }

    // 输入数组中有两个0
    void Test3() {
        Vec A{ 1, 2, 0, 4, 0 };
        Vec expected{ 0, 0, 0, 0, 0 };
        checkResult( "Test3", A, expected );
    }

    // 输入数组中有正、负数
    void Test4() {
        Vec A{ 1, -2, 3, -4, 5 };
        Vec expected{ 120, -60, 40, -30, 24 };
        checkResult( "Test4", A, expected );
    }

    // 输入输入中只有两个数字
    void Test5() {
        Vec A{ 1, -2 };
        Vec expected{ -2, 1 };
        checkResult( "Test5", A, expected );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
    }

   private:
    Solution solution;

    bool equalArrays( const Vec& arr1, const Vec& arr2 ) {
        if ( arr1.size() != arr2.size() ) return false;
        for ( int i = 0; i < arr1.size(); i++ ) {
            if ( arr1[ i ] != arr2[ i ] ) return false;
        }
        return true;
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
