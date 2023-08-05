// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Solution {
   public:
    bool isBalanced( TreeNode* root ) {
        return recur( root ) != -1;  // 不平衡标志为-1
    }

   private:
    // 后序遍历+剪枝。从底至顶判断左右子树是否平衡。
    // 返回当前子树的深度，或者不平衡标志-1
    int recur( TreeNode* root ) {
        // 终止条件：到达叶节点，返回深度为0
        if ( !root ) return 0;
        // 判断左子树
        int left = recur( root->left );
        if ( left == -1 ) return -1;  // 如果左子树不是平衡树则提前结束（剪枝）
        // 判断右子树
        int right = recur( root->right );
        if ( right == -1 ) return -1;
        // 左右子树均平衡，判断当前是否平衡。
        // 若是则返回当前深度 (子树深度+1)，否则返回-1
        return std::abs( left - right ) < 2 ? std::max( left, right ) + 1 : -1;
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root, bool expected ) {
        cout << testName;
        bool result = solution.isBalanced( root );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 完全二叉树
    //             1
    //         /      \
    //        2        3
    //       /\       / \
    //      4  5     6   7
    void Test1() {
        ValVec vals{ 1, 2, 3, 4, 5, 6, 7 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, 6 );

        checkResult( "Test1", nodes[ 0 ], true );
        destroyTree( nodes[ 0 ] );
    }

    // 不是完全二叉树，但是平衡二叉树
    //             1
    //         /      \
    //        2        3
    //       /\         \
    //      4  5         6
    //        /
    //       7
    void Test2() {
        ValVec vals{ 1, 2, 3, 4, 5, 6, 7 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, -1, 5 );
        connectNodesIndex( nodes, 4, 6, -1 );

        checkResult( "Test2", nodes[ 0 ], true );
        destroyTree( nodes[ 0 ] );
    }

    // 不是平衡二叉树
    //             1
    //         /      \
    //        2        3
    //       /\         
    //      4  5
    //        /
    //       6
    void Test3() {
        ValVec vals{ 1, 2, 3, 4, 5, 6 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 4, 5, -1 );

        checkResult( "Test3", nodes[ 0 ], false );
        destroyTree( nodes[ 0 ] );
    }

    //               1
    //              /
    //             2
    //            /
    //           3
    //          /
    //         4
    //        /
    //       5
    void Test4() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, -1 );
        connectNodesIndex( nodes, 1, 2, -1 );
        connectNodesIndex( nodes, 2, 3, -1 );
        connectNodesIndex( nodes, 3, 4, -1 );

        checkResult( "Test4", nodes[ 0 ], false );
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
    void Test5() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, -1, 1 );
        connectNodesIndex( nodes, 1, -1, 2 );
        connectNodesIndex( nodes, 2, -1, 3 );
        connectNodesIndex( nodes, 3, -1, 4 );

        checkResult( "Test5", nodes[ 0 ], false );
        destroyTree( nodes[ 0 ] );
    }

    // 树中只有1个结点
    void Test6() {
        ValVec vals{ 1 };
        NodeVec nodes = createNodesVec( vals );

        checkResult( "Test6", nodes[ 0 ], true );
        destroyTree( nodes[ 0 ] );
    }

    // 树中没有结点
    void Test7() { checkResult( "Test7", nullptr, true ); }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}