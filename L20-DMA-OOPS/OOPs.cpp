#include <iostream>
using namespace std;

//////////////////////////// BLUEPRINT //////////////////////////////////////////
class Car {
public:
	// data members of class Car
	char name[100];
	int model;
	int price;

	// Functions
	void print() {
		cout << "Name    : " << name << endl;
		cout << "Price   : " << price << endl;
		cout << "Model   : " << model << endl << endl;

	}
};
//////////////////////////// BLUEPRINT //////////////////////////////////////////

int main() {
	Car A;

	// A.name = "BMW";
	strcpy(A.name, "BMW");
	A.price = 10;
	A.model = 2020;

	// cout << "Name    : " << A.name << endl;
	// cout << "Price   : " << A.price << endl;
	// cout << "Model   : " << A.model << endl << endl;

	Car B;
	strcpy(B.name, "Audi");
	B.price = 20;
	B.model = 2022;
	// cout << "Name    : " << B.name << endl;
	// cout << "Price   : " << B.price << endl;
	// cout << "Model   : " << B.model << endl << endl;
	A.print();
	B.print();

	return 0;
}
















