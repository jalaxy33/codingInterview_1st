// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Solution {
   public:
    // 层序遍历+倒序
    vector<vector<int>> levelOrder( TreeNode* root ) {
        vector<vector<int>> result;
        if ( !root ) return result;

        queue<TreeNode*> q;
        q.push( root );
        while ( !q.empty() ) {
            vector<int> layer;
            for ( int i = q.size(); i > 0; i-- ) {
                TreeNode* tmp = q.front();
                q.pop();
                layer.push_back( tmp->val );
                if ( tmp->left ) q.push( tmp->left );
                if ( tmp->right ) q.push( tmp->right );
            }
            // 由层数的奇偶决定是否倒序输出
            if ( result.size() % 2 == 1 )
                std::reverse( layer.begin(), layer.end() );
            result.push_back( layer );
        }
        return result;
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
