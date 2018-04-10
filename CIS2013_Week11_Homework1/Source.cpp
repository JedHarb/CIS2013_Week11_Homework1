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

	void getInput(char input) {
		switch (input) {
		case 'c':
			cout << "Set the car color: ";
			cin >> color;
			cout << "The car is now colored " << color;
			break;
		case 'm':
			cout << "Set the car make: ";
			cin >> make;
		case 'o':
			cout << "Set the car model: ";
			cin >> model;
			break;
		case 'y':
			cout << "Set the car year: ";
			cin >> year;
			break;
		case 'n':
			carOn = true;
			break;
		case 'f':
			carOn = false;
			break;
		case 'd':
			driving = true;
			break;
		case 'p':
			driving = false;
			break;
		case 'g':
			speed += 10;
			break;
		case 'b':
			speed -= 10;
			break;
		case 'l':
			turn = 'l';
			break;
		case 's':
			turn = 's';
			break;
		case 'r':
			turn = 'r';
			break;
		case 't':
			printStats();
			break;
		case 'a':
			printActions();
			break;
		default:
			cout << "nope";
		}
	}

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
		cout << "Choose an action:" << endl << "Set year (y)" << endl << "Set color (c)" << endl << "Set make (m)" << endl << "Set model (o)" << endl << "Car on (n) or off (f)" << endl << "Drive (d) or park (p)" << endl << "Give it some gas (g) or some brake (b)" << endl << "Turn or go straight (l) (s) (r)" << endl << "You can press (a) to show these actions again, (t) to show the status of the car, or (x) to exit." << endl;
	}
};

int main() {
	userCar car;
	char userInput;
	bool keepAlive = true;

	car.printStats();
	car.printActions();

	while (keepAlive == true) {
		cout << "Your action: ";
		cin >> userInput;
		if (userInput == 'x') {
			keepAlive = false;
		}
		else {
			car.getInput(userInput);
		}
	}
	return 0;
}
