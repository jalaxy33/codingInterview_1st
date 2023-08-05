_Pragma( "once" );

#include <vector>

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}
};

using ValVec = std::vector<int>;
using NodeVec = std::vector<BinaryTreeNode*>;

// single-node funcs
BinaryTreeNode* createBinaryTreeNode( int value );
void connectTreeNodes( BinaryTreeNode* pParent, BinaryTreeNode* pLeft,
                       BinaryTreeNode* pRight );
void printTreeNode( const BinaryTreeNode* pNode );
void printTree( const BinaryTreeNode* pRoot );
void destroyTree( BinaryTreeNode* pRoot );

// multi-node funcs
NodeVec createNodesVec( const ValVec& vals );
void connectNodesIndex( NodeVec& nodes, int parent_i, int left_i = -1,
                        int right_i = -1 );
