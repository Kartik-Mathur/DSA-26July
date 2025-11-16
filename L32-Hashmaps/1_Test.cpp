#include <iostream>
using namespace std;

class node {
public:
	int value;
	string key;
	node* next;
	node(string k, int d) {
		key	 = k;
		value = d;
		next = NULL;
	}
};

class hashmap {
	int hashFn(string key) {
		int ans = 0;
		int mul = 1;

		for (int i = 0; i < key.size(); ++i)
		{
			ans = (ans % ts + (key[i] % ts * mul % ts)) % ts;
			mul = mul * 13;
			mul %= ts;
		}

		return ans % ts;
	}

	void rehashing() {
		node** olda = a;
		int oldts = ts;

		cs = 0;
		ts = 2 * ts;
		a = new node*[ts];
		for (int i = 0; i < ts; ++i)
		{
			a[i] = NULL;
		}

		for (int i = 0; i < oldts; ++i)
		{
			node* head = olda[i];
			while (head != NULL) {
				insert(head->key, head -> value);
				node* oldhead = head;
				head = head->next;

				delete oldhead; // Yeh wale head ka data toh new table mei ho gaya insert
				// udda do isse..
			}
		}

		delete [] olda;
	}

public:
	node** a;
	int ts;
	int cs;
	hashmap(int s = 5) {
		a = new node*[s];
		ts = s;
		cs = 0;

		for (int i = 0; i < ts; ++i)
		{
			a[i] = NULL;
		}
	}

	void insert(string key, int value) {
		int indx = hashFn(key);

		node* n = new node(key, value);
		n->next = a[indx];
		a[indx] = n;
		cs++;

		float load_factor = cs / (1.0 * ts);
		if (load_factor >= 0.5) {
			rehashing();
		}
	}

	void print() {
		for (int i = 0; i < ts; ++i)
		{
			node* head = a[i];
			cout << i << " : ";
			while (head != NULL) {
				cout << "(" << head->key << ", " << head->value << ") ";
				head = head->next;
			}
			cout << endl;
		}
	}
};

int main() {

	hashmap h;
	h.insert("Mango", 100);
	h.insert("apple", 120);
	h.insert("Kiwi", 50);
	h.insert("pineapple", 50);
	h.insert("banana", 150);
	h.print();





	return 0;
}
















