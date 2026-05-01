# Multi-Level Movie Database Management System

A C++ console application that implements a hierarchical database using **Doubly Linked Lists (DLL)** and **Singly Linked Lists (SLL)**. This project demonstrates advanced memory management and pointer manipulation to organize movie data by genre.

## 🚀 Project Overview
This system was designed to manage a "Netflix-style" database where genres are stored in an alphabetically sorted Doubly Linked List. Each genre node acts as a header for its own Singly Linked List of movies, which are also maintained in alphabetical order.

### Key Data Structures:
- **Genre List (DLL):** Allows bidirectional traversal of movie categories.
- *Movie List (SLL):** Each genre contains a unique Singly Linked List of movies.
- **Binary Search Tree (BST):** Designed for managing Cast & Crew lists for optimized searching.

## 🛠️ Features
- **Categorized Storage:** Add genres and movies into sorted positions using `sortInsert` logic.
- **CRUD Operations:** Create, Read, Update (Modify), and Delete functionality for both movies and genres.
- **Formatted Display:** List all genres or view specific movies within a selected genre.
- **Memory Management:** Custom destructors to prevent memory leaks in nested linked list structures.

## 📂 File Structure
- `Movie.h`: Movie object with attributes (Title, Director, Date, Synopsis).
- `MovieSLL.h`: Implementation of the Singly Linked List for movies.
- `GenreNode.h`: The bridge between the DLL and SLL structures.
- `GenereDLL.h`: The main database controller using a Doubly Linked List.
- `main.cpp`: The user interface and menu-driven logic.

## Open to Any Fixes/Suggestions
