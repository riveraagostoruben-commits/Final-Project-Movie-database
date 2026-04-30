#include<iostream>
#include "GenereDLL.h"

using namespace std;
void printMenu();
int main(){ 

    int option = 0;
    GenreDLL * MoiveDataBase = new GenreDLL();
    while(option !=8){
        printMenu();
    cout<< "Enter Option: ";
    cin>> option;
    switch (option)
    {
    case 1: {



        break;
    }
        
    
    default:
        break;
    }
    }
    

    
}
void printMenu(){
    cout<< "Welcome to the Netflix Database"<< endl;
    cout << "1. Add a genre" << endl
    << "2. Add a movie" << endl 
    << "3. Modify a movie" << endl
    << "4. List all genre" << endl 
    << "5. Delete a movie"<< endl 
    << "6. List all movies for a selected genre" << endl 
    << "7. Search for a movie" << endl
    << "8. Exit"<< endl;
}