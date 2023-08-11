// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

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
    // 双指针，前面的指针先走k步
    ListNode* getKthFromEnd( ListNode* head, int k ) {
        if ( !head ) return nullptr;
        ListNode *p1 = head, *p2 = head;
        for ( int i = 0; i < k; i++ ) {
            if ( p1 == nullptr ) return nullptr;  // 考虑k比链表长的情况
            p1 = p1->next;
        }
        while ( p1 ) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};

class Test {
   public:
    void checkResult( const string testName, ListNode* head, int k,
                      int expected ) {
        cout << testName;
        ListNode* pResult = solution.getKthFromEnd( head, k );

        if ( pResult and pResult->val == expected )
            cout << " passed.\n";
        else if ( !pResult and expected == -1 )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 测试要找的结点在链表中间
    void Test1() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int k = 2;
        int expected = 4;
        checkResult( "Test1", nodes[ 0 ], k, expected );
        destroyList( nodes[ 0 ] );
    }

    // 测试要找的结点是链表的尾结点
    void Test2() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int k = 1;
        int expected = 5;
        checkResult( "Test2", nodes[ 0 ], k, expected );
        destroyList( nodes[ 0 ] );
    }

    // 测试要找的结点是链表的头结点
    void Test3() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int k = 5;
        int expected = 1;
        checkResult( "Test3", nodes[ 0 ], k, expected );
        destroyList( nodes[ 0 ] );
    }

    // 测试空链表
    void Test3() {
        int k = 100;
        int expected = -1;
        checkResult( "Test4", nullptr, k, expected );
    }

    // 测试输入的第二个参数大于链表的结点总数
    void Test4() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int k = 6;
        int expected = -1;
        checkResult( "Test5", nodes[ 0 ], k, expected );
        destroyList( nodes[ 0 ] );
    }

    // 测试输入的第二个参数为0
    void Test6() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes = createListNodesVec( vals );
        connectListNodesVec( nodes );

        int k = 0;
        int expected = -1;
        checkResult( "Test6", nodes[ 0 ], k, expected );
        destroyList( nodes[ 0 ] );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test3();
        Test4();
        Test6();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
