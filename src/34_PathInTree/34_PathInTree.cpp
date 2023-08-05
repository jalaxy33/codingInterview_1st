// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#include <iostream>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Solution {
   public:
    vector<vector<int>> pathSum( TreeNode* root, int target ) {
        // 预处理，清空原有数据
        result.clear();
        path.clear();

        recur( root, target );
        return result;
    }

   private:
    vector<vector<int>> result;  // 记录最终结果
    vector<int> path;            // 记录其中一条路径

    void recur( TreeNode* root, int target ) {
        if ( !root ) return;
        // 将当前结点加入路径，并更新目标值
        path.push_back( root->val );  
        target -= root->val;          
        // 成功条件：1) 目标值为0，且 2) 已到达叶节点
        if ( target == 0 && !root->left && !root->right )
            // C++ 中，push_back是复制，无需对动态变化的path特殊处理
            result.push_back( path );
        // 遍历左右子树
        recur( root->left, target );
        recur( root->right, target );
        // 执行到此处说明当前路径不合要求，从path中删除当前节点
        path.pop_back();
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root, int target,
                      int expected_num ) {
        cout << "==== " << testName << " ====\n"
             << "target sum: " << target << endl
             << "expected path num: " << expected_num << endl;

        vector<vector<int>> result = solution.pathSum( root, target );
        cout << "[ ";
        for ( auto path : result ) {
            cout << "[ ";
            for ( auto item : path ) cout << item << ", ";
            cout << "], ";
        }
        cout << "]\n\n";
    }

    //            10
    //         /      \
    //        5        12
    //       /\        
    //      4  7
    // 有两条路径上的结点和为22
    void Test1() {
        ValVec vals{ 10, 5, 12, 4, 7 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );

        checkResult( "Test1", nodes[ 0 ], 22, 2 );
        destroyTree( nodes[ 0 ] );
    }

    //            10
    //         /      \
    //        5        12
    //       /\        
    //      4  7
    // 没有路径上的结点和为15
    void Test2() {
        ValVec vals{ 10, 5, 12, 4, 7 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );

        checkResult( "Test2", nodes[ 0 ], 15, 0 );
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
    // 有一条路径上面的结点和为15
    void Test3() {
        ValVec vals{ 5, 4, 3, 2, 1 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, -1 );
        connectNodesIndex( nodes, 1, 2, -1 );
        connectNodesIndex( nodes, 2, 3, -1 );
        connectNodesIndex( nodes, 3, 4, -1 );

        checkResult( "Test3", nodes[ 0 ], 15, 1 );
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
    // 没有路径上面的结点和为16
    void Test4() {
        ValVec vals{ 1, 2, 3, 4, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, -1, 1 );
        connectNodesIndex( nodes, 1, -1, 2 );
        connectNodesIndex( nodes, 2, -1, 3 );
        connectNodesIndex( nodes, 3, -1, 4 );

        checkResult( "Test4", nodes[ 0 ], 16, 0 );
        destroyTree( nodes[ 0 ] );
    }

    // 树中只有1个结点
    void Test5() {
        ValVec vals{ 1 };
        NodeVec nodes = createNodesVec( vals );

        checkResult( "Test5", nodes[ 0 ], 1, 1 );
        destroyTree( nodes[ 0 ] );
    }

    // 树中没有结点
    void Test6() { checkResult( "Test6", nullptr, 0, 0 ); }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
