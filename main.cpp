#include<iostream>
#include "GenereDLL.h"

using namespace std;
void printMenu();
int main(){ 
    int option;
    printMenu();
    cout<< "Enter Option: ";
    cin>> option;
    GenreDLL *
    while(option != 8){

        switch (option)
        {
        case 1:
            string GenreName;
            cout << "Input Genre Title"<< endl;
            cin >> GenreName;

             MovieSLL *newMovieSLL = new MovieSLL(GenreName);
             

            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        
        default:
            cout<< "Have a Good Day!!"; 
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