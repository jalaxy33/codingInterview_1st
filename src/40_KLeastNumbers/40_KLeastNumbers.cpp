// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> getLeastNumbers( vector<int>& arr, int k,
                                 bool use_qsort = false ) {
        result.clear();
        if ( k >= arr.size() ) return arr;
        if ( k <= 0 ) return result;

        if ( use_qsort )
            return quickSort( arr, k, 0, arr.size() - 1 );
        else
            return withHeap( arr, k );
    }

   private:
    // multiset用红黑树实现，表示最大堆
    using intSet = multiset<int, greater<int>>;

    vector<int> result;

    // 由于只需找出最小的k个数，
    // 因此仅需将数组划分为 最小k个数 和 其他数字 两部分即可。
    vector<int> quickSort( vector<int>& arr, int k, int l, int r ) {
        int i = partition( arr, l, r );
        // 将数组分为两部分
        if ( i > k ) return quickSort( arr, k, l, i - 1 );
        if ( i < k ) return quickSort( arr, k, i + 1, r );
        // 返回最终结果
        result.assign( arr.begin(),
                       arr.begin() + k );  // c++中用assign方法来为容器对象赋值
        return result;
    }

    int partition( vector<int>& arr, int l, int r ) {
        // 以最左侧元素l为哨兵，保证交换后左边的元素都比哨兵小，
        // 右边的都更大
        int i = l, j = r;
        while ( i < j ) {
            while ( i < j && arr[ j ] >= arr[ l ] ) j--;
            while ( i < j && arr[ i ] <= arr[ l ] ) i++;
            std::swap( arr[ i ], arr[ j ] );
        }
        std::swap( arr[ i ], arr[ l ] );
        return i;  // 返回当前哨兵坐标
    }

    // 利用最大堆。创建一个容量为k的最大堆，
    // 如果待插入值比最大值小，则替换最大值。
    // 如果更大，则不可能是k个最小之一。
    // 此方法的优点在于不改变原数组。
    vector<int> withHeap( vector<int>& arr, int k ) {
        intSet leastNums;  // 创建最大堆, C++中用set或multiset实现
        return heapSort( arr, leastNums, k );
    }

    vector<int> heapSort( vector<int>& arr, intSet& leastNums, int k ) {
        for ( auto iter = arr.begin(); iter != arr.end(); ++iter ) {
            if ( leastNums.size() < k )
                leastNums.insert( *iter );
            else {
                // 用begin()得到最大堆的堆顶，若当前更小则替换
                if ( *iter < *( leastNums.begin() ) ) {
                    leastNums.erase( leastNums.begin() );
                    leastNums.insert( *iter );
                }
            }
        }
        // 返回最终结果
        auto iter = leastNums.begin();
        for ( int i = 0; i < k; i++ ) result.push_back( *iter++ );
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& arr, int k,
                      vector<int>& expected ) {
        cout << testName;
        vector<int> result = solution.getLeastNumbers( arr, k );

        std::sort( result.begin(), result.end() );
        std::sort( expected.begin(), expected.end() );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // k小于数组长度
    void Test1() {
        vector<int> arr{ 4, 5, 1, 6, 2, 7, 3, 8 };
        vector<int> expected{ 1, 2, 3, 4 };
        int k = expected.size();
        checkResult( "Test1", arr, k, expected );
    }

    // k等于数组的长度
    void Test2() {
        vector<int> arr{ 4, 5, 1, 6, 2, 7, 3, 8 };
        vector<int> expected{ 1, 2, 3, 4, 5, 6, 7, 8 };
        int k = expected.size();
        checkResult( "Test2", arr, k, expected );
    }

    // k大于数组的长度
    void Test3() {
        vector<int> arr{ 4, 5, 1, 6, 2, 7, 3, 8 };
        vector<int> expected{ 4, 5, 1, 6, 2, 7, 3, 8 };
        int k = 10;
        checkResult( "Test3", arr, k, expected );
    }

    // k等于1
    void Test4() {
        vector<int> arr{ 4, 5, 1, 6, 2, 7, 3, 8 };
        vector<int> expected{ 1 };
        int k = expected.size();
        checkResult( "Test4", arr, k, expected );
    }

    // k等于0
    void Test5() {
        vector<int> arr{ 4, 5, 1, 6, 2, 7, 3, 8 };
        vector<int> expected;
        int k = 0;
        checkResult( "Test5", arr, k, expected );
    }

    // 数组中有相同的数字
    void Test6() {
        vector<int> arr{ 4, 5, 1, 6, 2, 7, 2, 8 };
        vector<int> expected{ 1, 2 };
        int k = expected.size();
        checkResult( "Test6", arr, k, expected );
    }

    // 空数组
    void Test7() {
        vector<int> arr;
        vector<int> expected;
        int k = 0;
        checkResult( "Test7", arr, k, expected );
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