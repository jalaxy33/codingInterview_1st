// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
// 实例：
// 输入：head = [1,3,2]
// 输出：[2,3,1]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <iostream>
#include <stack>
#include <vector>

#include "../Utilities/List.h"

using namespace std;

class Solution {
   public:
    vector<int> reversePrint( ListNode *pHead, bool isRecur = false ) {
        results.clear();

        if ( isRecur )
            reversePrint_Recursively( pHead );
        else
            reversePrint_Iteratively( pHead );

        return results;
    }

    // 使用递归
    void reversePrint_Recursively( ListNode *pHead ) {
        if ( pHead == nullptr ) return;
        if ( pHead->next != nullptr ) reversePrint_Recursively( pHead->next );
        results.push_back( pHead->val );
    }

    // 使用基于栈的迭代
    void reversePrint_Iteratively( ListNode *pHead ) {
        stack<int> stk;
        while ( pHead != nullptr ) {
            stk.push( pHead->val );
            pHead = pHead->next;
        }

        while ( !stk.empty() ) {
            results.push_back( stk.top() );
            stk.pop();
        }
    }

   private:
    vector<int> results;
};

class Test {
   public:
    void checkResult( ListNode *pHead ) {
        printListNode( pHead );
        vector<int> results;
        results = solution.reversePrint( pHead, true );
        printResults( results );
        results = solution.reversePrint( pHead, false );
        printResults( results );
    }

    // 1->2->3->4->5
    void Test1() {
        cout << "\nTest1 begins.\n";

        ValVec vals{1,2,3,4,5};
        ListNodeVec nodes = createListNodesVec(vals);
        connectListNodesVec(nodes);

        checkResult( nodes[0] );
        destroyList( nodes[0] );
    }

    // 只有一个结点的链表: 1
    void Test2() {
        cout << "\nTest2 begins.\n";

        ListNode *pNode1 = createListNode( 1 );
        checkResult( pNode1 );
        destroyList( pNode1 );
    }

    // 空链表
    void Test3() {
        cout << "\nTest3 begins.\n";
        checkResult( nullptr );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
    }

   private:
    Solution solution;

    template <typename T>
    void printResults( vector<T> &results ) {
        if ( results.empty() ) return;

        for ( T item : results )
            cout << item << " ";
        cout << endl;
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
