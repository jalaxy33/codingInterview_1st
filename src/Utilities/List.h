_Pragma( "once" );

#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    ListNode( int x ) : val( x ), next( nullptr ) {}
};

using ValVec = std::vector<int>;
using ListNodeVec = std::vector<ListNode*>;

ListNode *createListNode( int value );
void connectListNodes( ListNode *pCurrent, ListNode *pNext );
void printListNode( ListNode *pNode );
void printList( ListNode *pHead );
void destroyList( ListNode *pHead );
void addToTail( ListNode **pHead, int value );
void removeNode( ListNode **pHead, int value );


// multi-node
ListNodeVec createListNodesVec(const ValVec& vals);
void connectListNodesVec(ListNodeVec& nodes);
void destoryListNodesVec(ListNodeVec& nodes);

