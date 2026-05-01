#include <iostream>
#include <string>
using namespace std;

class BSTNode {
    
    private:
    BSTNode *left;
    BSTNode * right;
    string name;

    public:
    BSTNode(string nam1,BSTNode *l= nullptr, BSTNode*r = nullptr):name(nam1),left(l), right(r){}

    void setName(string n){
        name = n;
    }
    string getName(){
        return name;
    }
    void setLeft(BSTNode * l){
        left = l;
    }
    BSTNode *getLeft(){
        return left;
    }
    void setRight(BSTNode *r){
        right = r;
    }
    BSTNode *getRight(){
        return right;
    }

};

class BSTree{
    private:
    BSTNode *root;
    void visitInOrder(BSTNode *node){
        if(node!=nullptr){
            visitInOrder(node->getLeft());
            cout<< "-"<<node->getName()<< "-";
            visitInOrder(node->getRight());
        }
    }
    void destroyTree(BSTNode* node) {
    if (node != nullptr) {
        destroyTree(node->getLeft());  // Delete everything on the left
        destroyTree(node->getRight()); // Delete everything on the right
        delete node;                   // Finally, delete the current node
    }
}
    public:
    BSTree(BSTNode *r =nullptr):root(r){}
    ~BSTree(){
        destroyTree(root); 
        root = nullptr;
    }

    void Insert(string name){
        if(root ==nullptr) // if tree empty
        root = new BSTNode(name,nullptr,nullptr); // insert new root

        else{
            BSTNode * ptr = root; // pointer to the root
            BSTNode *sRoot; //trail pointer to not lose connection
            while(ptr != nullptr){
                sRoot = ptr;
                if(name < sRoot->getName()) // if name is less than the root go left
                    ptr = ptr->getLeft();
                else
                ptr = ptr->getRight(); //if name is greater than the root go right
            }
            if(name < sRoot->getName()) //insert at the left of sRoot
            sRoot->setLeft(new BSTNode(name, nullptr,nullptr));
            else
            sRoot->setRight(new BSTNode(name,nullptr,nullptr)); // insert at the right
        }
    
    }
    void PrintInOrder(){
        visitInOrder(root);
    }
   


};

class Movie

{
private:
    string Title;
    string Director;
    string Publish_Date;
    string Synopsis;
    Movie* next;
    BSTree *cast_crew;
  

public:
Movie(string t1, string d1, string dt1, string sy1, Movie *nxt = nullptr, BSTree *c_c = nullptr): Title(t1),Director(d1),Publish_Date(dt1),Synopsis(sy1),next(nxt),cast_crew(c_c){}
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
void setCastCrew(BSTree *c_c){
    cast_crew = c_c;
}
BSTree *getCastCrew(){
    return cast_crew;
}




};
