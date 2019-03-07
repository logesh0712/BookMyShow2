#include<list>
#include "Seat.h"
#include "Movie.h"

using namespace std;

class Audi
{
public:
	int audiNo;
	Movie *movie;
	
	//list<Seat> seats;
	//list<long> showTimes;

	map<long, list<Seat>> timeSeatsMap;

	Audi(int audiNo) 
	{
		this->audiNo = audiNo;
	}

	void initialize(Movie movie, int maxGoldSeat, int maxSilverSeat, list<long> showTimes) {
		this->movie = &movie;

		for (list<long>::iterator curTime = showTimes.begin(); curTime != showTimes.end(); curTime++) {
			list<Seat> seat = createSeats(maxGoldSeat, maxSilverSeat);

			timeSeatsMap.insert(pair<long, list<Seat>>(*curTime, seat));
		}
	}

private:
	list<Seat> createSeats(int totalGoldSeat, int totalSilverSeat);
};

list<Seat> Audi::createSeats(int totalGoldSeat,int totalSilverSeat) {
	int curSeat = 0;
	int totalSeat = totalGoldSeat + totalSilverSeat;
	list<Seat> seats;

	for (int row = 0; row < totalSeat; row++) {
		for (int column = 0; column < 10; column++) {
			
			if (curSeat == totalSeat) {
				break;
			}

			Seat *seat;
			if (curSeat < totalGoldSeat) {
				seat = new GoldSeat(row, column);
			}
			else {
				seat = new SilverSeat(row, column);
			}
				
			seats.push_back(*seat);
		}

		if (curSeat == totalSeat) {
			break;
		}
	}
	
	return seats;
}
/*
//void Audi::initialize(Movie *movie, int maxGoldSeat, int maxSilverSeat, list<long> showTimes) {
void Audi::initialize(Movie *movie, int maxGoldSeat, int maxSilverSeat, list<long> showTimes){
	this->movie = movie;

	for (list<long>::iterator curTime = showTimes.begin(); curTime != showTimes.end(); curTime++) {
		list<Seat> seat = createSeats(maxGoldSeat,maxSilverSeat);

		timeSeatsMap.insert(pair<long,list<Seat>> (*curTime, seat));
	}
}
*/