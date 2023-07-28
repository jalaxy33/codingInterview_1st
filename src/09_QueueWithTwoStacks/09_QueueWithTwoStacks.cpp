// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class CQueue {
   public:
    CQueue() {}

    void appendTail( int value ) {
        // 直接推入栈A即可
        A.push( value );
    }

    int deleteHead() {
        // 如果B中还有元素，则返回B的栈顶并弹出
        if ( !B.empty() ) {
            int tmp = B.top();
            B.pop();
            return tmp;
        }

        // 否则，当A也为空，说明队列中无元素，返回-1
        if ( A.empty() ) return -1;

        // 否则，将A中元素全部转入B，最后返回B栈顶元素
        while ( !A.empty() ) {
            int tmp = A.top();
            A.pop();
            B.push( tmp );
        }
        int tmp = B.top();
        B.pop();
        return tmp;
    }

   private:
    stack<int> A, B;
};

class Test {
   public:
    void checkResult( string text, int actual, int expected ) {
        cout << text;
        if ( actual == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        queue.appendTail( 1 );
        queue.appendTail( 2 );
        queue.appendTail( 3 );

        int head = queue.deleteHead();
        checkResult( "delete 1", head, 1 );

        head = queue.deleteHead();
        checkResult( "delete 2", head, 2 );

        queue.appendTail( 4 );
        head = queue.deleteHead();
        checkResult( "delete 3", head, 3 );

        queue.appendTail( 5 );
        head = queue.deleteHead();
        checkResult( "delete 4", head, 4 );

        head = queue.deleteHead();
        checkResult( "delete 5", head, 5 );
    }

   private:
    CQueue queue;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
