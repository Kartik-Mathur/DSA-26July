#include <iostream>
using namespace std;

void updateData(int *a) {
	*a = *a + 1;
	a = NULL;
}
int main() {
	int x = 1;
	int *xp = &x;
	updateData(xp);

	cout << x << endl;


	return 0;
}
















