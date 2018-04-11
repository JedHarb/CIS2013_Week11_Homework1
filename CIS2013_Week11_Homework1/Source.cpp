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
			cout << "The car is now colored " << color << endl;
			break;
		case 'm':
			cout << "Set the car make: ";
			cin >> make;
			cout << "The car is now the make " << make << endl;
			break;
		case 'o':
			cout << "Set the car model: ";
			cin >> model;
			cout << "The car is now the model " << model << endl;
			break;
		case 'y':
			cout << "Set the car year: ";
			cin >> year;
			cout << "The car is now the year " << year << endl;
			break;
		case 'n':
			if (carOn == true) {
				cout << "The car is already on." << endl;
			}
			else {
				carOn = true;
				cout << "VROOM the car is now on." << endl;
			}
			break;
		case 'f':
			if (carOn == false) {
				cout << "The car is already off." << endl;
			}
			else if (driving == true) {
				cout << "You should put the car in park before turning it off." << endl;
			}
			else {
				carOn = false;
				cout << "The car is now off" << endl;
			}
			break;
		case 'd':
			if (driving == true) {
				cout << "The car is already in drive." << endl;
			}
			else if (carOn == false) {
				cout << "You can't put the car in drive if the car is off." << endl;
			}
			else {
				driving = true;
				cout << "The car is now in drive." << endl;
			}
			break;
		case 'p':
			if (driving == false) {
				cout << "The car is already in park." << endl;
			}
			else if (speed > 0) {
				cout << "You can't put the car in park while you are moving." << endl;
			}
			else {
				driving = false;
				cout << "The car is now in park." << endl;
			}
			break;
		case 'g':
			if (driving == true) {
				speed += 10;
				cout << "The car is now going " << speed << " MPH." << endl;
			}
			else {
				cout << "You tapped the gas pedal but it does nothing if you aren't in drive." << endl;
			}
			break;
		case 'b':
			if (speed < 1) {
				cout << "You tapped the brakes but you already aren't moving." << endl;
				speed = 0;
			}
			else {
				speed -= 10;
				cout << "The car is now going " << speed << " MPH." << endl;
			}
			break;
		case 'l':
		case 's':
		case 'r':
			turn = input;
			cout << "Turned the steering wheel a bit" << endl;
			break;
		case 't':
			printStats();
			break;
		case 'a':
			printActions();
			break;
		default:
			cout << "Unknown input.";
		}
	}

	void printStats() {
		cout << endl << "You are in a " << year << " " << color << " " << make << " " << model << "." << endl;
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
						cout << " driving straight ahead.";
					}
				}
			}
		}
		cout << endl;
	}

	void printActions() {
		cout << "Choose an action:" << endl << "Set year (y)" << endl << "Set color (c)" << endl << "Set make (m)" << endl << "Set model (o)" << endl << "Car on (n) or off (f)" << endl << "Drive (d) or park (p)" << endl << "Give it some gas (g) or some brake (b)" << endl << "Turn or go straight (l) (s) (r)" << endl << "Press (a) to show these actions again, (t) to show the status of the car, or (x) to exit the program." << endl;
	}
};

int main() {
	userCar car;
	char userInput;
	bool keepAlive = true;
	bool carExploded = false;

	car.printStats();
	car.printActions();

	while (keepAlive == true) {
		cout << "Your action: ";
		cin >> userInput;
		if (userInput == 'x') {
			keepAlive = false;
		}
		else if (userInput == 'e') {
			keepAlive = false;
			carExploded = true;
		}
		else {
			car.getInput(userInput);
		}
	}

	if (carExploded == true) {
		cout << "You found the self-destruct button and pushed it. The car counted down from 5 and you narrowly ran away in time. The car exploded." << endl;
	}
	while (carExploded == true) {
		cout << "Your action: ";
		cin >> userInput;
		if (userInput == 'x') {
			carExploded = false;
		}
		else {
			cout << "That's hard to do with a smouldering pile of metal." << endl;
		}
	}

	return 0;
}
