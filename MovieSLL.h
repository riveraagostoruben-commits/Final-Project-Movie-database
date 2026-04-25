#include <iostream>
#include <string>
#include "Movie.h"

using namespace std;

class MovieSLL

{
    private:
    Movie * head;
    Movie * tail;
    string genre;



    public:
    MovieSLL(string genre = "N/A", Movie *head1 = nullptr, Movie *tail1 = nullptr): head(head1),tail(tail1){}
    ~MovieSLL(){
        
        while(head != nullptr){
            Movie *ptr = head;
            head = head->getNext();
            delete ptr;

        }
    }
    Movie *getHead(){
        return head;
    }
    void setHead(Movie* m1){
        head = m1;
    }


    void setGenre(string gnr){
        genre = gnr;
    }
    string getGenre(){
        return genre;
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

    void addtoTail(string t1, string d1, string dt1, string sy1){
        Movie *ptr = new Movie(t1, d1, dt1, sy1, nullptr);

        if(tail != nullptr){
            tail->setNext(ptr);
            tail = tail->getNext();
        }
        else
        head = tail = ptr;

    }

    void deletefromTail(){
        if(head!= nullptr){
            Movie *ptr = head;
            if(head != tail){
            while(ptr->getNext() != tail){
            ptr = ptr->getNext();
            }
            
            tail = ptr;
            ptr = tail->getNext();
            tail->setNext(nullptr);
            }
        
        else{
            head = tail = nullptr;
            }
        delete ptr;
        }
    }
    void sortInsert(Movie *m1){
        if(m1 == nullptr)
        return; //safety check

        if(head == nullptr || m1->getTitle() < head->getTitle()){
            if(head == nullptr){
                head = tail = m1;
            }
            else{
                m1->setNext(head);
                head = m1;
            }
            return;
        }
        

        Movie * ptr = head;
        while( ptr->getNext() != nullptr && m1->getTitle() > ptr->getNext()->getTitle() ){
            ptr = ptr->getNext();


        }
        if(ptr->getNext() == nullptr){
            ptr->setNext(m1);
            tail = m1;
            return;
        }
        m1->setNext(ptr->getNext());
        ptr->setNext(m1);

    }
    string modifyMovie(string ti1, string newd1, string newdt1, string newsy1){
        
        Movie *ptr = findMovieByTitle(ti1);
        if(ptr!=nullptr){
        
        ptr->setDirector(newd1);
        ptr->setPublish_Date(newdt1);
        ptr->setSynopsis(newsy1);
        return "Movie Successfully Modified";
        }
        return "Movie Not Found";
    }


    Movie *findMovieByTitle( string ti1){
        if(head!= nullptr){
            Movie *ptr = head;
            while(ptr != nullptr){
                if(ptr->getTitle() == ti1){
                    return ptr;
                }
                ptr = ptr->getNext();
            }
            return nullptr;


        }
    }
    string deleteMovie(string ti1){
        if( head == nullptr)
        return "Movie List Empty";
        if(head!=nullptr){
            Movie * ptr = head;
            if(ptr->getTitle() == ti1){
                head = head->getNext();
                delete ptr;
                return " Successfully Deleted";
            }
            
            while(ptr->getNext() != nullptr && ptr->getNext()->getTitle() != ti1){
                ptr = ptr->getNext();
            }
            if(ptr->getNext() == nullptr)
            return "Movie Not Found";

            else{
                Movie *ptr2 = ptr->getNext();
                if (ptr2 == tail) {
                tail = ptr;
                }

                ptr->setNext(ptr2->getNext());
                delete ptr2;
                return "Successfully Deleted";
            }
            
            
        }


    }







};