#include <iostream>
using namespace std;

class Queue {
	int *arr;
	int n;
	int cs;
	int f, e;
public:
	Queue(int s = 5) {
		n = s;

		arr = new int[n];
		cs = 0;
		f = 0;
		e = n - 1;
	}

	void push(int d) {
		if (cs < n) {
			e = (e + 1) % n;
			arr[e] = d;
			cs++;
		}
		else {
			cout << "Overflow\n";
		}
	}

	void pop() {
		if (cs <= 0) {
			cout << "Underflow\n";
		}
		else {
			f = (f + 1) % n;
			cs--;
		}
	}

	int front() {
		return arr[f];
	}

	bool empty() {
		if (cs == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {

	Queue q(6);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}
















