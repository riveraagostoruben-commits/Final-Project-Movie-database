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
    MovieSLL(string gen1 = "N/A", Movie *head1 = nullptr, Movie *tail1 = nullptr): genre(gen1),head(head1),tail(tail1){}
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
            tail = nullptr;

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
    void sortInsert(string t, string d, string date, string s) {
    Movie* newNode = new Movie(t, d, date, s);

    if (head == nullptr || t < head->getTitle()) {
        newNode->setNext(head);
        if (head == nullptr) {
            tail = newNode;
        }
        head = newNode;
        return;
    }
    Movie* ptr = head;
    while (ptr->getNext() != nullptr && t > ptr->getNext()->getTitle()) {
        ptr = ptr->getNext();
    }
    newNode->setNext(ptr->getNext());
    ptr->setNext(newNode);
    
    if (newNode->getNext() == nullptr) {
        tail = newNode;
    }
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
        return nullptr;
    }
    string deleteMovie(string ti1){
        if( head == nullptr)
        return "Movie List Empty";
        if(head!=nullptr){
            Movie * ptr = head;
            if(ptr->getTitle() == ti1){
                head = head->getNext();
                if(head == nullptr){
                    tail = nullptr;
                }
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
        void printList(){
        if(head != nullptr){
            Movie *ptr = head;
            while(ptr!= nullptr){
            cout<< ptr->getTitle() << endl;
            ptr = ptr->getNext();
            }

        }
        return;

    }


    







};