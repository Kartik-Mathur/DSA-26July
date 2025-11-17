#include <iostream>
using namespace std;

class node {
public:
	string key;
	int value;
	node* next;
	node(string k, int d) {
		key = k;
		value = d;
		next = NULL;
	}
};

class hashmap {
private:

	int hashFunction(string key) {
		int ans = 0;
		int mul = 1;
		for (int i = 0; i < key.size(); ++i)
		{
			ans += (key[i] % ts * mul % ts) % ts;
			mul *= 13;
			mul %= ts;
		}

		return ans % ts;
	}

	void rehashing() {
		node** olda = a;
		int oldts = ts;

		a = new node*[2 * ts];
		cs = 0;
		ts *= 2;
		for (int i = 0; i < ts; ++i)
		{
			a[i] = NULL;
		}

		for (int i = 0; i < oldts; ++i)
		{
			node* head = olda[i];
			while (head != NULL) {
				insert(head->key, head->value);
				node* t = head;
				head = head->next;
				delete t;
			}
		}

		delete []olda;
	}

public:
	node** a; // Dynamic memory allocation
	int ts;
	int cs;

	hashmap(int s = 5) {
		a = new node*[s];
		ts = s;
		cs = 0;

		for (int i = 0; i < ts; ++i)
		{
			a[i] = NULL; // Every bucket should have NULL in it...
		}
	}

	void insert(string key, int value) {
		int indx = hashFunction(key);

		node* n = new node(key, value);
		n->next = a[indx];
		a[indx] = n;
		cs++;

		float load_factor = cs / (ts * 1.0);
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
		int indx = hashFunction(key);
		node* head = a[indx];

		while (head != NULL) {
			if (head -> key == key) {
				return head;
			}

			head = head->next;
		}

		return NULL; // If no key was found so return NULL
	}

	int& operator[](string key) {
		node* ans = search(key);

		if (ans == NULL) { // This key is not present inside the hashtable
			insert(key, -1); // -1 is the garbage value
			ans = search(key);
		}

		// Yaha par ans bucket will have the address
		return ans->value;
	}

	void update(string key, int value) {
		node* ans = search(key);
		if (ans == NULL) {
			insert(key, value);
			ans = search(key);
		}
		ans -> value = value;
	}
	// void delete(string key){ } // HOMEWORK
};

int main() {

	hashmap h;
	h.insert("mango", 100);
	h.insert("apple", 120);
	h.insert("kiwi", 20);
	h.insert("guava", 210);
	// h.insert("orange", 22);

	h["orange"] = 22; // Insertion
	h["orange"] = 200; // Updation

	h.update("orange", 220);
	cout << h["orange"] << endl; // 200

	h.print();
	// node* ans = h.search("Orange");
	// if (ans != NULL) {
	// 	cout << ans->key << ", " << ans->value << endl;
	// }
	// else {
	// 	cout << "Key not found\n";
	// }

	return 0;
}
















