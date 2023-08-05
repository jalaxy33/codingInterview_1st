// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
// 打印到一行。

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Solution {
   public:
    // 用队列实现bfs
    vector<vector<int>> levelOrder( TreeNode* root ) {
        vector<vector<int>> results;
        if ( !root ) return results;

        queue<TreeNode*> q;
        q.push( root );
        while ( !q.empty() ) {
            // 逐层处理
            vector<int> layerVals;
            // q的大小会变化，不适合做循环终止条件，故递减
            for ( int i = q.size(); i > 0; i-- ) {
                TreeNode* tmp = q.front();
                q.pop();
                // 输出本层
                layerVals.push_back( tmp->val );
                // 将下层结点入队
                if ( tmp->left ) q.push( tmp->left );
                if ( tmp->right ) q.push( tmp->right );
            }
            results.push_back( layerVals );
        }
        return results;
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root ) {
        cout << "==== " << testName << " ====\n";
        vector<vector<int>> result = solution.levelOrder( root );
        for ( vector<int> layer : result ) {
            for ( int num : layer ) cout << num << "\t";
            cout << endl;
        }
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