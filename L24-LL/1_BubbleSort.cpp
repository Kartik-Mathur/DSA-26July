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

int lengthLL(node* head) {
	int ans = 0;
	while (head != NULL) {
		ans++;
		head = head->next;
	}
	return ans;
}


void bubbleSort(node* &head) {
	int len_N = lengthLL(head);

	for (int i = 0; i < len_N - 1; ++i)
	{
		node* p = NULL, *c = head;
		while (c != NULL and c->next != NULL) {
			node* n = c->next;

			if (c->data > n->data) {
				// swapping hogi...
				if (p == NULL) {
					// head change
					c->next = n->next;
					n->next = c;
					head = p = n;
				}
				else { // head change nhi hoga
					c->next = n->next;
					n->next = c;
					p->next = n;
					p = n;
				}
			}
			else {
				// swapping nahi hogi...
				p = c;
				c = n;
			}
		}
	}
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
	bubbleSort(head);
	printLL(head);



	return 0;
}




