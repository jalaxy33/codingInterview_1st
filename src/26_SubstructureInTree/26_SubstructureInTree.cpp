// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。

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

class Solution {
   public:
    bool isSubStructure( TreeNode* A, TreeNode* B ) {
        // 分两步：1) 遍历A的每个节点nA，2) 判断以nA为根节点的子树是否包含B
        // 先以A为根节点，如果找不到B，则继续在左右子树寻找
        if ( !A || !B ) return false;
        return isAHasB( A, B ) || isSubStructure( A->left, B ) ||
               isSubStructure( A->right, B );
    }

   private:
    // 递归判断A是否包含B
    bool isAHasB( TreeNode* A, TreeNode* B ) {
        // 成功条件：已经遍历至B的叶节点
        if ( !B ) return true;
        // 失败条件：1) 到A的叶节点，但没到B的叶节点; 2) 当前节点值不相同
        if ( !A || A->val != B->val ) return false;
        // 继续遍历左右子树
        return isAHasB( A->left, B->left ) && isAHasB( A->right, B->right );
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* A, TreeNode* B,
                      bool expected ) {
        cout << testName;
        bool result = solution.isSubStructure( A, B );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // 树中结点含有分叉，树B是树A的子结构
    //                  8                8
    //              /       \           / \
    //             8         7         9   2
    //           /   \
    //          9     2
    //               / \
    //              4   7
    void Test1() {
        ValVec Avals{ 8, 8, 7, 9, 2, 4, 7 };
        ValVec Bvals{ 8, 9, 2 };

        TreeNodeVec Anodes = createTreeNodesVec( Avals );
        TreeNodeVec Bnodes = createTreeNodesVec( Bvals );

        TreeIndexVec Aidxs{
            { 0, 1, 2 },
            { 1, 3, 4 },
            { 4, 5, 6 },
        };
        TreeIndexVec Bidxs{
            { 0, 1, 2 },
        };
        connectTreeNodesIndexVec( Anodes, Aidxs );
        connectTreeNodesIndexVec( Bnodes, Bidxs );

        checkResult( "Test1", Anodes[ 0 ], Bnodes[ 0 ], true );
        destroyTree( Anodes[ 0 ] );
        destroyTree( Bnodes[ 0 ] );
    }

    // 树中结点含有分叉，树B不是树A的子结构
    //                  8                8
    //              /       \           / \
    //             8         7         9   2
    //           /   \
    //          9     3
    //               / \
    //              4   7
    void Test2() {
        ValVec Avals{ 8, 8, 7, 9, 3, 4, 7 };
        ValVec Bvals{ 8, 9, 2 };

        TreeNodeVec Anodes = createTreeNodesVec( Avals );
        TreeNodeVec Bnodes = createTreeNodesVec( Bvals );

        TreeIndexVec Aidxs{
            { 0, 1, 2 },
            { 1, 3, 4 },
            { 4, 5, 6 },
        };
        TreeIndexVec Bidxs{
            { 0, 1, 2 },
        };
        connectTreeNodesIndexVec( Anodes, Aidxs );
        connectTreeNodesIndexVec( Bnodes, Bidxs );

        checkResult( "Test2", Anodes[ 0 ], Bnodes[ 0 ], false );
        destroyTree( Anodes[ 0 ] );
        destroyTree( Bnodes[ 0 ] );
    }

    // 树中结点只有左子结点，树B是树A的子结构
    //                8                  8
    //              /                   /
    //             8                   9
    //           /                    /
    //          9                    2
    //         /
    //        2
    //       /
    //      5
    void Test3() {
        ValVec Avals{ 8, 8, 9, 2, 5 };
        ValVec Bvals{ 8, 9, 2 };

        TreeNodeVec Anodes = createTreeNodesVec( Avals );
        TreeNodeVec Bnodes = createTreeNodesVec( Bvals );

        TreeIndexVec Aidxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
            { 2, 3, -1 },
            { 3, 4, -1 },
        };
        TreeIndexVec Bidxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
        };
        connectTreeNodesIndexVec( Anodes, Aidxs );
        connectTreeNodesIndexVec( Bnodes, Bidxs );

