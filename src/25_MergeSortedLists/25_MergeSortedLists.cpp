// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <iostream>
#include <string>

#include "../Utilities/List.h"

using namespace std;

class Solution {
   public:
    // 双指针
    ListNode* mergeTwoLists( ListNode* l1, ListNode* l2 ) {
        if ( !l1 )
            return l2;
        else if ( !l2 )
            return l1;

        ListNode* head = new ListNode( 0 );  // 伪头指针
        ListNode* cur = head;                // 指向新节点的指针
        // 构建新的递增序列
        while ( l1 && l2 ) {
            if ( l1->val < l2->val ) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = ( l1 ? l1 : l2 );
        // 处理伪头指针
        cur = head, head = head->next;
        delete cur;
        return head;
    }
};

class Test {
   public:
    void checkResult( const string testName, ListNode* l1, ListNode* l2 ) {
        cout << "==== " << testName << " ====\n";
        ListNode* pResult = solution.mergeTwoLists( l1, l2 );
        printList( pResult );
        cout << endl;
        destroyList( pResult );
    }

    // list1: 1->3->5
    // list2: 2->4->6
    void Test1() {
        ValVec vals1{ 1, 3, 5 };
        ValVec vals2{ 2, 4, 6 };
        ListNodeVec nodes1 = createListNodesVec( vals1 );
        ListNodeVec nodes2 = createListNodesVec( vals2 );
        connectListNodesVec( nodes1 );
        connectListNodesVec( nodes2 );

        checkResult( "Test1", nodes1[ 0 ], nodes2[ 0 ] );
    }

    // 两个链表中有重复的数字
    // list1: 1->3->5
    // list2: 1->3->5
    void Test2() {
        ValVec vals1{ 1, 3, 5 };
        ValVec vals2{ 1, 3, 5 };
        ListNodeVec nodes1 = createListNodesVec( vals1 );
        ListNodeVec nodes2 = createListNodesVec( vals2 );
        connectListNodesVec( nodes1 );
        connectListNodesVec( nodes2 );

        checkResult( "Test2", nodes1[ 0 ], nodes2[ 0 ] );
    }

    // 两个链表都只有一个数字
    // list1: 1
    // list2: 2
    void Test3() {
        ValVec vals1{ 1 };
        ValVec vals2{ 2 };
        ListNodeVec nodes1 = createListNodesVec( vals1 );
        ListNodeVec nodes2 = createListNodesVec( vals2 );
        connectListNodesVec( nodes1 );
        connectListNodesVec( nodes2 );

        checkResult( "Test3", nodes1[ 0 ], nodes2[ 0 ] );
    }

    // 一个链表为空链表
    // list1: 1->3->5
    // list2: 空链表
    void Test3() {
        ValVec vals1{ 1, 3, 5 };
        ListNodeVec nodes1 = createListNodesVec( vals1 );
        connectListNodesVec( nodes1 );

        checkResult( "Test4", nodes1[ 0 ], nullptr );
    }

    // 两个链表都为空链表
    // list1: 空链表
    // list2: 空链表
    void Test4() { checkResult( "Test5", nullptr, nullptr ); }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test3();
        Test4();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
