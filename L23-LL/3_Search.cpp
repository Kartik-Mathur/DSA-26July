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

// node* searchLL(node* head, int key) {
// 	if (head == NULL) {
// 		return NULL;
// 	}

// 	if (head->data == key) {
// 		return head;
// 	}

// 	node* x  = searchLL(head->next, key);
// 	if (x != NULL) {
// 		return x;
// 	}

// 	return NULL;
// }



// node* searchLL(node* head, int key) {
// 	if (head == NULL) {
// 		return NULL;
// 	}

// 	if (head->data == key) {
// 		return head;
// 	}

// 	node* x  = searchLL(head->next, key);
// 	return x;
// }


node* searchLL(node* head, int key) {
	if (head == NULL) {
		return NULL;
	}

	if (head->data == key) {
		return head;
	}

	return searchLL(head->next, key);
}

node* mergeSortedLL(node* a, node * b) {
	if (a == NULL) return b;
	if (b == NULL) return a;

	node* nH;
	if (a->data < b->data) {
		nH = a;
		nH->next = mergeLL(a->next, b);
	}
	else {
		nH = b;
		nH->next = mergeLL(a, b->next);
	}

	return nH;
}

int main() {
	node* head, *tail;
	head = tail = NULL;

	node* head1, *tail1;
	head1 = tail1 = NULL;

	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 4);
	insertAtEnd(head, tail, 6);
	insertAtEnd(head1, tail1, 2);
	insertAtEnd(head1, tail1, 6);
	insertAtEnd(head1, tail1, 7);
	insertAtEnd(head1, tail1, 8);

	node* nH = mergeSortedLL(head, head1);
	printLL(nH);


	return 0;
}




