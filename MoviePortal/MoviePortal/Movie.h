
#include "pch.h"
#include <iostream>
#include<list>

using namespace std;

class Movie
{
public:
	int movieId;
	string movieName;
	list<string> casts;
	long releaseDate;

	Movie(int movieId,string movieName) {
		this->movieId = movieId;
		this->movieName = movieName;
	}

	string getMovieName() {
		return movieName;
	}

	void setCasts(list<string> casts) {
		this->casts = casts;
	}

	void setReleaseDate(long releaseDate) {
		this->releaseDate = releaseDate;
	}
};