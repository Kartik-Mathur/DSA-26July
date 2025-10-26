#include <iostream>
#include <stack>
using namespace std;

void push_bottom(stack<int> &s, int topElement) {
	if (s.empty()) {
		s.push(topElement);
		return;
	}
	// Ek element mei hata leta hoon
	int top = s.top();
	s.pop();
	// Ask recursion ko vo chote stack mei topElement ko last mei insert krke dede.. Assumption
	push_bottom(s, topElement);

	// Vapis jaate time jo element humne hataya tha usse vapis daal do top par
	s.push(top);
}

void reverseStack(stack<int> &s) {
	// base case
	if (s.empty()) {
		return; // khali stack hai toh vapis jao kch nhi h reverse krne ko....
	}
	// recursive case
	int topElement = s.top();
	s.pop();
	reverseStack(s); // Remaining stack ko tu reverse karde...Assumption
	push_bottom(s, topElement);
}

void printStack(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	printStack(s);
	reverseStack(s);
	printStack(s);

	return 0;
}
















