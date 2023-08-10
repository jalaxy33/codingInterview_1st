// 面试题68： 二叉搜索树的最近公共祖先
// 题目：给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
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

class Solution {
   public:
    // 如果p和q在root两侧，那么root就是它们的共同祖先
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q,
                                    bool use_iter = false ) {
        if ( !root ) return nullptr;
        if ( use_iter )
            return withIter( root, p, q );
        else
            return withRecur( root, p, q );
    }

   private:
    // 迭代
    TreeNode* withIter( TreeNode* root, TreeNode* p, TreeNode* q ) {
        // 保证p.val<q.val，减少后续判断
        if ( p->val > q->val ) std::swap( p, q );
        while ( root ) {
            if ( root->val < p->val && root->val < q->val )  // p,q都在右子树
                root = root->right;
            else if ( root->val > p->val && root->val > q->val )  // 都在左子树
                root = root->left;
            else  // 如果分别在两侧，说明找到
                break;
        }
        return root;
    }

    // 递归
    TreeNode* withRecur( TreeNode* root, TreeNode* p, TreeNode* q ) {
        if ( root->val < p->val && root->val < q->val )
            return withRecur( root->right, p, q );
        if ( root->val > p->val && root->val > q->val )
            return withRecur( root->left, p, q );
        return root;
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
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, 2 },
            { 1, 3, 4 },
            { 2, 5, 6 },
            { 4, 7, 8 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

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
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
            { 2, 3, -1 },
            { 3, 4, -1 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

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