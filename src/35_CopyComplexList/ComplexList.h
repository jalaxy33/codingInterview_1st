// 面试题35：复杂链表的复制
// 题目：请实现函数 Node* Clone(Node* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个 next 指针指向下一个
// 结点外，还有一个 random 指向链表中的任意结点或者nullptr。

_Pragma( "once" );

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node( int _val ) : val( _val ), next( nullptr ), random( nullptr ) {}
};

Node* CreateNode( int value );
void BuildNodes( Node* pNode, Node* pNext, Node* pRand );
void PrintList( Node* pHead );
void DestroyList( Node *pHead );
