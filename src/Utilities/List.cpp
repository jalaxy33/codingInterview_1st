#include "List.h"

#include <iostream>

ListNode *createListNode( int value ) {
    ListNode *pNode = new ListNode( value );
    return pNode;
}

void connectListNodes( ListNode *pCurrent, ListNode *pNext ) {
    if ( pCurrent == nullptr ) {
        std::cout << "Error to connect two nodes.\n";
        exit( 1 );
    }

    pCurrent->next = pNext;
}

void printListNode( ListNode *pNode ) {
    if ( pNode == nullptr ) {
        std::cout << "The node is nullptr\n";
    } else {
        std::cout << "The key in node is " << pNode->val << std::endl;
    }
}

void printList( ListNode *pHead ) {
    std::cout << "PrintList starts.\n";

    ListNode *pNode = pHead;
    while ( pNode != nullptr ) {
        std::cout << pNode->val << "\t";
        pNode = pNode->next;
    }

    std::cout << "\nPrintList ends.\n";
}

void destroyList( ListNode *pHead ) {
    ListNode *pNode = pHead;
    while ( pNode != nullptr ) {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void addToTail( ListNode **pHead, int value ) {
    ListNode *pNew = new ListNode( value );

    if ( *pHead == nullptr ) {
        *pHead = pNew;
    } else {
        ListNode *pNode = *pHead;
        while ( pNode->next != nullptr ) pNode = pNode->next;

        pNode->next = pNew;
    }
}

void removeNode( ListNode **pHead, int value ) {
    if ( pHead == nullptr || *pHead == nullptr ) return;

    ListNode *pToBeDeleted = nullptr;
    if ( ( *pHead )->val == value ) {
        pToBeDeleted = *pHead;
        *pHead = ( *pHead )->next;
    } else {
        ListNode *pNode = *pHead;
        while ( pNode->next != nullptr && pNode->next->val != value )
            pNode = pNode->next;

        if ( pNode->next != nullptr && pNode->next->val == value ) {
            pToBeDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }
    }

    if ( pToBeDeleted != nullptr ) {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

// ==== multi-nodes ======

ListNodeVec createListNodesVec( const ValVec &vals ) {
    ListNodeVec nodes;
    for ( int i = 0; i < vals.size(); i++ )
        nodes.push_back( createListNode( vals[ i ] ) );
    return nodes;
}

void connectListNodesVec( ListNodeVec &nodes ) {
    if ( nodes.size() < 2 ) return;
    for ( int i = 0; i < nodes.size() - 1; i++ )
        connectListNodes( nodes[ i ], nodes[ i + 1 ] );
}
