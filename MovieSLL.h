#include <iostream>
#include "Movie.h"

using namespace std;

class MovieSLL

{
    private:
    Movie * head;
    Movie * tail;



    public:
    MovieSLL(Movie *head1 = nullptr, Movie *tail1 = nullptr): head(head1),tail(tail1){}
    ~MovieSLL(){
        
        while(head != nullptr){
            Movie *ptr = head;
            head = head->getNext();
            delete ptr;

        }
    }


    

    void addtoHead(string t1, string d1, string dt1, string sy1){

        if(head == nullptr)
        head = tail = new Movie(t1, d1, dt1, sy1, nullptr );

        else{
            head = new Movie(t1, d1, dt1, sy1, head);
        }
        

    }

    void deletefromHead(){
        if(head != nullptr){
            Movie *ptr = head;
            head = ptr->getNext();

            delete ptr;

        }
        if(head == nullptr){
            tail == nullptr;

        }

    }

    void addtoTail(Movie *m1){

    }

    void deletefromTail(){
        if(head!= nullptr){
            Movie * ptr = head;
            while(ptr->getNext() != tail){
            ptr = ptr->getNext();
            }
        }
    }







};