        checkResult( "Test3", Anodes[ 0 ], Bnodes[ 0 ], true );
        destroyTree( Anodes[ 0 ] );
        destroyTree( Bnodes[ 0 ] );
    }

    // 树中结点只有左子结点，树B不是树A的子结构
    //                8                  8
    //              /                   /
    //             8                   9
    //           /                    /
    //          9                    3
    //         /
    //        2
    //       /
    //      5
    void Test4() {
        ValVec Avals{ 8, 8, 9, 2, 5 };
        ValVec Bvals{ 8, 9, 3 };

        TreeNodeVec Anodes = createTreeNodesVec( Avals );
        TreeNodeVec Bnodes = createTreeNodesVec( Bvals );

        TreeIndexVec Aidxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
            { 2, 3, -1 },
            { 3, 4, -1 },
        };
        TreeIndexVec Bidxs{
            { 0, 1, -1 },
            { 1, 2, -1 },
        };
        connectTreeNodesIndexVec( Anodes, Aidxs );
        connectTreeNodesIndexVec( Bnodes, Bidxs );

        checkResult( "Test4", Anodes[ 0 ], Bnodes[ 0 ], false );
        destroyTree( Anodes[ 0 ] );
        destroyTree( Bnodes[ 0 ] );
    }

    // 树中结点只有右子结点，树B是树A的子结构
    //       8                   8
    //        \                   \ 
    //         8                   9
    //          \                   \
    //           9                   2
    //            \      
    //             2
    //              \
    //               5
    void Test5() {
        ValVec Avals{ 8, 8, 9, 2, 5 };
        ValVec Bvals{ 8, 9, 2 };

        TreeNodeVec Anodes = createTreeNodesVec( Avals );
        TreeNodeVec Bnodes = createTreeNodesVec( Bvals );

        TreeIndexVec Aidxs{
            { 0, -1, 1 },
            { 1, -1, 2 },
            { 2, -1, 3 },
            { 3, -1, 4 },
        };
        TreeIndexVec Bidxs{
            { 0, -1, 1 },
            { 1, -1, 2 },
        };
        connectTreeNodesIndexVec( Anodes, Aidxs );
        connectTreeNodesIndexVec( Bnodes, Bidxs );

        checkResult( "Test5", Anodes[ 0 ], Bnodes[ 0 ], true );
        destroyTree( Anodes[ 0 ] );
        destroyTree( Bnodes[ 0 ] );
    }

    // 树中结点只有右子结点，树B不是树A的子结构
    //       8                   8
    //        \                   \ 
    //         8                   9
    //          \                 / \
    //           9               3   2
    //            \      
    //             2
    //              \
    //               5
    void Test6() {
        ValVec Avals{ 8, 8, 9, 2, 5 };
        ValVec Bvals{ 8, 9, 3, 2 };

        TreeNodeVec Anodes = createTreeNodesVec( Avals );
        TreeNodeVec Bnodes = createTreeNodesVec( Bvals );

        TreeIndexVec Aidxs{
            { 0, -1, 1 },
            { 1, -1, 2 },
            { 2, -1, 3 },
            { 3, -1, 4 },
        };
        TreeIndexVec Bidxs{
            { 0, -1, 1 },
            { 1, 2, 3 },
        };
        connectTreeNodesIndexVec( Anodes, Aidxs );
        connectTreeNodesIndexVec( Bnodes, Bidxs );

        checkResult( "Test6", Anodes[ 0 ], Bnodes[ 0 ], false );
        destroyTree( Anodes[ 0 ] );
        destroyTree( Bnodes[ 0 ] );
    }

    // 树A为空树
    void Test7() {
        ValVec Bvals{ 8, 9, 3, 2 };
        TreeNodeVec Bnodes = createTreeNodesVec( Bvals );

        TreeIndexVec Bidxs{
            { 0, -1, 1 },
            { 1, 2, 3 },
        };
        connectTreeNodesIndexVec( Bnodes, Bidxs );

        checkResult( "Test7", nullptr, Bnodes[ 0 ], false );
        destroyTree( Bnodes[ 0 ] );
    }

    // 树B为空树
    void Test8() {
        ValVec Avals{ 8, 8, 9, 2, 5 };
        TreeNodeVec Anodes = createTreeNodesVec( Avals );

        TreeIndexVec Aidxs{
            { 0, -1, 1 },
            { 1, -1, 2 },
            { 2, -1, 3 },
            { 3, -1, 4 },
        };
        connectTreeNodesIndexVec( Anodes, Aidxs );

        checkResult( "Test8", Anodes[ 0 ], nullptr, false );
        destroyTree( Anodes[ 0 ] );
    }

    // 树A和树B都为空
    void Test9() { checkResult( "Test9", nullptr, nullptr, false ); }

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
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
