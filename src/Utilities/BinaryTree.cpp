#include "BinaryTree.h"

#include <iostream>
#include <tuple>

using namespace std;

TreeNode* createBinaryTreeNode( int value ) {
    TreeNode* pNode = new TreeNode( value );
    return pNode;
}

void connectTreeNodes( TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight ) {
    if ( pParent != nullptr ) {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void printTreeNode( const TreeNode* pNode ) {
    if ( pNode != nullptr ) {
        cout << "value of this node is: " << pNode->val << endl;

        if ( pNode->left != nullptr )
            cout << "value of its left child is: " << pNode->left->val << endl;
        else
            cout << "left child is nullptr.\n";

        if ( pNode->right != nullptr )
            cout << "value of its right child is: " << pNode->right->val
                 << endl;
        else
            cout << "right child is nullptr.\n";
    } else {
        cout << "this node is nullptr.\n";
    }
    cout << endl;
}

void printTree( const TreeNode* pRoot ) {
    printTreeNode( pRoot );

    if ( pRoot != nullptr ) {
        if ( pRoot->left != nullptr ) printTree( pRoot->left );
        if ( pRoot->right != nullptr ) printTree( pRoot->right );
    }
}

void destroyTree( TreeNode* pRoot ) {
    if ( pRoot != nullptr ) {
        TreeNode* pLeft = pRoot->left;
        TreeNode* pRight = pRoot->right;

        delete pRoot;
        pRoot = nullptr;

        destroyTree( pLeft );
        destroyTree( pRight );
    }
}

// ================ multi-nodes =========================

TreeNodeVec createTreeNodesVec( const ValVec& vals ) {
    TreeNodeVec nodes;
    for ( int i = 0; i < vals.size(); i++ )
        nodes.push_back( createBinaryTreeNode( vals[ i ] ) );
    return nodes;
}

void connectTreeNodesIndex( TreeNodeVec& nodes, int parent_i, int left_i,
                            int right_i ) {
    TreeNode* pLeft = ( left_i != -1 ) ? nodes[ left_i ] : nullptr;
    TreeNode* pRight = ( right_i != -1 ) ? nodes[ right_i ] : nullptr;
    connectTreeNodes( nodes[ parent_i ], pLeft, pRight );
}

void connectTreeNodesIndexVec( TreeNodeVec& nodes, TreeIndexVec& indexes ) {
    int parent_i, left_i, right_i;
    for ( TreeIndex idxs : indexes ) {
        std::tie( parent_i, left_i, right_i ) = idxs;
        connectTreeNodesIndex( nodes, parent_i, left_i, right_i );
    }
}
