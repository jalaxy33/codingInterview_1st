// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

#include <cstdlib>
#include <exception>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum( int num ) {
        if ( A.size() != B.size() ) {
            // 当数据流总元素数为奇数时，向B添加元素。
            // 先将该元素插入A，再将A堆顶插入B
            A.push( num );
            B.push( A.top() );
            A.pop();
        } else {
            // 当数据流总元素数为偶数时，向A添加元素。
            // 先将该元素插入B，再将B堆顶插入A
            B.push( num );
            A.push( B.top() );
            B.pop();
        }
    }

    // 用两个堆顶来求中位数
    double findMedian() {
        // 当总元素数为奇数时，返回A的堆顶，否则返回堆顶均值
        return A.size() != B.size() ? A.top() : ( A.top() + B.top() ) / 2.0;
    }

    void reset() {
        priority_queue<int, vector<int>, greater<int>> A_;
        priority_queue<int, vector<int>, less<int>> B_;
        std::swap( A, A_ );
        std::swap( B, B_ );
    }

   private:
    // 构建大小顶堆，用两者的堆顶来求中位数
    priority_queue<int, vector<int>, greater<int>> A;  // 小顶堆，保存较大的一半
    priority_queue<int, vector<int>, less<int>> B;  // 大顶堆，保存较小的一半
};

class Test {
   public:
    void checkResult( const string testName, int num, double expected ) {
        cout << testName;
        
        solution.addNum( num );
        double result = solution.findMedian();
        if ( std::abs( result - expected ) < 1e-9 )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        solution.reset();

        checkResult( "Test1", 5, 5 );
        checkResult( "Test2", 2, 3.5 );
        checkResult( "Test3", 3, 3 );
        checkResult( "Test4", 4, 3.5 );
        checkResult( "Test5", 1, 3 );
        checkResult( "Test6", 6, 3.5 );
        checkResult( "Test7", 7, 4 );
        checkResult( "Test8", 0, 3.5 );
        checkResult( "Test9", 8, 4 );
    }

   private:
    MedianFinder solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
