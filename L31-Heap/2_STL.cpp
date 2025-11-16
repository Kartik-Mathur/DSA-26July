#include <iostream>
#include <queue> // priority_queue
using namespace std;

class cmp {
public:
	bool operator()(int a, int b) { // FUNCTOR
		return a > b;
	}
};

int main() {
	// priority_queue<int> h; // Maxheap
	priority_queue<int, vector<int> , cmp > h;

	h.push(5);
	h.push(2);
	h.push(1);
	h.push(3);
	h.push(4);

	// Heap Sort
	while (!h.empty()) {
		cout << h.top() << endl;
		h.pop();
	}

	return 0;
}
















