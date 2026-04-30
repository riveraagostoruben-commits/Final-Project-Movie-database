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

    void sortInsert(string g1, MovieSLL *ml1){
        if(head == nullptr){
            head = tail = new GenreNode(g1,m1,nullptr,nullptr);
        }
        else{
            
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






};


