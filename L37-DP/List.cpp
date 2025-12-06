#include <iostream>
#include <algorithm>
#include <list> // Doubly
#include <forward_list> // Singly 
using namespace std;

int main() {

	// forward_list<int> l;
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	l.push_front(5);
	l.push_front(6);
	l.push_front(7);

	// Insertion in between
	int pos = 4;
	int data = 19;
	list<int>::iterator it = l.begin();

	for (int i = 0; i < pos; ++i)
	{
		it++;
	}
	l.insert(it, data);
	l.insert(it, data);

	// We create iterators to traverse LL
	// list<int> :: iterator it;
	for (auto it = l.begin() ; it != l.end() ; it++) {
		cout << *it << "-->";
	}
	cout << endl;


	// l.remove(19); // Will delete all 19 values from LL
	// TO delete only first 19 that we will come across

	for (it = l.begin() ; it != l.end() ; it++)
	{
		if (*it == 19) {
			break;
		}
	}

	l.erase(it);

	for (auto it = l.rbegin() ; it != l.rend(); it++) {
		cout << *it << "-->";
	}
	cout << endl;

	auto x = find(l.begin(), l.end(), 5);
	if (x == l.end()) {
		cout << "Not found\n";
	}
	else {
		cout << "Found : " << *x << endl;
	}

	// FOR EACH LOOP
	for (int x : l) { // For every integer that belongs to linked list -> l
		cout << x << " --> ";
	}
	cout << endl;

	l.reverse();

	for (int x : l) { // For every integer that belongs to linked list -> l
		cout << x << " --> ";
	}
	cout << endl;




	return 0;
}
















