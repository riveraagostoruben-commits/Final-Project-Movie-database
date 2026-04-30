#include<iostream>
#include "GenereDLL.h"

using namespace std;
void printMenu();
int main(){ 

    int option = 0;
    GenreDLL * MovieDataBase = new GenreDLL();
    while(option !=8){
        printMenu();
    cout<< "\nEnter Option: ";
    cin>> option;
    switch (option)
    {
    case 1: {
        string GenreName;
        cout<< "\nInput Genre Title (No Spaces): "
        ;
        cin >> GenreName;
        cout << "\nGenre Inputed: " << GenreName << endl;

        MovieSLL * GenreMovies = new MovieSLL(GenreName); //creating the movie list for the genre
        MovieDataBase->sortInsert(GenreName, GenreMovies); // adding the genre in the GenreDLL

        cout<< "\nGenre Successfully Added"<< endl << endl;

        break;
    }
    case 2: {
       
        cout<< "\nAvailable Genres: "<< endl;
        MovieDataBase->printList();

        string SelectedGenre;
    
        cout <<"\nEnter the Genre Name to add this Movie to: "<< endl;
        cin >> SelectedGenre;

        GenreNode *Genre_Input = MovieDataBase->findGenre(SelectedGenre);// looking for the genre inputed in our GenreDLL
        
        if(Genre_Input != nullptr){
             string Title, Director, PublishDate, Synopsis;
             
             cout<< "\nEnter Movie Title:";
             cin >> Title;

               cout<< "\nEnter Movie Director:";
             cin >> Director;

               cout<< "\nEnter Movie Publish Date:";
             cin >> PublishDate;

               cout<< "\nEnter Movie Synospsis";
             cin >> Synopsis;

             Genre_Input->getMovList()->sortInsert(Title, Director, PublishDate ,Synopsis);

             cout<< "\nMovie Succesfully Added" 
             <<"\nGenre of Movie: "
             << Genre_Input->getGenre() 
             <<"\nMovie Title: "
             <<Title
             <<"\nDirector of Moie: "
             << Director
             <<"\nPublish Date of Movie: "
             << PublishDate
             <<"\nSynopsis of Movie: "
             << Synopsis<< endl << endl;


            


        }
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