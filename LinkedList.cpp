//
//  main.cpp
//  Linked List Lab
//
//  Created by Nkechi Iregbulem on 4/4/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include <list>


class Node {
    
public:
    string data ="";
    Node* next=nullptr;
    Node* previous=nullptr;
};

class List {
    
public:
    Node* Head=nullptr;
    Node* Tail=nullptr;
    void ListApprend(Node* newNode);
    void ListPrepend(Node* newNode);
    void ListInsertAfter(Node* currNode, Node* newNode);
    void ListRemove(Node* currNode);
    void ListTraverse();
    void ListTraverseReverse();
    void ListInsertionSort();
};


    


void List::ListApprend(Node* newNode) {
    
    if (Head == nullptr) {
        Head = newNode;
        Tail = newNode;
    }
    else{
        Tail->next = newNode;
        newNode->previous = Tail;
        Tail = newNode;
    }
    
}

void List::ListPrepend(Node* newNode) {
    if ( Head == nullptr) {
        Head = newNode;
        Tail = newNode;
    }
    else{
        newNode->next = Head;
        Head->previous = newNode;
        Head = newNode;
    }
}

void List::ListInsertAfter(Node* currNode, Node* newNode) {
    if( Head == nullptr) {
        Head = newNode;
        Tail = newNode;
    }
    else if (currNode == Tail){
        Tail->next = newNode;
        newNode->previous = Tail;
        Tail = newNode;
    }
    else {
        Node* Suc = currNode->next;
        newNode->next = Suc;
        Suc->previous = newNode;
        newNode->previous = currNode;
        currNode->next = newNode;
    }
    
}

void List::ListRemove(Node* currNode) {
    if(currNode == nullptr && Head != nullptr) {
        Node* sucNode;
        sucNode = Head->next;
        Head = sucNode;
        Head->previous = nullptr;
        
        if(sucNode == nullptr) {
            Tail = nullptr;
        }
    }
    else {
        Node* sucNode = currNode->next;
        Node* predNode = currNode->previous;
        if (predNode != nullptr) {
            predNode->next = sucNode;
        }
        if (sucNode != nullptr) {
            sucNode->previous = predNode;
        }

        if (sucNode == nullptr) {
            Tail = predNode;
        }
        if (predNode == nullptr) {
            Head = sucNode;
        }
    }
}

void List::ListTraverse() {
    Node* currNode;
    currNode = Head;
    while(currNode != nullptr) {
        cout << currNode->data << endl;
        currNode = currNode->next;
    }
    
    
}

void List::ListTraverseReverse() {
    Node* currNode;
    currNode = Tail;
    while(currNode != nullptr) {
        cout << currNode->data << endl;
        currNode = currNode->previous;
    }
    
}

void List::ListInsertionSort() {
    Node* currNode;
    currNode = Head->next;
    while(currNode != nullptr) {
        Node* nextNode = currNode->next;
        Node* searchNode = currNode->previous;
        while (searchNode != nullptr && searchNode->data > currNode->data) {
            searchNode = searchNode->previous;
        }
        ListRemove(currNode);
        if (searchNode == nullptr) {
            currNode->previous = nullptr;
            ListPrepend(currNode);
        }
        else{
            ListInsertAfter(searchNode, currNode);
        }
        currNode = nextNode;
    }
}

int main() {
    Node* brush = new Node;
    brush->data = "Brush Teeth";
    Node* wash = new Node;
    wash->data = "wash face";
    Node* eat = new Node;
    eat->data = "eat breakfast";
    Node* school = new Node;
    school->data = "Go to school";
    Node* wake = new Node;
    wake->data = "wake up";
    
    List how;
    how.ListApprend(brush);
    how.ListApprend(wash);
    how.ListApprend(eat);
    how.ListApprend(school);
    how.ListPrepend(wake);
    how.ListTraverse();
    cout<<endl;
    Node* bed = new Node;
    bed->data = "make bed";
    how.ListInsertAfter(wash, bed);
    how.ListTraverseReverse();
    cout<<endl;
    how.ListInsertionSort();
    how.ListTraverse();
    cout<<endl;
    return 0;
}
