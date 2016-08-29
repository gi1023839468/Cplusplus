#include <iostream>
#include <cstring>

using namespace std;

int main (){
	char *head, *tail, *cList;
	string user_In;
	
	//Get String by User//
	cout << "Enter a String: ";
	getline(cin,user_In);
	
	cList = new char [user_In.size()];		//create new array to hemp
	strcpy(cList,user_In.c_str());			//copy string into char array
	head = &cList[0];						//first char
	tail = &cList[user_In.size()- 1];		//last char
	
	char tmp;
	int i = 0;
	while(head <= tail){					//loop until finish swap process
		tmp = cList[i];						//store head to tmp
											//SWAP START//
		cList[i] = *tail;					//swap tail to head
		*tail = tmp;						//swap previous head char back to tail
											//SWAP END//
		*tail --;							//decrement tail
		*head ++;							//increment head
		i++;
	}
	cout << cList;							//print array
	delete [] cList;						//free memory
	cList = NULL;
}
