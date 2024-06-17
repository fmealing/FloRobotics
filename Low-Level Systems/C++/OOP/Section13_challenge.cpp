// Movie.h
//
// Created by Florian Mealing on 17/06/2024.
//

#ifndef SECTION13CHALLENGE_MOVIE_H
#define SECTION13CHALLENGE_MOVIE_H
#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int watched;
public:
    // Constructor
    Movie(std::string name, std::string rating, int watched);

    // Getters
    std::string get_name() const;
    std::string get_rating() const;
    int get_watched() const;

    // Increment watched count
    void increment_watched();

    // Display the movie information
    void display() const;
};


#endif //SECTION13CHALLENGE_MOVIE_H

// Movie.cpp
#include "Movie.h"
#include <iostream>

Movie::Movie(std::string name, std::string rating, int watched)
    : name{name}, rating{rating}, watched{watched} {
}

std::string Movie::get_name() const { return name; }

std::string Movie::get_rating() const { return rating; }

int Movie::get_watched() const { return watched; }

void Movie::increment_watched() { ++watched; }

void Movie::display() const {
    std::cout << name << ", " << rating << ", watched " << watched << " times" << std::endl;
}

// Movies.h
#ifndef SECTION13CHALLENGE_MOVIES_H
#define SECTION13CHALLENGE_MOVIES_H

#include <vector>
#include <string>
#include "Movie.h"

class Movies {
private:
    std::vector<Movie> movies;
public:
    // Add a movie
    bool add_movie(std::string name, std::string rating, int watched);

    // Increment watched count
    bool increment_watched(std::string name);

    // Display all movies
    void display() const;
};


#endif //SECTION13CHALLENGE_MOVIES_H

// Movies.cpp
#include "Movies.h"
#include <iostream>

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie &movie: movies){
        if (movie.get_name() == name)
            return false; // Movie already exists
    }
    Movie new_movie{name, rating, watched};
    movies.push_back(new_movie);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for(Movie &movie : movies){
        if (movie.get_name() == name){
            movie.increment_watched();
            return true;
        }
    }
    return false; // Movie not found
}

void Movies::display() const {
    if (movies.empty()){
        std::cout << "Sorry, no movies to display." << std::endl;
    } else {
        for (const auto &movie: movies){
            movie.display();
        }
    }
}

// main.cpp
#include <iostream>
#include "Movies.h"

int main() {
    Movies my_movies;

    my_movies.add_movie("Big", "PG-13", 2);
    my_movies.add_movie("Star Wars", "PG", 5);
    my_movies.add_movie("Cinderella", "G", 7);

    my_movies.display();  // Display all movies

    if (!my_movies.add_movie("Cinderella", "G", 7)) {
        std::cout << "Error: Movie 'Cinderella' already exists." << std::endl;
    }

    if (my_movies.increment_watched("Big")) {
        std::cout << "Incremented watched count for 'Big'." << std::endl;
    } else {
        std::cout << "Error: Movie 'Big' not found." << std::endl;
    }

    if (!my_movies.increment_watched("Ice Age")) {
        std::cout << "Error: Movie 'Ice Age' not found." << std::endl;
    }

    my_movies.display();  // Display all movies again

    return 0;
}
