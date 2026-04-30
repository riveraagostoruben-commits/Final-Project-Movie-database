#include <iostream>
#include "GenreNode.h"

class GenreDLL{

    private:
    GenreNode *head;
    GenreNode *tail;


    public:

    void addtoHead(string g1,MovieSLL *ml1){
        if(head!= nullptr){
            head->setPrev(new GenreNode(g1, ml1,nullptr, head));
            head = head->getPrev();
        }
        else {
            head = tail = new GenreNode(g1, ml1,nullptr, nullptr);
        }

    }

    void addtoTail(string g1, MovieSLL *ml1){
        if(tail!= nullptr){
            tail->setNext(new GenreNode(g1, ml1, tail, nullptr));
            tail = tail->getNext();

        }
        else{
            tail = head = new GenreNode(g1,ml1, nullptr, nullptr);
        }

    }

    void deletefromHead(){
        if(head != nullptr){
            GenreNode *ptr = head;
            head = head->getNext();
            if(head == nullptr){
                tail = nullptr;
            }
            else{
                head->setPrev(nullptr);
            }
            delete ptr;
        }

    }

    void deltefromTail(){
        if(head != nullptr){
            GenreNode *ptr = tail;
            if(head!=tail){
                tail =  ptr->getPrev();
                tail->setNext(nullptr);

            }
            else{
                head = tail = nullptr;
            }
            delete ptr;

        }

    }

    void sortInsert(string g1, MovieSLL *m1) {
    GenreNode* newNode = new GenreNode(g1, m1, nullptr, nullptr);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    if (g1 < head->getGenre()) {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
        return;
    }

    GenreNode* ptr = head;
    while (ptr->getNext() != nullptr && g1 > ptr->getNext()->getGenre()) {
        ptr = ptr->getNext();
    }

    if (ptr->getNext() == nullptr) {
        newNode->setPrev(ptr);
        ptr->setNext(newNode);
        tail = newNode;
    }
    else {
        GenreNode* after = ptr->getNext();

        newNode->setNext(after);
        newNode->setPrev(ptr);

        after->setPrev(newNode);
        ptr->setNext(newNode);
    }
}
    void printList(){
        if(head != nullptr){
            GenreNode *ptr = head;
            while(ptr!= nullptr){
            cout<< ptr->getGenre() << endl;
            ptr = ptr->getNext();
            }

        }
        return;

    }

    void listallMovforGenre(string g1){
        if(head!= nullptr){
            GenreNode *ptr = head;
            while(ptr!= nullptr){
                if(g1 == ptr->getGenre()){
                    ptr->getMovList()->printList();
                    return;
                }
                ptr = ptr->getNext();

            }
            cout<< "Genre not found";
            return;


    }
}






};


