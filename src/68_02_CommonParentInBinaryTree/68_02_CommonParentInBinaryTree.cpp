// 面试题68： 二叉树的最近公共祖先
// 题目：给定一个普通的二叉树, 找到该树中两个指定节点的最近公共祖先。
// 所有节点的值都是唯一的, p、q 为不同节点且均存在于给定的二叉搜索树中

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
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q ) {
        if ( !root || root == p || root == q ) return root;
        TreeNode* left = lowestCommonAncestor( root->left, p, q );
        TreeNode* right = lowestCommonAncestor( root->right, p, q );
        if ( !left ) return right;  // 共同祖先不在左侧
        if ( !right ) return left;  // 共同祖先不在右侧
        return root;  // 两侧均非空，说明当前正是共同祖先
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root, TreeNode* p,
                      TreeNode* q, TreeNode* expected ) {
        cout << testName;
        TreeNode* result = solution.lowestCommonAncestor( root, p, q );
        if ( ( !expected && !result ) ||
             ( expected && result && expected->val == result->val ) )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    //      6
    //    /   \
    //   2     8
    //  / \    / \
    // 0   4  7   9
    //    / \
    //   3   5
    // p=0, q=5, expected=2
    void Test1() {
        ValVec vals{ 6, 2, 8, 0, 4, 7, 9, 3, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, 6 );
        connectNodesIndex( nodes, 4, 7, 8 );

        checkResult( "Test1", nodes[ 0 ], nodes[ 3 ], nodes[ 8 ], nodes[ 1 ] );
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
    // p=1, q=3, expected=4
    void Test2() {
        ValVec vals{ 5, 4, 3, 2, 1 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, -1 );
        connectNodesIndex( nodes, 1, 2, -1 );
        connectNodesIndex( nodes, 2, 3, -1 );
        connectNodesIndex( nodes, 3, 4, -1 );

        checkResult( "Test2", nodes[ 0 ], nodes[ 4 ], nodes[ 2 ], nodes[ 2 ] );
        destroyTree( nodes[ 0 ] );
    }

    // 输入nullptr
    void Test3() { checkResult( "Test3", nullptr, nullptr, nullptr, nullptr ); }

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