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

node* midLL(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	node* f = head->next;
	node* s = head;
	while (f != NULL and f->next != NULL) {
		f = f->next->next;
		s = s->next;
	}

	return s;
}

node* mergeSortedLL(node* a, node * b) {
	if (a == NULL) return b;
	if (b == NULL) return a;

	node* nH;
	if (a->data < b->data) {
		nH = a;
		nH->next = mergeSortedLL(a->next, b);
	}
	else {
		nH = b;
		nH->next = mergeSortedLL(a, b->next);
	}

	return nH;
}

node* mergeSort(node* head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	// 1. Divide
	node* a = head;
	node* m = midLL(head);
	node* b = m->next;
	m->next = NULL;

	// 2. Sort
	a = mergeSort(a);
	b = mergeSort(b);

	// 3. Merge
	node* nH = mergeSortedLL(a, b);
	return nH;
}


int main() {
	node* head, *tail;
	head = tail = NULL;


	insertAtEnd(head, tail, 10);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 6);

	printLL(head);
	head = mergeSort(head);
	printLL(head);



	return 0;
}




