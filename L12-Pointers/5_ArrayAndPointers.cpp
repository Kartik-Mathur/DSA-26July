#include <iostream>
using namespace std;

// void print(int a[], int n) {
// Address aa raha hai toh pointer can store the address of integer bucket.
void print(int *a, int n) {

	for (int i = 0; i < n; ++i)
	{
		cout << *(a + i) << " "; // a[i]
	}
	cout << endl;

}


int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	print(a, n); // a is address of 0th index bucket

	cout << &a[3] - &a[0] << endl;



	return 0;
}
















