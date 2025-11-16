#include <iostream>
#include <queue> // priority_queue
using namespace std;
class cmp {
public:
	bool operator()(int a, int b) { // FUNCTOR
		return a > b;
	}
};

void printHeap(priority_queue<int, vector<int>, cmp > h) { // Pass by value, COPY Constructor call krega
	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}
	cout << endl;
}

int main() {
	priority_queue<int, vector<int> , cmp > h;
	int k = 3;
	int cs = 0;
	while (true) {
		int data;
		cin >> data;


		if (data == -1) { // Print top k elements
			printHeap(h); // We are doing via function so that mere yeh wala heap khali na ho jaaye....
		}
		else { // Logic
			if (cs == k) { // Agar mere heap mei k elements hai
				if (h.top() < data) {
					h.pop();
					h.push(data);
				}
			}
			else {
				h.push(data);
				cs++;
			}
		}
	}

	return 0;
}
















