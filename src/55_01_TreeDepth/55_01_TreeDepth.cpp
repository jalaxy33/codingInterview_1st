// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

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
#include <iostream>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

class Solution {
   public:
    // 树高=左右子树层数的最大值+1
    int maxDepth( TreeNode* root ) {
        if ( !root ) return 0;
        return std::max( maxDepth( root->left ), maxDepth( root->right ) ) + 1;
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root, int expected ) {
        cout << testName;
        int result = solution.maxDepth( root );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    //            1
    //         /      \
    //        2        3
    //       /\         \
    //      4  5         6
    //        /
    //       7
    void Test1() {
        ValVec vals{ 1, 2, 3, 4, 5, 6, 7 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, 2 },
            { 1, 3, 4 },
            { 2, -1, 5 },
            { 4, 6, -1 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test1", nodes[ 0 ], 4 );
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
    void Test2() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
            { 2, 3, -1 },
            { 3, 4, -1 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test2", nodes[ 0 ], 5 );
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
    void Test3() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, -1, 1 },
            { 1, -1, 2 },
            { 2, -1, 3 },
            { 3, -1, 4 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test3", nodes[ 0 ], 5 );
        destroyTree( nodes[ 0 ] );
    }

    // 树中只有1个结点
    void Test4() {
        ValVec vals{ 1 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        checkResult( "Test4", nodes[ 0 ], 1 );
        destroyTree( nodes[ 0 ] );
    }

    // 树中没有结点
    void Test5() { checkResult( "Test5", nullptr, 0 ); }

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