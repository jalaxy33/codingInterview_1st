// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <iostream>

#include "../Utilities/List.h"

using namespace std;

class Solution {
   public:
    ListNode* reverseList( ListNode* pHead, bool use_iter = true ) {
        if ( use_iter )
            return reverseList_Iteratively( pHead );
        else
            return reverseList_Recursively( pHead, nullptr );
    }

    // 基于迭代
    ListNode* reverseList_Iteratively( ListNode* pHead ) {
        ListNode *cur = pHead, *pre = nullptr;
        while ( cur != nullptr ) {
            // cur->next, pre, cur = pre, cur, cur->next
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // 基于递归
    ListNode* reverseList_Recursively( ListNode* cur, ListNode* pre ) {
        // 终止条件
        if ( cur == nullptr ) return pre;
        // 递归后继节点
        ListNode* newHead = reverseList_Recursively( cur->next, cur );
        cur->next = pre;  // 修改节点引用指向
        return newHead;   // 返回倒转后的头节点
    }
};

class Test {
   public:
    ListNode* testMain( ListNode* pHead ) {
        cout << "\nThe original list is: \n";
        PrintList( pHead );

        ListNode* pReversedHead = solution.reverseList( pHead );
        cout << "The reversed list is:\n";
        PrintList( pReversedHead );
        cout << "\n";
        return pReversedHead;
    }

    // 输入的链表有多个结点
    void Test1() {
        ListNode* pNode1 = CreateListNode( 1 );
        ListNode* pNode2 = CreateListNode( 2 );
        ListNode* pNode3 = CreateListNode( 3 );
        ListNode* pNode4 = CreateListNode( 4 );
        ListNode* pNode5 = CreateListNode( 5 );

        ConnectListNodes( pNode1, pNode2 );
        ConnectListNodes( pNode2, pNode3 );
        ConnectListNodes( pNode3, pNode4 );
        ConnectListNodes( pNode4, pNode5 );

        ListNode* pReversedHead = testMain( pNode1 );

        DestroyList( pReversedHead );
    }

    // 输入的链表只有一个结点
    void Test2() {
        ListNode* pNode1 = CreateListNode( 1 );
        ListNode* pReversedHead = testMain( pNode1 );
        DestroyList( pReversedHead );
    }

    // 输入空链表
    void Test3() { testMain( nullptr ); }

    void runTest() {
        Test1();
        Test2();
        Test3();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
