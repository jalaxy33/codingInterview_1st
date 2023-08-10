// 面试题18：给定单向链表的头指针和一个要删除的节点的值，
// 定义一个函数删除该节点。返回删除后的链表的头节点。
// 题目保证链表中节点的值互不相同

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
    // 提交时注释掉 delete 行
    ListNode* deleteNode( ListNode* head, int val ) {
        if ( !head ) return nullptr;

        ListNode *pre = head, *cur = head->next;
        // 如果要删除的节点为头节点
        if ( head->val == val ) {
            delete head;
            return cur;
        }
        // 遍历链表查找节点
        while ( cur && cur->val != val ) {
            pre = cur;
            cur = cur->next;
        }
        // 删除节点
        if ( cur ) {
            pre->next = cur->next;
            delete cur;
        }
        return head;
    }
};

class Test {
   public:
    void checkResult( const string testName, ListNode* head, int val ) {
        cout << "==== " << testName << " ====\n";
        ListNode* resultHead = solution.deleteNode( head, val );
        printList( resultHead );
        destroyList( resultHead );
        cout << endl;
    }

    // 链表中有多个结点，删除中间的结点
    void Test1() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int val = 3;
        checkResult( "Test1", nodes[ 0 ], val );
    }

    // 链表中有多个结点，删除尾结点
    void Test2() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int val = 5;
        checkResult( "Test2", nodes[ 0 ], val );
    }

    // 链表中有多个结点，删除头结点
    void Test3() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int val = 1;
        checkResult( "Test3", nodes[ 0 ], val );
    }

    // 链表中只有一个结点，删除头结点
    void Test4() {
        ValVec vals{ 1 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int val = 1;
        checkResult( "Test4", nodes[ 0 ], val );
    }

    // 链表为空
    void Test5() {
        int val = -1;
        checkResult( "Test5", nullptr, val );
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
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
