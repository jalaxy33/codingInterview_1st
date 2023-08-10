// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。

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
#include <stack>
#include <string>

#include "../Utilities/BinaryTree.h"

using namespace std;

class Solution {
   public:
    TreeNode* mirrorTree( TreeNode* pRoot, bool use_recur = false ) {
        if ( use_recur )
            return withRecur( pRoot );
        else
            return withIter( pRoot );
    }

   private:
    // 递归法
    TreeNode* withRecur( TreeNode* pRoot ) {
        if ( !pRoot ) return nullptr;
        TreeNode* tmp = pRoot->left;
        pRoot->left = withRecur( pRoot->right );
        pRoot->right = withRecur( tmp );
        return pRoot;
    }

    // 迭代法，借助栈
    TreeNode* withIter( TreeNode* pRoot ) {
        if ( !pRoot ) return nullptr;
        stack<TreeNode*> stk;
        stk.push( pRoot );  // 根节点入栈
        while ( !stk.empty() ) {
            // 栈顶节点出栈
            TreeNode* node = stk.top();
            stk.pop();
            // 使左右子节点入栈
            if ( node->left ) stk.push( node->left );
            if ( node->right ) stk.push( node->right );
            // 交换左右子树
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        return pRoot;
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* pRoot ) {
        cout << "==== " << testName << " ====\n";

        cout << "[original]:\n";
        printTree( pRoot );

        cout << "\n[mirrorred]:\n";
        TreeNode* pMirror = solution.mirrorTree( pRoot );
        printTree( pMirror );

        cout << endl;
    }

    // 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
    //            8
    //        6      10
    //       5 7    9  11
    void Test1() {
        ValVec vals{ 8, 6, 10, 5, 7, 9, 11 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, 2 },
            { 1, 3, 4 },
            { 2, 5, 6 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test1", nodes[ 0 ] );
    }

    // 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
    //            8
    //          7
    //        6
    //      5
    //    4
    void Test2() {
        ValVec vals{ 8, 7, 6, 5, 4 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
            { 2, 3, -1 },
            { 3, 4, -1 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test2", nodes[ 0 ] );
    }

    // 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
    //            8
    //             7
    //              6
    //               5
    //                4
    void Test3() {
        ValVec vals{ 8, 7, 6, 5, 4 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        TreeIndexVec idxs{
            { 0, -1, 1 },
            { 1, -1, 2 },
            { 2, -1, 3 },
            { 3, -1, 4 },
        };
        connectTreeNodesIndexVec( nodes, idxs );

        checkResult( "Test3", nodes[ 0 ] );
    }

    // 测试空二叉树：根结点为空指针
    void Test4() { checkResult( "Test4", nullptr ); }

    // 测试只有一个结点的二叉树
    void Test5() {
        ValVec vals{ 8 };
        TreeNodeVec nodes = createTreeNodesVec( vals );

        checkResult( "Test5", nodes[ 0 ] );
    }

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
