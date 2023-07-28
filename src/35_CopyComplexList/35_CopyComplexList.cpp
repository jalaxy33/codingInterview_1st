// 面试题35：复杂链表的复制
// 题目：请实现函数 Node* Clone(Node* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个 next 指针指向下一个
// 结点外，还有一个 random 指向链表中的任意结点或者nullptr。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

#include <iostream>
#include <string>
#include <unordered_map>

#include "ComplexList.h"

using namespace std;

class Solution {
   public:
    Node* copyRandomList( Node* pHead, bool use_hash = true ) {
        if ( use_hash )
            return copy_Hashtable( pHead );
        else
            return copy_CatSplit( pHead );
    }

    // 利用哈希表
    Node* copy_Hashtable( Node* pHead ) {
        if ( pHead == nullptr ) return nullptr;
        Node* cur = pHead;
        unordered_map<Node*, Node*> map;
        // 存储“原节点-新节点”的映射关系
        while ( cur != nullptr ) {
            map[ cur ] = new Node( cur->val );
            cur = cur->next;
        }
        // 调整新链表节点的next和random指向
        cur = pHead;
        while ( cur != nullptr ) {
            map[ cur ]->next = map[ cur->next ];
            map[ cur ]->random = map[ cur->random ];
            cur = cur->next;
        }
        return map[ pHead ];
    }

    // 利用拼接+拆分
    Node* copy_CatSplit( Node* pHead ) {
        if ( pHead == nullptr ) return nullptr;
        Node* cur = pHead;
        // 1. 复制各节点，并作为原节点的next拼接至原链表
        while ( cur != nullptr ) {
            Node* tmp = new Node( cur->val );
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        // 2. 调整新节点的random指向
        cur = pHead;
        while ( cur != nullptr ) {
            // cur->next是复制节点，cur->random->next是random的复制节点
            if ( cur->random != nullptr ) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 3. 拆分两链表
        cur = pHead->next;
        Node *pre = pHead, *newHead = pHead->next;
        while ( cur->next != nullptr ) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;  // 单独处理原链表尾节点
        return newHead;
    }
};

class Test {
   public:
    void testMain( const string testName, Node* pHead ) {
        if ( !testName.empty() && testName.length() > 0 )
            cout << ">>>" << testName << " begins:\n";

        cout << "[original] list is:\n";
        PrintList( pHead );

        Node* pCopiedHead = solution.copyRandomList( pHead );
        cout << "[copied] list is:\n";
        PrintList( pCopiedHead );

        DestroyList( pCopiedHead );
    }

    //          -----------------
    //         \|/              |
    //  1-------2-------3-------4-------5
    //  |       |      /|\             /|\
    //  --------+--------               |
    //          -------------------------
    void Test1() {
        Node* pNode1 = CreateNode( 1 );
        Node* pNode2 = CreateNode( 2 );
        Node* pNode3 = CreateNode( 3 );
        Node* pNode4 = CreateNode( 4 );
        Node* pNode5 = CreateNode( 5 );

        BuildNodes( pNode1, pNode2, pNode3 );
        BuildNodes( pNode2, pNode3, pNode5 );
        BuildNodes( pNode3, pNode4, nullptr );
        BuildNodes( pNode4, pNode5, pNode2 );

        testMain( "Test1", pNode1 );
    }

    // m_pSibling指向结点自身
    //          -----------------
    //         \|/              |
    //  1-------2-------3-------4-------5
    //         |       | /|\           /|\
    //         |       | --             |
    //         |------------------------|
    void Test2() {
        Node* pNode1 = CreateNode( 1 );
        Node* pNode2 = CreateNode( 2 );
        Node* pNode3 = CreateNode( 3 );
        Node* pNode4 = CreateNode( 4 );
        Node* pNode5 = CreateNode( 5 );

        BuildNodes( pNode1, pNode2, nullptr );
        BuildNodes( pNode2, pNode3, pNode5 );
        BuildNodes( pNode3, pNode4, pNode3 );
        BuildNodes( pNode4, pNode5, pNode2 );

        testMain( "Test2", pNode1 );
    }

    // m_pSibling形成环
    //          -----------------
    //         \|/              |
    //  1-------2-------3-------4-------5
    //          |              /|\
    //          |               |
    //          |---------------|
    void Test3() {
        Node* pNode1 = CreateNode( 1 );
        Node* pNode2 = CreateNode( 2 );
        Node* pNode3 = CreateNode( 3 );
        Node* pNode4 = CreateNode( 4 );
        Node* pNode5 = CreateNode( 5 );

        BuildNodes( pNode1, pNode2, nullptr );
        BuildNodes( pNode2, pNode3, pNode4 );
        BuildNodes( pNode3, pNode4, nullptr );
        BuildNodes( pNode4, pNode5, pNode2 );

        testMain( "Test3", pNode1 );
    }

    // 只有一个结点
    void Test4() {
        Node* pNode1 = CreateNode( 1 );
        BuildNodes( pNode1, nullptr, pNode1 );

        testMain( "Test4", pNode1 );
    }

    // 鲁棒性测试
    void Test5() { testMain( "Test5", nullptr ); }

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