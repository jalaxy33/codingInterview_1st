// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。
// 对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
// 当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。
// 还需要返回链表中的第一个节点的指针。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};
*/

#include <iostream>
#include <string>

#include "../Utilities/BinaryTree.h"

using namespace std;

using Node = TreeNode;

class Solution {
   public:
    Node* treeToDoublyList( Node* root ) {
        // 转化为排序的循环双向链表，包含三个要素:
        // 1) 排序链表：节点从小到大排列，原树为二叉排序树，因此采用中序遍历
        // 2）双向链表：原左子节点为前驱，原右子节点为后继
        // 3）循环链表：链表的头尾节点相连

        head = nullptr, pre = nullptr;  // 重置全局指针

        if ( !root ) return nullptr;
        dfs( root );

        // 最后连接头尾节点
        if ( head ) head->left = pre;
        if ( pre ) pre->right = head;
        return head;
    }

   private:
    Node *head, *pre;  // 全局记录头节点、前驱节点

    // 中序遍历
    void dfs( Node* cur ) {
        // 终止条件：当前节点为空
        if ( !cur ) return;

        // 遍历左子节点
        dfs( cur->left );

        // pre为空说明刚开始，记录当前节点为头节点
        // 否则连接cur与pre
        if ( pre )
            pre->right = cur;
        else
            head = cur;

        cur->left = pre;
        pre = cur;

        // 遍历右子节点
        dfs( cur->right );
    }
};

class Test {
   public:
    void checkResult( const string testName, Node* root ) {
        cout << "==== " << testName << " ====\n";
        Node* resultHead = solution.treeToDoublyList( root );
        printDoubleLinkedList( resultHead );
        destroyDoubleLinkedList( resultHead );
    }

    //            10
    //         /      \
    //        5        14
    //       /\       /  \
    //      4  7    12    16
    void Test1() {
        ValVec vals{ 10, 5, 14, 4, 7, 12, 16 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, 2 },
            { 1, 3, 4 },
            { 2, 5, 6 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test1", nodes[ 0 ] );
    }

    //            10
    //         /      \
    //        5        14
    //       /\        
    //      4  7
    void Test2() {
        ValVec vals{ 10, 5, 14, 4, 7 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, 2 }, { 1, 3, 4 },
            // { 2, 5, 6 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test2", nodes[ 0 ] );
    }

    //               5
    //              /
    //             4
    //            /
    //           3
    //          /
    //         2
    //        /
    //       1
    void Test3() {
        ValVec vals{ 5, 4, 3, 2, 1 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
            { 2, 3, -1 },
            { 3, 4, -1 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test3", nodes[ 0 ] );
    }

    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    //        \
    //         5
    void Test4() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, -1, 1 },
            { 1, -1, 2 },
            { 2, -1, 3 },
            { 3, -1, 4 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test4", nodes[ 0 ] );
    }

    // 树中只有1个结点
    void Test5() {
        ValVec vals{ 1 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        checkResult( "Test5", nodes[ 0 ] );
    }

    // 树中没有结点
    void Test6() { checkResult( "Test6", nullptr ); }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
    }

   private:
    Solution solution;

    void printDoubleLinkedList( Node* head ) {
        Node* tail = head ? head->left : nullptr;

        // 先切断首尾节点的连接
        if ( tail ) tail->right = nullptr;
        if ( head ) head->left = nullptr;

        Node* node = head;
        cout << "(L -> R):\t";
        while ( node ) {
            cout << node->val << "\t";
            if ( !node->right ) break;
            node = node->right;
        }
        cout << endl;

        node = tail;
        cout << "(R -> L):\t";
        while ( node ) {
            cout << node->val << "\t";
            if ( !node->left ) break;
            node = node->left;
        }
        cout << endl << endl;

        // 最后再重新连接首尾节点
        if ( tail ) tail->right = head;
        if ( head ) head->left = tail;
    }

    void destroyDoubleLinkedList( Node* head ) {
        Node* node = head;
        Node* tail = head ? head->left : nullptr;

        // 先切断首尾节点连接
        if ( tail ) tail->right = nullptr;
        if ( head ) head->left = nullptr;

        while ( node ) {
            Node* next = node->right;
            delete node;
            node = next;
        }
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}