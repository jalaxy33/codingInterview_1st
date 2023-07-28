_Pragma( "once" );

struct ListNode {
    int val;
    ListNode *next;

    ListNode( int x ) : val( x ), next( nullptr ) {}
};

ListNode *CreateListNode( int value );
void ConnectListNodes( ListNode *pCurrent, ListNode *pNext );
void PrintListNode( ListNode *pNode );
void PrintList( ListNode *pHead );
void DestroyList( ListNode *pHead );
void AddToTail( ListNode **pHead, int value );
void RemoveNode( ListNode **pHead, int value );
