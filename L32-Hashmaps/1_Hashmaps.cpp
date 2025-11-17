#include <iostream>
using namespace std;

class node {
public:
	string key;
	int data;
	node(string k, int d) {
		key = k;
		data = d;
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
			mul %= ts
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


};

int main() {

	hashmap h;


	return 0;
}
















