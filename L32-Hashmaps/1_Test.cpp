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

	node* search(string key) {
		int indx = hashFn(key);
		node* head = a[indx];
		while (head != NULL) {
			if (head->key == key) {
				return head;
			}

			head = head->next;
		}

		return NULL;
	}
	// Operator overloading of []
	int& operator[](string key) {
		node* ans = search(key);
		if (ans == NULL) { // Insertion
			int x = -1;
			insert(key, x);
			ans = search(key);
		}

		return ans -> value;

	}
};

int main() {

	hashmap h;
	h.insert("Mango", 100);
	h.insert("apple", 120);
	h.insert("Kiwi", 50);
	h.insert("pineapple", 50);
	h.insert("banana", 150);
	// h.print();


	h["orange"] = 100; // Insertion
	h["orange"] = 120; // Updation
	cout << h["orange"] << endl; // Search
	// h.print();

	// node* ans = h.search("Apple");
	// if (ans != NULL) {
	// 	cout << ans->key << ", " << ans->value << endl;
	// }
	// else {
	// 	cout << "NOT FOUND\n";
	// }




	return 0;
}
















