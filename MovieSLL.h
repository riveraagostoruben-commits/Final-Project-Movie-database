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
    // void modifyMovie(newt1, string newd1, string newdt1, string newsy1){]

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







};