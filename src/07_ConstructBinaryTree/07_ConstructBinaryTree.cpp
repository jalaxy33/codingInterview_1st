// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <exception>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

class Solution {
   public:
    // 前序遍历确认根节点，中序遍历确认左右子树
    TreeNode* buildTree( vector<int>& preorder, vector<int>& inorder ) {
        this->preorder = preorder;
        for ( int i = 0; i < inorder.size(); i++ ) dic[ inorder[ i ] ] = i;
        return recur( 0, 0, inorder.size() - 1 );
    }

   private:
    vector<int> preorder;  // 全局保存前序遍历列表
    unordered_map<int, int> dic;  // 保存中序遍历的值-索引关系，以便快速查询

    // root:根节点在前序遍历的索引，left:子树在中序遍历的左边界，
    // right:子树在中序遍历的右边界
    TreeNode* recur( int root, int left, int right ) {
        if ( left > right ) return nullptr;  // 终止条件：左边界超过右边界
        TreeNode* node = new TreeNode( preorder[ root ] );  // 建立当前根节点

        // 根据根节点位置将中序列表划分为左中右三部分，并分别在左右子树递归
        int i = dic[ preorder[ root ] ];
        // 左子树的根节点前序 = root+1
        node->left = recur( root + 1, left, i - 1 );
        // 右子树的根节点前序 = 根节点位置-左子树序列长度+1
        node->right = recur( i + root - left + 1, i + 1, right );
        return node;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& preorder,
                      vector<int>& inorder ) {
        cout << "==== " << testName << " ====\n";
        try {
            TreeNode* resultRoot = solution.buildTree( preorder, inorder );
            printTree( resultRoot );
            destroyTree( resultRoot );
        } catch ( std::exception& exception ) {
            cout << "Invalid input.\n";
        }
        cout << endl;
    }

    // 普通二叉树
    //              1
    //           /     \
    //          2       3
    //         /       / \
    //        4       5   6
    //         \         /
    //          7       8
    void Test1() {
        vector<int> preorder{ 1, 2, 4, 7, 3, 5, 6, 8 };
        vector<int> inorder{ 4, 7, 2, 1, 5, 3, 8, 6 };
        checkResult( "Test1", preorder, inorder );
    }

    // 所有结点都没有右子结点
    //            1
    //           /
    //          2
    //         /
    //        3
    //       /
    //      4
    //     /
    //    5
    void Test2() {
        vector<int> preorder{ 1, 2, 3, 4, 5 };
        vector<int> inorder{ 5, 4, 3, 2, 1 };
        checkResult( "Test2", preorder, inorder );
    }

    // 所有结点都没有左子结点
    //            1
    //             \ 
    //              2
    //               \ 
    //                3
    //                 \
    //                  4
    //                   \
    //                    5
    void Test3() {
        vector<int> preorder{ 1, 2, 3, 4, 5 };
        vector<int> inorder{ 1, 2, 3, 4, 5 };
        checkResult( "Test3", preorder, inorder );
    }

    // 树中只有一个结点
    void Test4() {
        vector<int> preorder{ 1 };
        vector<int> inorder{ 1 };
        checkResult( "Test4", preorder, inorder );
    }

    // 完全二叉树
    //              1
    //           /     \
    //          2       3
    //         / \     / \
    //        4   5   6   7
    void Test5() {
        vector<int> preorder{ 1, 2, 4, 5, 3, 6, 7 };
        vector<int> inorder{ 4, 2, 5, 1, 6, 3, 7 };
        checkResult( "Test5", preorder, inorder );
    }

    // 输入空指针
    void Test6() {
        vector<int> preorder;
        vector<int> inorder;
        checkResult( "Test6", preorder, inorder );
    }

    // 输入的两个序列不匹配
    void Test7() {
        vector<int> preorder{ 1, 2, 4, 5, 3, 6, 7 };
        vector<int> inorder{ 4, 2, 8, 1, 6, 3, 7 };
        checkResult( "Test7", preorder, inorder );
    }

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