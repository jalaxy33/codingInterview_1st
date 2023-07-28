// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

class MinStack {
   public:
    void push( int x ) {
        // 将{x, 当前最小}推入栈中
        if ( stk.empty() )
            stk.push( { x, x } );
        else {
            int tmp = stk.top().second;
            if ( x < tmp ) tmp = x;
            stk.push( { x, tmp } );
        }
    }

    void pop() { stk.pop(); }

    int top() { return stk.top().first; }

    int min() const { return stk.top().second; }

   private:
    // stk.first保存入栈的所有元素，stk.second保存每次栈内的最小值
    stack<pair<int, int>> stk;
};

class Test {
   public:
    void checkResult( const string testName, const MinStack& stk,
                      int expected ) {
        if ( !testName.empty() && testName.length() > 0 ) cout << testName;

        if ( stk.min() == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        MinStack stk;

        stk.push( 3 );
        checkResult( "Test1", stk, 3 );

        stk.push( 4 );
        checkResult( "Test2", stk, 3 );

        stk.push( 2 );
        checkResult( "Test3", stk, 2 );

        stk.push( 3 );
        checkResult( "Test4", stk, 2 );

        stk.pop();
        checkResult( "Test5", stk, 2 );

        stk.pop();
        checkResult( "Test6", stk, 3 );

        stk.pop();
        checkResult( "Test7", stk, 3 );

        stk.push( 0 );
        checkResult( "Test8", stk, 0 );
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
