#include <iostream>
#include <ctime>

using namespace std;

void print();
char map [22][22];
int main (){

	
	for(int i = 0; i < 22; i ++){
		map[0][i] = '-';
		map[21][i] = '-';
	}
	
	
	for(int i = 1; i < 21; i++){
		for(int j = 1; j< 21; j++){
			map[i][j] = ' ';
		}
	}
	
	for(int i = 1; i < 21; i ++){
		map[i][0] = '|';
		map[i][21] = '|';
	}
	print();
}

void print(){
	for(int i = 0; i < 22; i ++){
		for (int j = 0; j < 22; j++){
			cout<< map[i][j] ;
		}
		cout << endl;
	}
}
