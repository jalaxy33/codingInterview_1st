#include <tuple>
_Pragma( "once" );

#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}
};

using ValVec = std::vector<int>;
using TreeNodeVec = std::vector<TreeNode*>;
using TreeIndex = std::tuple<int, int, int>;
using TreeIndexVec = std::vector<TreeIndex>;

// single-node funcs
TreeNode* createBinaryTreeNode( int value );
void connectTreeNodes( TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight );
void printTreeNode( const TreeNode* pNode );
void printTree( const TreeNode* pRoot );
void destroyTree( TreeNode* pRoot );

// multi-node funcs
TreeNodeVec createTreeNodesVec( const ValVec& vals );
void connectTreeNodesIndex( TreeNodeVec& nodes, int parent_i, int left_i = -1,
                            int right_i = -1 );
void connectTreeNodesIndexVec( TreeNodeVec& nodes, TreeIndexVec& indexes );
