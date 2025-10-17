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

int lengthLL(node* head) {
	int ans = 0;
	while (head != NULL) {
		ans++;
		head = head->next;
	}
	return ans;
}

void insertAtFront(node* &head, node* &tail, int data) {
	if (head == NULL) {
		head = tail = new node(data);
	}
	else {
		node* n = new node(data);
		n->next = head;
		head = n;
	}
}

void insertAtEnd(node* &head, node* &tail, int data) {
	if (head == NULL) {
		head = tail = new node(data);
	}
	else {
		node* n = new node(data);
		tail->next = n;
		tail = n;
	}
}

void insertAtMid(node* &head, node* &tail, int data, int pos) {
	if (pos == 0) {
		insertAtFront(head, tail, data);
	}
	else if (pos >= lengthLL(head)) {
		insertAtEnd(head, tail, data);
	}
	else {
		node* t = head;
		for (int i = 1; i <= pos - 1; ++i)
		{
			t = t->next;
		}

		node* n = new node(data);
		n->next = t->next;
		t->next = n;
	}
}

void printLL(node* head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL\n";
}

int main() {

	node* head, *tail;
	head = tail = NULL;

	insertAtFront(head, tail, 1);
	insertAtFront(head, tail, 2);
	insertAtFront(head, tail, 3);
	insertAtFront(head, tail, 4);
	insertAtFront(head, tail, 5);
	insertAtEnd(head, tail, 6);
	insertAtEnd(head, tail, 7);

	printLL(head);
	insertAtMid(head, tail, 11, 7);
	printLL(head);


	return 0;
}




