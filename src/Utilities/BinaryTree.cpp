#include "BinaryTree.h"

#include <iostream>

using namespace std;

BinaryTreeNode* createBinaryTreeNode( int value ) {
    BinaryTreeNode* pNode = new BinaryTreeNode( value );
    return pNode;
}

void connectTreeNodes( BinaryTreeNode* pParent, BinaryTreeNode* pLeft,
                       BinaryTreeNode* pRight ) {
    if ( pParent != nullptr ) {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void printTreeNode( const BinaryTreeNode* pNode ) {
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

void printTree( const BinaryTreeNode* pRoot ) {
    printTreeNode( pRoot );

    if ( pRoot != nullptr ) {
        if ( pRoot->left != nullptr ) printTree( pRoot->left );
        if ( pRoot->right != nullptr ) printTree( pRoot->right );
    }
}

void destroyTree( BinaryTreeNode* pRoot ) {
    if ( pRoot != nullptr ) {
        BinaryTreeNode* pLeft = pRoot->left;
        BinaryTreeNode* pRight = pRoot->right;

        delete pRoot;
        pRoot = nullptr;

        destroyTree( pLeft );
        destroyTree( pRight );
    }
}

NodeVec createNodesVec( const ValVec& vals ) {
    NodeVec nodes;
    for ( int i = 0; i < vals.size(); i++ )
        nodes.push_back( createBinaryTreeNode( vals[ i ] ) );
    return nodes;
}

void connectNodesIndex( NodeVec& nodes, int parent_i, int left_i,
                        int right_i ) {
    BinaryTreeNode* pLeft = ( left_i != -1 ) ? nodes[ left_i ] : nullptr;
    BinaryTreeNode* pRight = ( right_i != -1 ) ? nodes[ right_i ] : nullptr;
    connectTreeNodes( nodes[ parent_i ], pLeft, pRight );
}