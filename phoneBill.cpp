#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

//Class of Customer
class Customer{
	private:
		int monthly_fee;
	protected:
		int number_of_call;
		string name;
	public:
		Customer(){																							//default constructor
			monthly_fee = 10;
			number_of_call = 0;
			name = "";
		}
		Customer(string customer_name, int number_call){													//two-args constructor
			monthly_fee = 10;
			name = customer_name;
			number_of_call = number_call;
		}
		string getName(){																					//get name
			return name;
		}
		virtual double Compute_Bill(){																		//virtual compute bill function
			double Bill;
			Bill = monthly_fee + number_of_call*0.50;
			return Bill;
		}
};

//Class of Premium Customer and inherit base class Customer
class Premium_Customer : public Customer{
	private:
		int monthly_fee;
		int number_of_min;
	public:
		Premium_Customer(){																					//default constructor
			monthly_fee = 20;
			number_of_min = 2;
		}
		Premium_Customer(string customer_name, int number_call): Customer(customer_name, number_call){		//two-args constructor and inherit from base
			monthly_fee = 20;
			number_of_min = 2;
		}
		void setNumofMin(int minutes){																		//set number of minutes
			number_of_min = minutes;
		}
		int getNumofMin(){																					//get number of minutes
			return number_of_min;
		}
		virtual double Compute_Bill(){																		//virtual compute bill function
			double Bill;
			Bill = monthly_fee + number_of_call*0.05 + number_of_min*0.10;
			return Bill;
		}
};
int main(){
	srand(time(NULL));										//initialize random seeds
	Customer *List[6];										//Create Object array List and has 6 empty elements.
	List[0] = new Customer("John Dough", 20);				//Assign new customer John Dough and has 20 calls
	List[1] = new Customer("Bob Dough", 50);				//Assign new customer Bob Dough and has 50 calls
	List[2] = new Customer("Williams Dough", 60);			//Assign new customer Williams Dough and has 60 calls
	List[3] = new Premium_Customer("Benjamin Doe", 70);		//Assign new premium customer Benjamin Dough and has 70 calls
	List[4] = new Premium_Customer("Colin Doe", 40);		//Assign new premium customer Colin Dough and has 40 calls
	List[5] = new Premium_Customer("Jane Doe", 100);		//Assign new premium customer Jane Dough and has 100 calls
	
	for(int i = 0; i<6; i++){								//print each customer's name and their bills
		cout << "Customer: " << List[i]->getName() << " owes " << List[i]->Compute_Bill() << " dollars." << endl;
	}
	
	for(int i = 0; i<6; i++){								//delete memorys and free them
		delete List[i];
	}
	
	cout << "\n";
	//--------------------------------------------------------Bonus Part Section----------------------------------------------------
	Customer *basic_Customer,*premium_Customer;				//Create two object for basic customer and premium customer
	int mins,num = 0,basic_win = 0, premium_win = 0;
	
	//Loop Start
	for(int i = 10; i <=100; i +=10){						//For loop ten times and each time increment 10 to call number and compare them
		mins = rand()%7 + 2;								//random number from 2 to 8
		basic_Customer = new Customer("Basic Customer", i);	//Assign new Customer Basic Customer with number of calls
		premium_Customer = new Premium_Customer("Premium Customer", i);						//Assign new Customer Premium Customer with number of calls
		(static_cast<Premium_Customer*>(premium_Customer))->setNumofMin(mins);				//Set number of minutes in Premium Customer
		cout << "Number of min for current customer : " <<  (static_cast<Premium_Customer*>(premium_Customer))->getNumofMin() << endl;
		
		double basic_Bill, premium_Bill;					//create two double variables
		basic_Bill = basic_Customer->Compute_Bill();		//basic customer bill
		premium_Bill = premium_Customer->Compute_Bill();	//premium customer bill
		if (basic_Bill < premium_Bill){						//if basic customer has lower price
			cout << "Customer: " << basic_Customer->getName()<< num + 1 << " has lower price than the Premium customer "<< premium_Bill << " dollars, and the Basic customer owes " << basic_Bill << " dollars, and average savings is: " <<premium_Bill - basic_Bill << " ."<< endl;
			basic_win ++;									//increment win numbers
		}
		else if (basic_Bill > premium_Bill){				////if premium customer has lower price
			cout << "Customer: " << premium_Customer->getName()<< num + 1 << " has lower price than the Basic customer "<< basic_Bill << " dollars, and the Premium customer owes " << premium_Bill << " dollars, and average savings is: " <<basic_Bill - premium_Bill << " ."<< endl;
			premium_win++;									//increment win numbers
		}
		else {												//otherwise they are the same price
			cout << "Customer: " << premium_Customer->getName()<< num + 1 << " has the same price as the basic customer and he owes " << premium_Bill << " dollars, and the basic customer owes " << basic_Bill << " dollars."<< endl;	
		}
		delete basic_Customer;								//frees up memory
		delete premium_Customer;							//frees up memory
		num++;
	}
	//Loop End
	
	if (basic_win > premium_win) {							//if basic customer are the best
		cout << "\nYeah! The test simulate a program to compare the two plans and basic plan is the best."<< endl;
	}
	else if (premium_win > basic_win){						//if premium customer are the best
		cout << "\nYeah! The test simulate a program to compare the two plans and premium plan is the best."<< endl;
	}
	else {													//otherwise they both are the best
		cout << "\nYeah! The test simulate a program to compare the two plans and both plans are the same, for best solution purpose run this program again to count which is the best."<< endl;
	}
}
