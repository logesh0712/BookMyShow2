#include<list>
#include"Audi.h"
using namespace std;

class Theater {
private:
	int totalAudi;
public:
	string name;
	string address;
	list<Audi> audies;

	Theater(string name, string address, int no_of_Audi) {
		this->name = name;
		this->address = address;
		this->totalAudi = no_of_Audi;

		for (int curAudi = 0; curAudi < totalAudi;curAudi++) {
			audies.push_back(*(new Audi(curAudi + 1)));
		}
	}

	void initialize(list<Movie> movies,int goldSeat,int silveSeat,list<long> showTimings) {

		list<Movie>::iterator movieItr = movies.begin();
		
		for (list<Audi>::iterator it = audies.begin(); it != audies.end() && movieItr != movies.end(); it++) {
			it->initialize(*movieItr, goldSeat, silveSeat, showTimings);
		}
	}
};
/*
void Theater::initialize(list<Movie> movies, int goldSeat, int silveSeat, list<long> showTimings) {
	
	list<Movie>::iterator movieItr=movies.begin();
	for (list<Audi>::iterator it = audies.begin(); it != audies.end() && movieItr!=movies.end(); it++) {
		
		it->initialize(&*movieItr,goldSeat, silveSeat, showTimings);
	}
}
*/