#include <iostream>
#include <cassert>
using namespace std;

class Rational {
	private:
		int num;
		int denom;
		
	public:
		//Constructors//
		Rational();
		Rational(int wholeNumber);
		Rational(int n,int d);
		//Mutators//
		void simplify();
		friend ostream& operator << (ostream& output, const Rational &obj);
		friend istream& operator >> (istream& input, Rational &obj);
		Rational operator * (Rational Right);
		Rational operator / (Rational Right);
		Rational operator + (Rational Right);
		Rational operator - (Rational Right);
		bool operator > (const Rational& Right);
		bool operator >= (const Rational& Right);
		bool operator < (const Rational& Right);
		bool operator <= (const Rational& Right);
		//Accessors//
		int GetGCD();

};
//default constructor//
Rational::Rational(){
	num = 0;
	denom = 1;
}
//one parameter constructor//
Rational::Rational(int wholeNumber){
	num = wholeNumber;
	denom = 1;
}
//two parameter constructor//
Rational::Rational(int n, int d){
	num = n;
	denom = d;
}
//simplify rational into simpest form//
void Rational::simplify(){
	if (denom < 0) {
		denom = -denom;
		num = -num;
	}
	else if (denom == 0) {
		cout << "The denominator can not be a zero!"<< endl;
		exit(0);
	}

	num /= GetGCD();
	denom /= GetGCD();
}
//calc GCD and return GCD//
int Rational::GetGCD(){
	int gcd;
	int n = num, d = denom;
	if (num < 0){
		n = -num;
		
	}
	else if (denom < 0) {
		d = -denom;
	}

	for (int i = 1; i <= n && i <= d; i ++) {
		if (n % i == 0 && d % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}
//<< operator//
ostream& operator << (ostream& output, const Rational &obj){
	if (obj.denom < 0) {
		output<< -(obj.num) << "/" << -(obj.denom)<<endl;
	}
	else {
		output<< obj.num << "/" << obj.denom << endl;
	}
	return output;
}
//>> operator//
istream& operator >> (istream& input, Rational &obj) {
	char slash;
	input >> obj.num >> slash >> obj.denom;
	obj.simplify();
}
//* operator//
Rational Rational::operator * (Rational Right) {
	Rational newRational;
	newRational.num = num* Right.num;
	newRational.denom = denom * Right.denom;
	simplify();
	return newRational;
}
// / operator//
Rational Rational::operator / (Rational Right){
	Rational newRational;
	newRational.num = num * Right.denom;
	newRational.denom = denom * Right.num;
	simplify();
	return newRational;
}
//+ operator//
Rational Rational::operator + (Rational Right){
	Rational newRational;
	newRational.num = ((num * Right.denom) + (Right.num * denom));
	newRational.denom = (denom * Right.denom);
	simplify();
	return newRational;
}
//- operator//
Rational Rational::operator - (Rational Right){
	Rational newRational;
	newRational.num = ((num * Right.denom) - (Right.num * denom));
	newRational.denom = (denom * Right.denom);
	simplify();
	return newRational;
}
//> operator//
bool Rational::operator > (const Rational& Right){
	bool result;
	if (((float)num/denom) > ((float)Right.num/Right.denom)){
		result = true;
	}
	else {
		result = false;
	}
	return result;
}
//< operator//
bool Rational::operator < (const Rational& Right){
	bool result;
	if (((float)num/denom) < ((float)Right.num/Right.denom)){
		result = true;
	}
	else {
		result = false;
	}
	return result;
}
//<= operator//
bool Rational::operator <= (const Rational& Right){
	bool result;
	if (((float)num/denom) <= ((float)Right.num/Right.denom)){
		result = true;
	}
	else {
		result = false;
	}
	return result;
}
//>= operator//
bool Rational::operator >= (const Rational& Right){
	bool result;
	if (((float)num/denom) >= ((float)Right.num/Right.denom)){
		result = true;
	}
	else {
		result = false;
	}
	return result;
}

int main () {
	//create 3 type of objs//
	Rational num1(25,5),num2,num3(15);
	cout << "Obj num 1: Current Rational is :" << num1 << "Obj num 1: Current GCD is :" << num1.GetGCD() <<endl;
	//simplify first obj//
	num1.simplify();
	cout << "Obj num 1: After simplification rational is :" << num1 <<endl;
	cout << "Obj num 2: Current Rational is :" << num2 <<"\nObj num 2: Enter Rational numbers :";
	//define a rational by user//
	cin >> num2;
	cout << "Obj num 2: Final Rational is :" << num2 << "Obj num 2: Current GCD is :" << num2.GetGCD() <<endl << endl;
	cout << "Obj num 3: Final Rational is :" << num3 << "Obj num 3: Current GCD is :" << num3.GetGCD() <<endl;
	//operation test//
	cout << "Obj num 1 * num2: " << num1*num2;
	cout << "Obj num 1 / num2: " << num1/num2;
	cout << "Obj num 1 + num2: " << num1+num2;
	cout << "Obj num 1 - num2: " << num1-num2;
	cout << "num1 > num2 Operator:" << endl;
	if (num1>num2){	
		cout << "True: Obj num1 is greater than Obj num2." << endl;
	}
	else {
		cout << "False: Obj num1 is not greater than Obj num2."  << endl;
	}
	cout << "num1 < num2 Operator:" << endl;
	if (num1<num2){
		cout << "True: Obj num1 is less than Obj num2." << endl;
	}
	else {
		cout << "False: Obj num1 is not less than Obj num2." << endl;
	}
	cout << "num1 <= num2 Operator:" << endl;
	if (num1<=num2){
		cout << "True: Obj num1 is less and equal to Obj num2." << endl;
	}
	else {
		cout << "False: Obj num1 is not less and equal to Obj num2." << endl;
	}
	cout << "num1 >= num2 Operator:" << endl;
	if (num1>=num2){
		cout << "True: Obj num1 is greater and equal to Obj num2." << endl;
	}
	else {
		cout << "False: Obj num1 is not greater and equal to Obj num2." << endl;
	}
}
