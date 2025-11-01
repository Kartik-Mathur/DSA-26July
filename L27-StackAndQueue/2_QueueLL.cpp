#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

class Queue {
	// head and tail  both should be private kyunki agar yeh main mei mill gaye toh poori LL print
	// ho skti hai, jo nhi honi chahiye as it voilates queue ki property...
	node* head, *tail;
public:
	Queue() {
		head = tail = NULL;
	}

	void push(int d) {
		if (head == NULL) { // means LL mei kch nhi hai abhi toh jo add hoga whi head and whi tail
			head = tail = new node(d);
		}
		else {
			// 1. nai node banao
			node* n = new node(d);
			// 2. last mei add kro tail ke aage
			tail->next = n;
			// 3. update tail pointer it should always point to end node
			tail = n;
		}
	}

	void pop() {
		if (head == NULL) {
			return;
		}
		else if (head->next == NULL) {
			// Ek hi node bachi hai udda do and head aur tail dono garbage nhi ho skte
			// NULL kardo..
			delete head;
			head = tail = NULL;
		}
		else {
			node* t = head;
			head = head->next;
			delete t;
		}
	}

	int front() {
		return head->data;
	}

	bool empty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Queue q;
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
















