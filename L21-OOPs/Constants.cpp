#include <iostream>
using namespace std;

class Car {
	int price;
public:
	char name[100];
	int model;
	const int tyres;

	void print() {
		cout << "Name    : " << name << endl;
		cout << "Price   : " << price << endl;
		cout << "Model   : " << model << endl << endl;
	}

	// 1. Constructor
	Car(): tyres(4) {
		cout << "Inside Default Constructor\n";
	}
	// 2. Parameterised Constructor
	Car(char *n, int p, int m): tyres(4), price(p) {
		cout << "Inside Parameterised Constructor\n";
		strcpy(name, n);
		// price = p;
		model = m;
	}

	friend ostream& operator<<(ostream& os, Car &X);
	friend istream& operator>>(istream& is, Car &X);
};

ostream& operator<<(ostream& os, Car &X) {
	cout << "Name    : " << X.name << endl;
	cout << "Price   : " << X.price << endl;
	cout << "Model   : " << X.model << endl << endl;

	return os;
}

istream& operator>>(istream& is, Car &X) {
	cout << "Enter Name: "; cin >> X.name;
	cout << "Enter Price: "; cin >> X.price;

	cout << "Enter Model: "; cin >> X.model;

	return is;
}
int main() {
	Car A;

	// strcpy(A.name, "BMW");
	// A.price = 10;
	// A.model = 2020;
	cin >> A;

	Car B( "Audi", 20, 2022);

	Car C = A;
	cout << A << endl;

	return 0;
}
















