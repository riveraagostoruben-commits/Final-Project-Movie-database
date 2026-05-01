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
                cout << "\nAvailable Genres: " << endl;
                MovieDataBase->printList();

                string SelectedGenre;
                cout << "\nEnter the Genre Name to add this Movie to: ";
                cin >> SelectedGenre;

                GenreNode* Genre_Input = MovieDataBase->findGenre(SelectedGenre);

                if (Genre_Input != nullptr) {
                    string Title, Director, PublishDate, Synopsis;
                    cout << "\nEnter Movie Title: ";
                    cin >> Title;
                    cout << "\nEnter Movie Director: ";
                    cin >> Director;
                    cout << "\nEnter Movie Publish Date: ";
                    cin >> PublishDate;
                    cout << "\nEnter Movie Synopsis: ";
                    cin >> Synopsis;

                    
                    BSTree* MovieCast = new BSTree();
                    int count;
                    cout << "Enter how many cast/crew members: "; // fix print out
                    cin >> count;

                    for (int i = 0; i < count; i++) {
                        string name;
                        cout << "Enter name " << i + 1 << " (No Spaces): "; //fix print out
                        cin >> name;
                        MovieCast->Insert(name);
                    }

                    Genre_Input->getMovList()->sortInsert(Title, Director, PublishDate, Synopsis, MovieCast);
                    cout << "\nMovie Successfully Added!" << endl << endl;
                } else {
                    cout << "\nGenre not found!" << endl;
                }
                break;
            } 
    case 3:{// have to add printout of cast and crew
        string SelectedGenre;
        cout<< "\nAvailable Genres: "<< endl;
        MovieDataBase->printList();
    
        cout<< "\nPlease Insert The Genre of the Movie: ";
        cin >> SelectedGenre;
         GenreNode *GenreInput = MovieDataBase->findGenre(SelectedGenre);
        if(GenreInput == nullptr){
            cout<< "\nGenre Not Found" << endl<< endl;
            break;
        }
        else{
            string MovSearch;
            cout<< "\nGenre: "<< endl << "|" <<SelectedGenre << "|" << endl;
            GenreInput->getMovList()->printList();
            cout<<endl;
            cout<< "\nPlease Insert Movie Name: ";
            cin>> MovSearch;

           Movie* MovInputed = GenreInput->getMovList()->findMovieByTitle(MovSearch);
           if(MovInputed != nullptr){
            string choice;
            cout << "\nMovie Found" << endl;
            cout<< "\nMovie Info:"<<endl;
            cout<< "\nTitle: " << MovInputed->getTitle()<< endl;
            cout<< "Director: " << MovInputed->getDirector()<< endl;
            cout<< "Pubish Date: " << MovInputed->getPublish_Date()<< endl;
            cout<< "Synopsis: " << MovInputed->getSynopsis()<< endl<< endl;

            cout<< "\nAre you sure you want to Modify the Movie: (Y/N)";
            cin>> choice;
            if(choice != "Y"){
                cout<< "\nReturning to Start of Program..."<<endl << endl;
                break;
            }
            else{
                string d, p, s;
                cout << "New Director: ";
                cin >> d;
                cout << "New Date: "; 
                cin >> p;
                cout << "New Synopsis: "; 
                 cin >> s;

                MovInputed->setDirector(d);
                MovInputed->setPublish_Date(p);
                MovInputed->setSynopsis(s);
    
                cout << "\nMovie Modified" << endl<< endl;
            }

            break;
           }
           else{
            cout<<"\nMovie Not Found"<<endl<< endl;
            break;
           }

    }
}
    case 4:{
        
        if(MovieDataBase->isEmpty() != true){
        cout << "\nListing all Genres:"<< endl;
        MovieDataBase->printList();
        cout<< endl;
        break;
        }

            cout << "\nNo Genres have been Added"<< endl<< endl;
            break;
    }
    case 5:{
         cout<< "\nAvailable Genres: "<< endl;
        MovieDataBase->printList();

        string SelectedGenre;
    
        cout <<"\nEnter the Genre of the Movie You want to delete: "<< endl;
        cin >> SelectedGenre;

        GenreNode *GenreInput = MovieDataBase->findGenre(SelectedGenre);// looking for the genre inputed in our GenreDLL
        if(GenreInput == nullptr){
            cout<< "\nGenre Not Found" << endl<< endl;
            break;
        }
        else{
            string MovSearch;
            string MovCheck;
            cout<< "\nGenre: "<< endl << "|" <<SelectedGenre << "|" << endl;
            GenreInput->getMovList()->printList();
            cout<<endl;
            cout<< "\nPlease Insert Movie Name: ";
            cin>> MovSearch;

            Movie *Moviedel = GenreInput->getMovList()->findMovieByTitle(MovSearch);
            if(Moviedel == nullptr){
                cout << "\nMovie Not Found" << endl;
                break;
            }
            
            cout<< "\nMovie |" << MovSearch<< "| Found"<< endl;
            cout<< "Please enter Movie Name again to delete: ";
            cin>> MovCheck;

                if(MovSearch == MovCheck){
                    GenreInput->getMovList()->deleteMovie(MovSearch);
                    cout << "\n" << "Movie Successfully deleted" << endl << endl;
                    break;
                }
                else{
                    cout<< "\nInvalid Input"<<endl;
                    break;
                }

            

            
    
    }
}
    case 6:{ // list all movies for selected genre
        string SelectedGenre;
        cout<< "\nAvailable Genres: "<< endl;
        MovieDataBase->printList();
    
        cout<< "\nPlease Insert The Genre: ";
        cin >> SelectedGenre;

        GenreNode *GenreInput = MovieDataBase->findGenre(SelectedGenre);
        if(GenreInput == nullptr){
            cout<< "\nGenre Not Found" << endl<< endl;
            break;
        }
        else{
            cout<< "\nGenre: "<<endl<< "|"<<SelectedGenre << "|" << endl;
            GenreInput->getMovList()->printList();
            cout<< endl; 
            break;   
        }   
    }
    case 7:{
        string SelectedGenre;
        cout<< "\nAvailable Genres: "<< endl;
        MovieDataBase->printList();
    
        cout<< "\nPlease Insert The Genre of the Movie: ";
        cin >> SelectedGenre;
         GenreNode *GenreInput = MovieDataBase->findGenre(SelectedGenre);
        if(GenreInput == nullptr){
            cout<< "\nGenre Not Found" << endl<< endl;
            break;
        }
        else{
            string MovSearch;
            cout<< "\nGenre: "<< endl << "|" <<SelectedGenre << "|" << endl;
            GenreInput->getMovList()->printList();
            cout<<endl;
            cout<< "\nPlease Insert Movie Name: ";
            cin>> MovSearch;

           Movie* MovInputed = GenreInput->getMovList()->findMovieByTitle(MovSearch);
           if(MovInputed != nullptr){
            cout << "\nMovie Found" << endl;
            cout<< "\nMovie Info:";
            cout<< "\nTitle: " << MovInputed->getTitle()<< endl;
            cout<< "Director: " << MovInputed->getDirector()<< endl;
            cout<< "Pubish Date: " << MovInputed->getPublish_Date()<< endl;
            cout<< "Synopsis: " << MovInputed->getSynopsis()<< endl;

            cout<< "Cast & Crew";
            MovInputed->getCastCrew()->PrintInOrder(); // Fix print out
            break;
           }
           else{
            cout<<"\nMovie Not Found"<<endl<< endl;
            break;
           }

           
        }   
        

    }
    case 8: 
    cout<< "\nHave a Good Day!"<< endl;
    break;
    

        
    
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