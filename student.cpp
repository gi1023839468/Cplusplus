#include <iostream>
#include <cstring>

using namespace std;

class Student {
	private:
		string name;
		int numClass;
		string *classList;
	public:
		//Constructor//
		Student ();
		//Destructor//
		~Student ();
		//mutators//
		void setName (string studentName);
		void setClassNum (int num);
		void setClassList ();
		void resetClass();
		void User_Input();
		void User_Output();
		Student& operator = (const Student &source);
		//accessors//
		string getName ();
		int getClassNum ();
		string getClassList (int index);	
	};
	//destructor//
	Student::~Student(){
		delete  [] classList;
	}
	//reset class//
	void Student::resetClass() {
		delete  [] classList;
		classList = NULL;
		numClass = 0;
	}
	//constructor
	Student::Student(){
		resetClass();
		name = "";
	}
	//= operator//
	Student& Student::operator = (const Student &source) {
		name = source.name;
		numClass = source.numClass;
		classList = new (nothrow) string [numClass];
		for (int i =0 ; i < numClass; i ++) {
			classList[i] = source.classList[i];
		}
		return *this;
	}
	
	//set name//
	void Student::setName(string studentName) {
		name = studentName;
	}
	//get name//
	string Student::getName(){return name;}
	//set class number//
	void Student::setClassNum(int num){
		numClass = num;
	}
	//get class number//
	int Student::getClassNum(){return numClass;}
	void Student::setClassList(){
		classList = new string [numClass];
		for (int i = 0; i < numClass; i++) {
			cout << "Enter your class " << (i + 1) << " :";
			getline(cin,classList[i]);
		}
	}
	//get class list//
	string Student::getClassList(int index){return classList[index];}
	//user input//
	void Student::User_Input(){
		string User_name,Class_name,User_y_n;
		int User_num;
		do {
			if (name != "" && numClass > 0) {
				Student::setClassList();
			}
			else {
				cout<<"What's your name? : ";
				cin >> User_name;
				Student::setName(User_name);
				cout <<"Please, enter how many class you currently have? :" ;
				cin >> User_num;
				Student::setClassNum(User_num);
				cin.ignore();
				Student::setClassList();
			}
			cout << "Do you want to enter data again? (y/n) :";
			cin >> User_y_n;
			if (User_y_n == "y") {
				resetClass();
				name = "";
			}
		}while (User_y_n == "y" || User_y_n == "Y");


	}
	//print output//
	void Student::User_Output() {
		cout << "Your name is :" << Student::getName() << endl;
		cout << "You have " << Student::getClassNum() << " classes." << endl;
		for (int i = 0; i < Student::numClass; i++) {
			cout << "You have class " << (i + 1) << " :"<< Student::getClassList(i)<< endl;
		}
	}
	int main () {
		Student Obj,Obj2;
		cout << "Obj1 user input:"<<endl;
		Obj.User_Input();
		cout << "Obj1 output:"<<endl;
		Obj.User_Output();
		cout << "\nObj1 assign to Obj2"<<endl;
		Obj2 = Obj;
		cout << "Obj2 output:"<<endl;
		Obj2.User_Output();
		cout << "\nReset Obj1 class."<<endl;
		Obj.resetClass();
		cout << "Obj1 output and should be empty."<<endl;
		Obj.User_Output();
		cout << "\nObj2 output:"<<endl;
		Obj2.User_Output();	
		return 0;
	}
