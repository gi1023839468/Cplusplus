#include <iostream>

using namespace std;

//Base Ship Class
class Ship{
	private:
		string name;
		int year;
	public:
		//constructor//
		Ship();
		Ship(string names, int years);
		//mutator//
		void setName(string names);
		void setYear(int years);
		virtual void Display(){
			cout << "Ship's name: " << getName() << " and year: " << getYear() << endl;
		}
		//Accessor//
		string getName();
		int getYear();
		
};

Ship::Ship(){
	name = "";
	year = 0;
}
Ship::Ship(string names, int years){
	name = names;
	year = years;
}

void Ship::setName(string names){
	name = names;
}
void Ship::setYear(int years){
	year = years;
}

string Ship::getName(){
	return name;
}

int Ship::getYear(){
	return year;
}

//Cruise Ship Class
class CruiseShip : public Ship {
	private:
		int max;
	public:
		//constructor//
		CruiseShip();
		CruiseShip(int num);
		//mutator//
		void setMax(int num);
		virtual void Display(){
			cout << "Ship's name: " << Ship::getName() << " and year: " << Ship::getYear() << " and maximum number of passengers: " << max <<endl;
		}
};
CruiseShip::CruiseShip(){
	max = 0;
}
CruiseShip::CruiseShip(int num){
	max = num;
}
void CruiseShip::setMax(int num){
	max = num;
}

//Cargo Ship Class
class CargoShip : public Ship {
	private:
		int capacity;
	public:
		//constructor//
		CargoShip();
		CargoShip(int num);
		//mutator//
		void setCap(int num);
		virtual void Display(){
			cout << "Ship's name: " << Ship::getName() << " and year: " << Ship::getYear()  << " and the ship's cargo capacity: " << capacity<<endl;
		}
};
CargoShip::CargoShip(){
	capacity = 0;
}
CargoShip::CargoShip(int num){
	capacity = num;
}
void CargoShip::setCap(int num) {
	capacity = num;
}

int main (){
	//set name and year
	cout << "This should display beetle and tiger and their year." << endl;
	CargoShip cargo(5);
	CruiseShip cruise(6);
	Ship *boat1 = &cargo;
	Ship *boat2 = &cruise;
	boat1->setName("Beetle");
	boat1->setYear(1994);
	boat2->setName("Tiger");
	boat2->setYear(2015);
	boat1->Display();			//print overwrite information
	boat2->Display();			//print overwrite information
	
	//default class
	cout << "\nThis should display default class from constructor." << endl;
	Ship Boat3;
	Ship Boat4("Fisher",1998);
	Boat3.Display();			//Print default Base Class
	Boat4.Display();			//Print default Base Class
	
	//User define
	cout << "\nThis should display information by user input." << endl;
	CargoShip yourCargo;
	CruiseShip yourCruise;
	string user_InName;
	int user_InYear,numbers;
	cout << "Please define Cargoship's name: ";
	getline(cin,user_InName);
	yourCargo.setName(user_InName);
	cout << "Your Cargoship called: " << yourCargo.getName() << endl;
	cout << "Please define its year: ";
	cin >> user_InYear;
	yourCargo.setYear(user_InYear);
	cout << "Your Cargoship's year is: " << yourCargo.getYear() << endl;
	cout << "Define its capacity: ";
	cin >> numbers;
	yourCargo.setCap(numbers);
	cin.ignore();
	
	cout << "\nPlease define CruiseShip's name: ";
	getline(cin,user_InName);
	yourCruise.setName(user_InName);
	cout << "Your CruiseShip called: " << yourCruise.getName() << endl;
	cout << "Please define its year: ";
	cin >> user_InYear;
	yourCruise.setYear(user_InYear);
	cout << "Your CruiseShip's year is: " << yourCruise.getYear() << endl;
	cout << "Define its max of passengers: ";
	cin >> numbers;
	yourCruise.setMax(numbers);
	cout << endl << endl;
	cin.ignore();
	
	Ship *ucargo,*ucruise;
	ucargo = &yourCargo;
	ucruise = &yourCruise;
	ucargo->Display();			//Print overwrite information
	ucruise->Display();			//Print overwrite information
	
}
