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
	bool carOn = false;
	bool driving = false;
	char turn = 's';
	bool faster = false;
	bool slower = false;

	void printStats() {
		cout << "You are in a " << year << " " << color << " " << make << " " << model << "." << endl;
		if (carOn == false) {
			cout << "The car is off." << endl;
		}
		else {
			if (driving == false) {
				cout << "The car is on but you're in park.";
			}
			else {
				if (speed == 0) {
					cout << "The car is on and you are in drive, but you aren't moving.";
				}
				else {
					cout << "You are driving at " << speed << " MPH";
					if (turn == 'l') {
						cout << " while turning left.";
					}
					else if (turn == 'r') {
						cout << " while turning right.";
					}
					else {
						cout << ".";
					}
				}
			}
		}
		cout << endl;
	}

	void printActions() {
		cout << "Choose an action:" << endl << "Set year (y)" << endl << "Set color (c)" << endl << "Set make (m)" << endl << "Set model (o)" << endl << "Car on (n) or off (f)" << endl << "Drive (d) or park (p)" << endl << "Give it some gas (g) or some brake (b)" << endl << "Turn or go straight (l) (s) (r)" << endl << "You can press (a) to show these actions again or (t) to show the status of the car." << endl;
	}

};

int main() {
	userCar car;
	char input;

	car.printStats();
	car.printActions();

	//while (true) {
	//	cin >> input;
	//	if (input == 'y') {

	//	}
	//}

	int keepAlive = 'y';
	cin >> keepAlive;
	return 0;
}
