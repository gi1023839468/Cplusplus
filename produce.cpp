#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

	/*Broccoli
	Tomato
	Kiwi
	Kale
	Tomatillo
	*/
using namespace std;

class BoxOfProduce{
	//Variable//
	private:
		char item1[30];
		char item2[30];
		char item3[30];
	public:
		//Static Variable//
		int static Box_Count;
		//Constructor//
		BoxOfProduce(char *ptr1, char *ptr2, char *ptr3);
		//Mutators//
		void Output ();
		void Subsitute(int item, char *ptr);
};
	int BoxOfProduce::Box_Count = 0;
	
	//copy a char pointer to destination//
	BoxOfProduce::BoxOfProduce(char *ptr1, char *ptr2, char *ptr3){
		Box_Count ++;
		strcpy(item1,ptr1);
		strcpy(item2,ptr2);
		strcpy(item3,ptr3);
	}
	//print output//
	void BoxOfProduce::Output() {
		cout << "Contents of the box :" << endl;
		cout << "Item 1: " << item1 <<endl;
		cout << "Item 2: " << item2 <<endl;
		cout << "Item 3: " << item3 <<endl;
	}
	//replace specific item//
	void BoxOfProduce::Subsitute(int item, char *ptr) {
		if (item == 1) {
			strcpy(item1,ptr);
		}
		else if (item == 2) {
			strcpy(item2,ptr);
		}
		else {
			strcpy(item3,ptr);
		}
	}
	
	int main (){
		string y_n;
		srand(time(NULL));
		char Box_List [][20] = {"Broccoli","Tomato","Kiwi","Kale","Tomatillo"};
		//main loop(CreateOrNot)//
		do {
			//randomize//
			BoxOfProduce Box(Box_List[rand()%5],Box_List[rand()%5],Box_List[rand()%5]);
			Box.Output();
			//minor loop (replacement)//
			do {
				cout << "Do you want to subsitute any items? (y/n) :";
				cin >> y_n;
				if (y_n == "y" || y_n == "Y") {
					int index,Rep_index;
					cout << "Which item you want to subsitute? (index) :";
					cin >> index;
					for (int i = 0; i < 5; i ++) {
						cout << "Available item " << i+1 << " :" << Box_List[i] << endl;
					}
					cout << "Which item you want to replace with ? (index):";
					cin >> Rep_index;
					Box.Subsitute(index,Box_List[Rep_index - 1]);
				}
			}while(y_n != "n" && y_n != "N");
			cout << "Final Box" << endl;
			Box.Output();
			cout << "Do you want to create another box? (y/n)";
			cin >> y_n;
		}while(y_n == "y" || y_n == "Y");
		cout << "Total number of box produced: " << BoxOfProduce::Box_Count;
		return 0;
	}
