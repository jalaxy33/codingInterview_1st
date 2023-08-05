// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Solution {
   public:
    // 使用队列实现BFS
    vector<int> levelOrder( TreeNode* root ) {
        vector<int> results;
        if ( !root ) return results;

        queue<TreeNode*> q;
        q.push( root );
        while ( !q.empty() ) {
            TreeNode* tmp = q.front();
            q.pop();
            results.push_back( tmp->val );
            if ( tmp->left ) q.push( tmp->left );
            if ( tmp->right ) q.push( tmp->right );
        }
        return results;
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root ) {
        cout << testName << ": [ ";
        vector<int> result = solution.levelOrder( root );
        for ( int r : result ) cout << r << ", ";
        cout << "]\n";
    }

    //            10
    //         /      \
    //        6        14
    //       /\        /\
    //      4  8     12  16
    void Test1() {
        ValVec vals{ 10, 6, 14, 4, 8, 12, 16 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, 6 );

        checkResult( "Test1", nodes[ 0 ] );
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
    void Test2() {
        ValVec vals{ 5, 4, 3, 2, 1 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, -1 );
        connectNodesIndex( nodes, 1, 2, -1 );
        connectNodesIndex( nodes, 2, 3, -1 );
        connectNodesIndex( nodes, 3, 4, -1 );

        checkResult( "Test2", nodes[ 0 ] );
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
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, -1, 1 );
        connectNodesIndex( nodes, 1, -1, 2 );
        connectNodesIndex( nodes, 2, -1, 3 );
        connectNodesIndex( nodes, 3, -1, 4 );

        checkResult( "Test3", nodes[ 0 ] );
        destroyTree( nodes[ 0 ] );
    }

    // 树中只有1个结点
    void Test4() {
        ValVec vals{ 1 };
        NodeVec nodes = createNodesVec( vals );

        checkResult( "Test4", nodes[ 0 ] );
        destroyTree( nodes[ 0 ] );
    }

    // 树中没有结点
    void Test5() { checkResult( "Test5", nullptr ); }

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