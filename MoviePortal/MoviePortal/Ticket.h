#include "Theater.h"
#include "Audi.h"
#include "Movie.h"
#include<string>

using namespace std;

class Ticket {
public:
	Theater *theater;
	int audiNo;
	long time;

	Ticket(Theater *theater,int audiNo,long time) {
		this->theater = theater;
		this->audiNo = audiNo;
		this->time = time;
	}

	void printTicket() {
		if (theater != NULL 
			&& theater->name.empty() == false 
			&& theater->audies.empty() == false 
			&& theater->audies.size() > 0) {
			
			list<Audi>::iterator curAudi;
			for (curAudi = theater->audies.begin(); curAudi != theater->audies.end(); curAudi++) {
				
				if (audiNo == curAudi->audiNo) {

					if (curAudi->seats.empty() == false && curAudi->movie != NULL && curAudi->movie->getMovieName().empty() == false) {
						cout << "\n" << theater->name;
						cout << "\n" << curAudi->audiNo;
						cout << "\n" << curAudi->movie->getMovieName();
						cout << "\n" << time;

						for (list<Seat>::iterator curSeat = curAudi->seats.begin(); curSeat != curAudi->seats.end(); curSeat++) {
							cout << "\n" << curSeat->row << " " << curSeat->column;
						}
					}
					break;
				}
			}

		}
	}
};