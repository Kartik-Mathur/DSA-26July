#include <iostream>
using namespace std;

class Car {
private:
	int price;
public:
	char name[100];
	int model;
	const int tyres;
	static int cnt;

	void print() {
		cout << "Name    : " << name << endl;
		cout << "Price   : " << price << endl;
		cout << "Model   : " << model << endl << endl;
	}

	// 1. Constructor
	Car(): tyres(4) {
		cout << "Inside Default Constructor\n";
		cnt++;
	}
	// 2. Parameterised Constructor
	Car(char *n, int p, int m): tyres(4), price(p) {
		cout << "Inside Parameterised Constructor\n";
		strcpy(name, n);
		// price = p;
		model = m;
		cnt++;
	}

	// 3. Parameterised Constructor-2
	Car(int p, int m, char *n): tyres(4) {
		cout << "Inside Parameterised Constructor-2\n";
		strcpy(name, n);
		price = p;
		model = m;
		cnt++;
	}

	// Copy Constructor
	// Car D = A;
	Car(Car & X): tyres(4) {
		cout << "Inside Copy Constructor\n";
		strcpy(name, X.name);
		price = X.price;
		model = X.model;
		cnt++;
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
		cnt--;
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

int Car::cnt = 0;


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
	cout << "Count: " << Car::cnt << endl;
	cout << "Count: " << A.cnt << endl;
	// B.print();
	// C.print();
	// D.print();

	return 0;
}
















