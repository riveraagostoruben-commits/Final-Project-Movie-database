#include<iostream>
#include "GenereDLL.h"

using namespace std;
void printMenu();
int main(){ 

    int option = 0;
    GenreDLL * MovieDataBase = new GenreDLL();
    while(option !=8){
        printMenu();
    cout<< "Enter Option: ";
    cin>> option;
    switch (option)
    {
    case 1: {
        string GenreName = "N/A";
        cout<< "Input Genre Title (No Spaces): "
        ;
        cin >> GenreName;
        cout << "Genre Inputed: " << GenreName << endl;

        MovieSLL * GenreMovies = new MovieSLL(GenreName);
        MovieDataBase->sortInsert(GenreName, GenreMovies);

        cout<< "Genre Successfully Added"<< endl << endl;

        break;
    }
    case 2: {}
        
    
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