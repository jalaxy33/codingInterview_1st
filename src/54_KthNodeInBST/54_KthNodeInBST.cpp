// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点的值。
// 其中 1<=k<=树的节点数

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
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Solution {
   public:
    // 问题转化为：求二叉搜索树的中序遍历倒序的第k大节点
    int kthLargest( TreeNode* root, int k ) {
        this->k = k;  // 重置k的大小
        dfs( root );
        return intResult;
    }

   private:
    int intResult, k;

    void dfs( TreeNode* root ) {
        if ( !root ) return;
        dfs( root->right );    // 中序遍历的倒序
        if ( k == 0 ) return;  // 若k=0，说明已经找到节点，提前返回
        if ( --k == 0 ) intResult = root->val;  // 递减k，直至找到节点
        dfs( root->left );
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root, int k,
                      int expected ) {
        cout << testName;
        int result = solution.kthLargest( root, k );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    //            8
    //        6      10
    //       5 7    9  11
    void TestA() {
        ValVec vals{ 8, 6, 10, 5, 7, 9, 11 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, 6 );

        checkResult( "TestA1", nodes[ 0 ], 1, 11 );
        checkResult( "TestA2", nodes[ 0 ], 2, 10 );
        checkResult( "TestA3", nodes[ 0 ], 3, 9 );
        checkResult( "TestA4", nodes[ 0 ], 4, 8 );
        checkResult( "TestA5", nodes[ 0 ], 5, 7 );
        checkResult( "TestA6", nodes[ 0 ], 6, 6 );
        checkResult( "TestA7", nodes[ 0 ], 7, 5 );
        cout << endl;

        destroyTree( nodes[ 0 ] );
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
    void TestB() {
        ValVec vals{ 5, 4, 3, 2, 1 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, -1 );
        connectNodesIndex( nodes, 1, 2, -1 );
        connectNodesIndex( nodes, 2, 3, -1 );
        connectNodesIndex( nodes, 3, 4, -1 );

        checkResult( "TestB1", nodes[ 0 ], 1, 5 );
        checkResult( "TestB2", nodes[ 0 ], 2, 4 );
        checkResult( "TestB3", nodes[ 0 ], 3, 3 );
        checkResult( "TestB4", nodes[ 0 ], 4, 2 );
        checkResult( "TestB5", nodes[ 0 ], 5, 1 );
        cout << endl;

        destroyTree( nodes[ 0 ] );
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
    void TestC() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, -1, 1 );
        connectNodesIndex( nodes, 1, -1, 2 );
        connectNodesIndex( nodes, 2, -1, 3 );
        connectNodesIndex( nodes, 3, -1, 4 );

        checkResult( "TestC1", nodes[ 0 ], 1, 5 );
        checkResult( "TestC2", nodes[ 0 ], 2, 4 );
        checkResult( "TestC3", nodes[ 0 ], 3, 3 );
        checkResult( "TestC4", nodes[ 0 ], 4, 2 );
        checkResult( "TestC5", nodes[ 0 ], 5, 1 );
        cout << endl;

        destroyTree( nodes[ 0 ] );
    }

    // There is only one node in a tree
    void TestD() {
        ValVec vals{ 1 };
        NodeVec nodes = createNodesVec( vals );

        checkResult( "TestD1", nodes[ 0 ], 1, 1 );
        cout << endl;

        destroyTree( nodes[ 0 ] );
    }

    void runTest() {
        TestA();
        TestB();
        TestC();
        TestD();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}