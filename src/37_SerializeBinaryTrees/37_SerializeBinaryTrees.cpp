// 面试题37：序列化二叉树
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。

// 输入输出格式与 LeetCode 目前使用的方式一致，例子：
// 输入：root = [1,2,3,null,null,4,5]
// 输出：[1,2,3,null,null,4,5]

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize( TreeNode* root ) {
        if ( !root ) return "[]";
        string result = "[";

        // 层序遍历
        queue<TreeNode*> q;
        q.push( root );
        while ( !q.empty() ) {
            TreeNode* node = q.front();
            q.pop();
            // 如果节点非空
            if ( node ) {
                // 使用std::to_string函数将数值转换为字符串，并在其后添上逗号
                result += ( std::to_string( node->val ) + "," );
                // 将左右子节点入列，无论是否为空
                q.push( node->left );
                q.push( node->right );
            } else {
                result += "null,";
            }
        }
        result.pop_back();  // 去掉末尾的逗号
        result += "]";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize( string data ) {
        if ( data == "[]" ) return nullptr;

        // 去掉首尾括号后，将原字符串拆分为列表
        vector<string> vals = split( data.substr( 1, data.length() - 2 ) );
        // 生成新的根节点，利用std::stoi将字符串转换为整数，
        // 此时根节点不为空，因此可以安全转换
        TreeNode* root = new TreeNode( std::stoi( vals[ 0 ] ) );

        queue<TreeNode*> q;
        q.push( root );
        int i = 1;  // 用以指示下一节点
        while ( !q.empty() ) {
            TreeNode* node = q.front();
            q.pop();
            // 左子节点
            if ( vals[ i ] != "null" ) {
                node->left = new TreeNode( std::stoi( vals[ i ] ) );
                q.push( node->left );
            }
            i++;
            // 右子节点
            if ( vals[ i ] != "null" ) {
                node->right = new TreeNode( std::stoi( vals[ i ] ) );
                q.push( node->right );
            }
            i++;
        }
        return root;
    }

   private:
    // 将字符串拆分为列表
    vector<string> split( string s, char sep = ',' ) {
        vector<string> strList;
        int i = 0, j = 0, length = s.length();
        while ( i < length ) {
            while ( j < length && s[ j ] != sep ) j++;
            strList.push_back( s.substr( i, j - i ) );
            i = ++j;
        }
        return strList;
    }
};

class Test {
   public:
    void checkResult( const string testName, TreeNode* root, string data ) {
        cout << testName << ": ";

        string resultStr = solution.serialize( root );
        TreeNode* resultRoot = solution.deserialize( resultStr );

        bool sameTree = isSameTree( root, resultRoot );

        cout << "sameStr=" << ( ( data == resultStr ) ? "true, " : "false, " )
             << "sameTree=" << ( sameTree ? "true." : "false." );
        cout << endl;
    }

    //            8
    //        6      10
    //       5 7    9  11
    void Test1() {
        string data =
            "[8,6,10,5,7,9,11,null,null,null,null,null,null,null,null]";

        ValVec vals{ 8, 6, 10, 5, 7, 9, 11 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, 2 );
        connectNodesIndex( nodes, 1, 3, 4 );
        connectNodesIndex( nodes, 2, 5, 6 );

        checkResult( "Test1", nodes[ 0 ], data );
        destroyTree( nodes[ 0 ] );
    }

    //            5
    //          4
    //        3
    //      2
    void Test2() {
        string data = "[5,4,null,3,null,2,null,null,null]";

        ValVec vals{ 5, 4, 3, 2 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, 1, -1 );
        connectNodesIndex( nodes, 1, 2, -1 );
        connectNodesIndex( nodes, 2, 3, -1 );

        checkResult( "Test2", nodes[ 0 ], data );
        destroyTree( nodes[ 0 ] );
    }

    //        5
    //         4
    //          3
    //           2
    void Test3() {
        string data = "[5,null,4,null,3,null,2,null,null]";

        ValVec vals{ 5, 4, 3, 2 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, -1, 1 );
        connectNodesIndex( nodes, 1, -1, 2 );
        connectNodesIndex( nodes, 2, -1, 3 );

        checkResult( "Test3", nodes[ 0 ], data );
        destroyTree( nodes[ 0 ] );
    }

    //        5
    //         5
    //          5
    //         5
    //        5
    //       5 5
    //      5   5
    void Test4() {
        string data =
            "[5,null,5,null,5,5,null,5,null,5,5,5,null,null,5,null,null,null,"
            "null]";

        ValVec vals{ 5, 5, 5, 5, 5, 5, 5, 5, 5 };
        NodeVec nodes = createNodesVec( vals );

        connectNodesIndex( nodes, 0, -1, 1 );
        connectNodesIndex( nodes, 1, -1, 2 );
        connectNodesIndex( nodes, 2, 3, -1 );
        connectNodesIndex( nodes, 2, 3, -1 );
        connectNodesIndex( nodes, 3, 4, -1 );
        connectNodesIndex( nodes, 4, 5, 6 );
        connectNodesIndex( nodes, 5, 7, -1 );
        connectNodesIndex( nodes, 6, -1, 8 );

        checkResult( "Test4", nodes[ 0 ], data );
        destroyTree( nodes[ 0 ] );
    }

    // 只有一个节点
    void Test5() {
        string data = "[1,null,null]";

        ValVec vals{ 1 };
        NodeVec nodes = createNodesVec( vals );

        checkResult( "Test5", nodes[ 0 ], data );
        destroyTree( nodes[ 0 ] );
    }

    // 没有节点
    void Test6() { checkResult( "Test6", nullptr, "[]" ); }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
    }

   private:
    Codec solution;

    bool isSameTree( TreeNode* root1, TreeNode* root2 ) {
        if ( !root1 && !root2 ) return true;
        if ( !root1 || !root2 || root1->val != root2->val ) return false;
        return isSameTree( root1->left, root2->left ) &&
               isSameTree( root1->right, root2->right );
    }
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
