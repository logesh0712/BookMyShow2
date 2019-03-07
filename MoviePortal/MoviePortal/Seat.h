#include<list>

using namespace std;

class Seat
{
public:
	int row;
	int column;
	
public:
	Seat(int row,int column) {
		this->row = row;
		this->column = column;
	}
};

class GoldSeat : public Seat
{
public:
	int ruppes = 300;

	GoldSeat(int row, int column):Seat(row, column) {
	
	}
};

class SilverSeat : public Seat
{
public:
	int ruppes = 150;

	SilverSeat(int row, int column) :Seat(row, column) {

	}
};