#include <iostream>
using namespace std;

class Car {
private:
	int price;
public:
	char name[100];
	int model;


	void print() {
		cout << "Name    : " << name << endl;
		cout << "Price   : " << price << endl;
		cout << "Model   : " << model << endl << endl;
	}

	// 1. Constructor
	Car() {
		cout << "Inside Default Constructor\n";
	}
	// 2. Parameterised Constructor
	Car(char *n, int p, int m) {
		cout << "Inside Parameterised Constructor\n";
		strcpy(name, n);
		price = p;
		model = m;
	}

	// 3. Parameterised Constructor-2
	Car(int p, int m, char *n) {
		cout << "Inside Parameterised Constructor-2\n";
		strcpy(name, n);
		price = p;
		model = m;
	}

	// Copy Constructor
	// Car D = A;
	Car(Car & X) {
		cout << "Inside Copy Constructor\n";
		strcpy(name, X.name);
		price = X.price;
		model = X.model;
	}

	// Copy Assignment Operator
	// Car D;
	// D = B;
	void operator=(Car &X) {
		cout << "Inside Copy Assignment Operator\n";
		strcpy(name, X.name);
		price = X.price;
		model = X.model;
	}

	// Destructor
	~Car() {
		cout << "Deleting car " << name << endl;
	}

	// GETTER AND SETTER
	void setPrice(int p) {
		if (p >= 120 and p < 200) {
			price = p;
		}
		else {
			price = 150;
		}
	}

	int getPrice() {
		return price;
	}
};

int main() {
	Car A;

	strcpy(A.name, "BMW");
	// A.price = 10;
	A.setPrice(10);
	A.model = 2020;

	Car B( "Audi", 20, 2022);
	Car C(10, 2023, "Maruti");

	// Copy Constructor
	Car D = A; // Car D(A);
	D = B;// Copy Assignment Operator
	cout << "Price : " << A.getPrice() << endl;
	A.print();
	// B.print();
	// C.print();
	// D.print();

	return 0;
}
















