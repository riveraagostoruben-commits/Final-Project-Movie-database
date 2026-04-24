#include <iostream>
#include <string>
using namespace std;

class Movie

{
private:
    string Title;
    string Director;
    string Publish_Date;
    string Synopsis;
    Movie* next;
    Movie* prev;

public:
Movie(string t1, string d1, string dt1, string sy1,Movie *prv = nullptr, Movie *nxt = nullptr): Title(t1),Director(d1),Publish_Date(dt1),Synopsis(sy1), prev(prv),next(nxt){}
void setTitle(string t1){
        Title = t1;
    }

string getTitle(){
        return Title;
    }

void setDirector(string d1){
        Director = d1;
    }

string getDirector(){
        return Director;
    }

void setPublish_Date(string dt1){
        Publish_Date = dt1;
    }

string getPublish_Date(){
    return Publish_Date;
}

void setSynopsis(string sy1){
    Synopsis = sy1;
}

string getSynopsis(){
    return Synopsis;
}
void setNext(Movie *nxt){
    next = nxt;
}

Movie *getNext(){
    return next;
}

void setPrev(Movie *prv){
    prev = prv;
}

Movie *getPrev(){
    return prev;
}



};
