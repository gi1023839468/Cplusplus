#include <iostream>

using namespace std;

class InvalidDay{																	//Exception class InvalidDay
	public:
		void prtError(){															//print Errors
			cout<< "Invalid day! Please check the day and should be 1 to 31.";
		}
};

class InvalidMonth{																	//Exception class InvalidMonth
	public:
		void prtError(){															//print Errors
			cout<< "Invalid month! Please check the month and should be 1 to 12.";
		}
};
class Date{
	private:
		int month;
		int day;
		int year;
	public:
		Date(int month, int day, int year);											//3 args constructor
		void setMonth(int month){													//set month mutator
			this->month = month; 
		}
		void setDay(int day){														//set day mutator
			this->day = day;
		}
		void setYear(int year){														//set year mutator
			this->year = year;
		}
		int getMonth(){																//get month accessor
			return month;
		}
		int getDay(){																//get day accessor
			return day;
		}
		int getYear(){																//get year accessor
			return year;
		}
		string convertMonth(int month);												//convert method proc
		void printNum(){															//print only number
			cout<< getMonth()<<"/" << getDay()<<"/"<< getYear()<<endl;
		}
		void printFormated1(){														//print MM DD, YY
			cout<< convertMonth(getMonth()) <<" "<< getDay()<<", " << getYear()<<endl;
		}
		void printFormated2(){														//print DD MM YY
			cout<< getDay()<<" "<< convertMonth(getMonth())<<" " << getYear()<<endl;
		}
};

Date::Date(int month, int day, int year){											//3 args constructor 
	if(month > 0 && month < 13){
		setMonth(month);
	}
	else{
		throw InvalidMonth();														//error occur and throw error
	}
	if(day > 0 && day < 32){
		setDay(day);
	}
	else {
		throw InvalidDay();															//error occur and throw error
	}
	setYear(year);
}
string Date::convertMonth(int month){												//convert number to months
	switch(month){
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
		default:
			return NULL;
	}
}

int main(){
	int day,month,year;
	cout<< "Enter a day:";
	cin >> day;
	cout << "Enter a month:";
	cin >> month;
	cout << "Enter a year:";
	cin >> year;
	cout << "\n";
	try{																			//try to run program
		Date date(month,day,year);													//create date object
		date.printNum();															//print number
		date.printFormated1();														//print format 1
		date.printFormated2();														//print format 2
	}catch (InvalidMonth &e){														//error catched
		e.prtError();																//print error
	}catch (InvalidDay &e){															//error catched
		e.prtError();																//print error
	}
	return 0;
}
