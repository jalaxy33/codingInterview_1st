// 面试题59（二）：队列的最大值
// 题目：请定义一个队列并实现函数 max_value 得到队列里的最大值，
// 要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
// 若队列为空，pop_front 和 max_value 需要返回 -1

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

#include <deque>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class MaxQueue {
   public:
    int max_value() const {
        // 最大值在deq首位取得，若为空，则返回-1
        return deq.empty() ? -1 : deq.front();
    }

    void push_back( int value ) {
        que.push( value );
        while ( !deq.empty() && deq.back() < value ) deq.pop_back();
        deq.push_back( value );  // 无论如何value都需要入deq
    }

    int pop_front() {
        if ( que.empty() ) return -1;
        // 从que中弹出
        int val = que.front();
        que.pop();
        // 如果是当前最大值，则从deq弹出
        if ( val == deq.front() ) deq.pop_front();
        return val;
    }

   private:
    queue<int> que;  // 用来存放入队元素
    deque<int> deq;  // 用来构造递减队列
};

class Test {
   public:
    void checkResult( const string testName, const MaxQueue &q, int expected ) {
        if ( !testName.empty() ) cout << testName;

        if ( q.max_value() == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        MaxQueue q;

        // {2}
        q.push_back( 2 );
        checkResult( "Test1", q, 2 );

        // {2, 3}
        q.push_back( 3 );
        checkResult( "Test2", q, 3 );

        // {2, 3, 4}
        q.push_back( 4 );
        checkResult( "Test3", q, 4 );

        // {2, 3, 4, 2}
        q.push_back( 2 );
        checkResult( "Test4", q, 4 );

        // {3, 4, 2}
        q.pop_front();
        checkResult( "Test5", q, 4 );

        // {4, 2}
        q.pop_front();
        checkResult( "Test6", q, 4 );

        // {2}
        q.pop_front();
        checkResult( "Test7", q, 2 );

        // {2, 6}
        q.push_back( 6 );
        checkResult( "Test8", q, 6 );

        // {2, 6, 2}
        q.push_back( 2 );
        checkResult( "Test9", q, 6 );

        // {2, 6, 2, 5}
        q.push_back( 5 );
        checkResult( "Test9", q, 6 );

        // {6, 2, 5}
        q.pop_front();
        checkResult( "Test10", q, 6 );

        // {2, 5}
        q.pop_front();
        checkResult( "Test11", q, 5 );

        // {5}
        q.pop_front();
        checkResult( "Test12", q, 5 );

        // {5, 1}
        q.push_back( 1 );
        checkResult( "Test13", q, 5 );
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
