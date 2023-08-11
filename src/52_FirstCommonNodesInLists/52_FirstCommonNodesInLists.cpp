// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

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
    // 双指针A和B分别从两个链表头出发。当A遍历完A链表开始遍历B链表，反之亦然。
    // 由于遍历的长度一致，因此一定会在重合点相遇，此时A==B，返回A或B均可。
    // 设A链B链长度分别为a和b，重合长度为c。则每个指针走的距离均为 a + b -c。
    ListNode *getIntersectionNode( ListNode *headA, ListNode *headB ) {
        if ( headA == headB ) return headA;
        if ( !headA || !headB ) return nullptr;

        ListNode *A = headA, *B = headB;
        while ( A != B ) {
            A = ( A ? A->next : headB );  // 先遍历A链，遍历完了去B链
            B = ( B ? B->next : headA );
        }
        return A;
    }
};

class Test {
   public:
    void checkResult( const string testName, ListNode *headA, ListNode *headB,
                      ListNode *pExpected ) {
        cout << testName;
        ListNode *pResult = solution.getIntersectionNode( headA, headB );
        if ( pResult == pExpected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 第一个公共结点在链表中间
    // 1 - 2 - 3 \
    //            6 - 7
    //     4 - 5 /
    void Test1() {
        ValVec vals1{ 1, 2, 3, 6, 7 };
        ValVec vals2{ 4, 5 };

        ListNodeVec nodes1 = createListNodesVec( vals1 );
        ListNodeVec nodes2 = createListNodesVec( vals2 );
        connectListNodesVec( nodes1 );
        connectListNodesVec( nodes2 );

        connectListNodes( nodes2[ 1 ], nodes1[ 3 ] );
        checkResult( "Test1", nodes1[ 0 ], nodes2[ 0 ], nodes1[ 3 ] );

        destoryListNodesVec( nodes1 );
        destoryListNodesVec( nodes2 );
    }

    // 没有公共结点
    // 1 - 2 - 3 - 4
    //
    // 5 - 6 - 7
    void Test2() {
        ValVec vals1{ 1, 2, 3, 4 };
        ValVec vals2{ 5, 6, 7 };

        ListNodeVec nodes1 = createListNodesVec( vals1 );
        ListNodeVec nodes2 = createListNodesVec( vals2 );
        connectListNodesVec( nodes1 );
        connectListNodesVec( nodes2 );

        checkResult( "Test2", nodes1[ 0 ], nodes2[ 0 ], nullptr );

        destoryListNodesVec( nodes1 );
        destoryListNodesVec( nodes2 );
    }

    // 公共结点是最后一个结点
    // 1 - 2 - 3 - 4 \
    //                7
    //         5 - 6 /
    void Test3() {
        ValVec vals1{ 1, 2, 3, 4, 7 };
        ValVec vals2{ 5, 6 };

        ListNodeVec nodes1 = createListNodesVec( vals1 );
        ListNodeVec nodes2 = createListNodesVec( vals2 );
        connectListNodesVec( nodes1 );
        connectListNodesVec( nodes2 );

        connectListNodes( nodes2[ 1 ], nodes1[ 4 ] );
        checkResult( "Test3", nodes1[ 0 ], nodes2[ 0 ], nodes1[ 4 ] );

        destoryListNodesVec( nodes1 );
        destoryListNodesVec( nodes2 );
    }

    // 公共结点是第一个结点
    // 1 - 2 - 3 - 4 - 5
    // 两个链表完全重合
    void Test3() {
        ValVec vals1{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes1 = createListNodesVec( vals1 );
        connectListNodesVec( nodes1 );

        checkResult( "Test4", nodes1[ 0 ], nodes1[ 0 ], nodes1[ 0 ] );

        destoryListNodesVec( nodes1 );
    }

    // 输入的两个链表有一个空链表
    void Test4() {
        ValVec vals1{ 1, 2, 3, 4, 5 };
        ListNodeVec nodes1 = createListNodesVec( vals1 );
        connectListNodesVec( nodes1 );

        checkResult( "Test5", nodes1[ 0 ], nullptr, nullptr );

        destoryListNodesVec( nodes1 );
    }

    // 输入的两个链表都是空链表
    void Test6() { checkResult( "Test6", nullptr, nullptr, nullptr ); }

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
