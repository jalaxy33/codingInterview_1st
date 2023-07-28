#include "ComplexList.h"

#include <iostream>
#include <ostream>

Node* CreateNode( int value ) {
    Node* pNode = new Node( value );
    return pNode;
}

void BuildNodes( Node* pNode, Node* pNext, Node* pRand ) {
    if ( pNode == nullptr ) {
        std::cout << "Error to connect nodes.\n";
        exit( 1 );
    }
    pNode->next = pNext;
    pNode->random = pRand;
}

void PrintList( Node* pHead ) {
    Node* pNode = pHead;
    while ( pNode != nullptr ) {
        std::cout << "The value of this node is: " << pNode->val << std::endl;
        if ( pNode->random != nullptr )
            std::cout << "The value of its random sibling is: "
                      << pNode->random->val << std::endl;
        else
            std::cout << "This node does not have a sibling.\n";
        std::cout << std::endl;
        pNode = pNode->next;
    }
}

void DestroyList( Node* pHead ) {
    Node* pNode = pHead;
    while ( pNode != nullptr ) {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}
