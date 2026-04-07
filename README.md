# Final-Project-Movie-Database
Instructions:
You must submit the report and source code on or before May 4th 2026.
You must design and implement a C++ project to solve the following problem.
Problem definition
Design a trivial movie database management system based on Doubly Linked List.
Your project must show the following menu:
1. Add a genre
2. Add a movie
3. Modify a movie.
4. List all genre
5. Delete a movie
6. List all movies for a selected genre
7. Search for a movie
8. Exit
Considerations
• To add a genre, your program must read the genre title (ie. Action, Comedy, Thriller, etc). Notify
the user that it was successfully added.
• To add a movie, your program must read the following:
 o Title: The title of the movie
o Genre: for the movie’s genre the program must show a list with all genres in the database
and the user shall select a genre from the list.
o Synopsis: A short summary of the movie
o Director: Director of the movie
o Cast & crew list (- 20 points if it is not implemented using BST)
o Release year: Year of publication
• To modify a movie, your program must read the title, show all information about the movie, ask if
the user really want to modify it, and for an affirmative answer, must read all the new movie
information. Notify the user that it was successfully modified.
• When listing all genres, your program must show them in alphabetical order.
• When delete a movie is chosen, the program should ask the user to enter the name of the movie
to be deleted. Next, you must delete the movie and notify the user that it was successfully deleted.
• When listing all movies for a genre, your program must read the genre and show a list with all
movies for the selected genre with the movie title, release year and director’s name.
• For searching a movie, your program must read the movie title and show all information about
the movie.
Project’s architecture
- The list of genres must be implemented using a Doubly Linked List based on genre’s title.
Each node must contain two attributes: * Genre title.
For each genre (each node) there should be a Single Linked List containing a list of movies
associated with that genre organized alphabetically by title.
Cast & Crew list must be implemented using a Binary Search Tree based on actor’s name
organized alphabetically. (20 points)
Project submission
Teams must not share design or code. Failure to comply with these requirements will result in a
grade of F in the course for the student(s) breaking these rules.
Your source code must be submitted via Blackboard on or before May 4, 2026 11:59PM. You must
submit your source code.
Rubric
70%: Project implementation
• 20%: Data structures implementation
• 40%: Functionality implementation (5% each menu function)
10%: Report
30%: Oral exam (mandatory, May 5, 2025 1:00PM)
