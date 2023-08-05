// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <iostream>
#include <string>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Solution {
   public:
    bool isSymmetric( TreeNode* root ) {
        return ( !root ) || recur( root->left, root->right );
    }

   private:
    // 递归法
    bool recur( TreeNode* lNode, TreeNode* rNode ) {
        // 成功条件：左右子树都遍历至叶节点
        if ( !lNode && !rNode ) return true;
        // 失败条件：1) 一叶一非叶，2) 值不同
        if ( !lNode || !rNode || lNode->val != rNode->val ) return false;
        return recur( lNode->left, rNode->right ) &&
               recur( lNode->right, rNode->left );
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root, bool expected ) {
        cout << testName;
        bool result = solution.isSymmetric( root );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    //            8
    //        6      6
    //       5 7    7 5
    void Test1() {
        ValVec vals{ 8, 6, 6, 5, 7, 7, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, 6 );

        checkResult( "Test1", nodes[ 0 ], true );
        destroyTree( nodes[ 0 ] );
    }

    //            8
    //        6      9
    //       5 7    7 5
    void Test2() {
        ValVec vals{ 8, 6, 9, 5, 7, 7, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, 6 );

        checkResult( "Test2", nodes[ 0 ], false );
        destroyTree( nodes[ 0 ] );
    }

    //            8
    //        6      6
    //       5 7    7
    void Test3() {
        ValVec vals{ 8, 6, 6, 5, 7, 7 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, -1 );

        checkResult( "Test3", nodes[ 0 ], false );
        destroyTree( nodes[ 0 ] );
    }

    //               5
    //              / \
    //             3   3
    //            /     \
    //           4       4
    //          /         \
    //         2           2
    //        /             \
    //       1               1
    void Test4() {
        ValVec vals{ 5, 3, 3, 4, 4, 2, 2, 1, 1 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, -1 );
        connectNodesIndex( nodes, 2, -1, 4 );
        connectNodesIndex( nodes, 3, 5, -1 );
        connectNodesIndex( nodes, 4, -1, 6 );
        connectNodesIndex( nodes, 5, 7, -1 );
        connectNodesIndex( nodes, 6, -1, 8 );

        checkResult( "Test4", nodes[ 0 ], true );
        destroyTree( nodes[ 0 ] );
    }

    //               5
    //              / \
    //             3   3
    //            /     \
    //           4       4
    //          /         \
    //         6           2
    //        /             \
    //       1               1
    void Test5() {
        ValVec vals{ 5, 3, 3, 4, 4, 6, 2, 1, 1 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, -1 );
        connectNodesIndex( nodes, 2, -1, 4 );
        connectNodesIndex( nodes, 3, 5, -1 );
        connectNodesIndex( nodes, 4, -1, 6 );
        connectNodesIndex( nodes, 5, 7, -1 );
        connectNodesIndex( nodes, 6, -1, 8 );

        checkResult( "Test5", nodes[ 0 ], false );
        destroyTree( nodes[ 0 ] );
    }

    //               5
    //              / \
    //             3   3
    //            /     \
    //           4       4
    //          /         \
    //         2           2
    //                      \
    //                       1
    void Test6() {
        ValVec vals{ 5, 3, 3, 4, 4, 2, 2, 1 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, -1 );
        connectNodesIndex( nodes, 2, -1, 4 );
        connectNodesIndex( nodes, 3, 5, -1 );
        connectNodesIndex( nodes, 4, -1, 6 );
        connectNodesIndex( nodes, 5, -1, -1 );
        connectNodesIndex( nodes, 6, -1, 7 );

        checkResult( "Test6", nodes[ 0 ], false );
        destroyTree( nodes[ 0 ] );
    }

    // 只有一个结点
    void Test7() {
        ValVec vals{ 1 };
        NodeVec nodes = createNodesVec( vals );

        checkResult( "Test7", nodes[ 0 ], true );
        destroyTree( nodes[ 0 ] );
    }

    // 没有结点
    void Test8() { checkResult( "Test8", nullptr, true ); }

    // 所有结点都有相同的值，树对称
    //               5
    //              / \
    //             5   5
    //            /     \
    //           5       5
    //          /         \
    //         5           5
    void Test9() {
        ValVec vals{ 5, 5, 5, 5, 5, 5, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, -1 );
        connectNodesIndex( nodes, 2, -1, 4 );
        connectNodesIndex( nodes, 3, 5, -1 );
        connectNodesIndex( nodes, 4, -1, 6 );

        checkResult( "Test9", nodes[ 0 ], true );
        destroyTree( nodes[ 0 ] );
    }

    // 所有结点都有相同的值，树不对称
    //               5
    //              / \
    //             5   5
    //            /     \
    //           5       5
    //          /       /
    //         5       5
    void Test10() {
        ValVec vals{ 5, 5, 5, 5, 5, 5, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, -1 );
        connectNodesIndex( nodes, 2, -1, 4 );
        connectNodesIndex( nodes, 3, 5, -1 );
        connectNodesIndex( nodes, 4, 6, -1 );

        checkResult( "Test10", nodes[ 0 ], false );
        destroyTree( nodes[ 0 ] );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
        Test8();
        Test9();
        Test10();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}