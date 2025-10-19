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


void printLL(node* head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL\n";
}

// REVERSE LL
void reverseLL(node* &head, node* &tail) {
	node* c = head;
	node* p = NULL;

	while (c != NULL) {
		node* n = c->next;
		c->next = p;
		p = c;
		c = n;
	}

	swap(head, tail);
}

void reverseLLRecHelper(node* c, node* p = NULL) {
	if (c == NULL) {
		return;
	}

	node* n = c->next; // To prevent memory leak
	c->next = p;
	reverseLLRecHelper(n, c);
}

void reverseLLRec(node* &head, node* &tail) {
	reverseLLRecHelper(head);
	swap(head, tail);
}

void deleteAtFront(node* &head, node*& tail) {
	if (head == NULL) {
		return;
	}
	else if (head->next == NULL) { // ek hi node h
		delete head;
		head = tail = NULL;
	}
	else {
		node* t = head;
		head = head->next;
		delete t;
	}
}

void deleteAtEnd(node* &head, node* &tail) {
	if (head == NULL) {
		return;
	}
	else if (head->next == NULL) { // ek hi node h
		delete head;
		head = tail = NULL;
	}
	else {
		node* t = head;
		while (t->next != tail) {
			t = t->next;
		}

		delete tail;
		t->next = NULL;
		tail = t;
	}
}

void deleteAtMid(node* &head, node* &tail, int pos) {
	if (pos == 0) {
		deleteAtFront(head, tail);
	}
	else if (pos >= lengthLL(head) - 1) {
		deleteAtEnd(head, tail);
	}
	else {
		node* t = head;
		for (int i = 0; i < pos - 1; ++i)
		{
			t = t->next;
		}

		node* n = t->next;
		t->next = n->next;
		delete n;
	}
}

int main() {

	node* head, *tail;
	head = tail = NULL;

	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 5);
	insertAtEnd(head, tail, 6);
	printLL(head);


	return 0;
}




