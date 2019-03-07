// MoviePortal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<map>
#include "Movie.h"
#include "Theater.h"
#include "Ticket.h"

#define MAX_CITIES 3
using namespace std;

enum CITY
{
	HYD=1,
	BLR=2,
	MAD=3
};

class MoviePortal
{
private:
	string cities[MAX_CITIES+1]={ "","hyd","blr","mad" };
	map<int, list<Movie>> cityMovieMap;
	map<int, list<Theater>> movieTheaterMap;
	void addMovie(Movie movie, CITY city, Theater theater);


public:
	string* getCities(); //will return all cities
	list<Movie> getMovies(int cityId); //input cityId , output : list of movies (using map O(1) is time complexity)
	list<Theater> getTheaters(int movieId); //input movieId , output: list of Theaters (using map O(1) is time complexity)
	
	//Below methods is to select seat 
	list<Audi> getAudis(int theaterId,int movieId); 
	void selectSeat(int row,int column);
	void removeSeat(int row, int column);

	//Do payment.
	void doPayment();


	//below method will use Ticket class to initialize and get string output
	string getTicket();
};

void MoviePortal::addMovie(Movie movie,CITY city,Theater theater) {
	if (cityMovieMap.find((int)city) == cityMovieMap.end()) {
		list<Movie> movies;
		movies.push_back(movie);
		cityMovieMap.insert(std::make_pair((int)city, movies));
	}
	else {
		cityMovieMap[(int)city].push_back(movie);
	}


	if (movieTheaterMap.find(movie.movieId) == movieTheaterMap.end()) {
		list<Theater> theaters;
		theaters.push_back(theater);
		movieTheaterMap.insert(std::make_pair(movie.movieId, theaters));
	}
	else {
		movieTheaterMap[movie.movieId].push_back(theater);
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
