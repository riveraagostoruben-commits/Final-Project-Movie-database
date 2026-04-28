#include<iostream>
#include<string>
#include "MovieSLL.h"
using namespace std;

class GenreNode 
{
    private:
    string genre;
    
    GenreNode *prev;
    GenreNode *next;

    MovieSLL *MovList;






    public:
    

    void setGenre(string g1){
        genre = g1;
    }

    string getGenre(){
        return genre;
    }

    void setNext(GenreNode *gnn){
        next = gnn;
    }
    GenreNode *getNext(){
        return next;
    }

    void setPrev(GenreNode * gnp){
        prev = gnp;
    }

    GenreNode *getPrev(){
        return prev;
    }

    void setMovList(MovieSLL * movl1){
        MovList = movl1;

    }

    MovieSLL *getMovList(){
        return MovList;
    }


};
