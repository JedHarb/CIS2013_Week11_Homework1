#include <iostream>
#include <string>
using namespace std;

//Attributes
//Be sure to set defaults for each of the attribute values :
//color
//make
//model
//year
//current speed
//
//Actions
//start / stop the car
//drive the car
//turn left / right
//speed up
//slow down
//
//Limitations
//Car must be started to drive
//Car must be driving to speed up / slow down
//Car must be driving to turn
//Car cannot have a speed if off or stopped
//Car must be slowed down to stop

class userCar {
public:

	string color = "blue";
	string make = "Ford";
	string model = "Escape";
	int year = 2005;
	int speed = 0;
	bool carOn = true;
	bool driving = false;
	char turn = 's';
	bool faster = false;
	bool slower = false;

	void printStats() {
		cout << "You are in a " << year << " " << color << " " << make << " " << model << "." << endl;
	}

	void printActions() {
		cout << "Your actions are ";
	}

};

int main() {
	userCar car;
	car.printStats();


	int keepAlive = 'y';
	cin >> keepAlive;
	return 0;
}
