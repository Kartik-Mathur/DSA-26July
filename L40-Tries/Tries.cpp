#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
	char ch;
	bool isEnd;
	unordered_map<char, node*> h;
	node(char c) {
		ch = c;
		isEnd = false;
	}
};

class Trie {
public:
	node* root;
	Trie() {
		root = new node('\0');
	}

	void addWord(string word) {
		node* temp = root;

		for (int i = 0; i < word.size(); ++i)
		{
			char ch = word[i];
			if (temp->h.count(ch) == 1) {
				temp = temp->h[ch];
			}
			else {
				node* n = new node(ch);
				temp->h[ch] = n;
				temp = n;
			}
		}

		temp->isEnd = true;
	}

	bool searchWord(string word) {
		node* temp = root;

		for (int i = 0; i < word.size(); ++i)
		{
			char ch = word[i];
			if (temp->h.count(ch) == 1) {
				temp = temp->h[ch];
			}
			else {
				return false;
			}
		}

		return temp->isEnd;
	}

	void autoCompleteHelper(node* t, string w) {
		if (t->isEnd) cout << w << endl;
		for (auto p : t->h) {
			autoCompleteHelper(p.second, w + p.first);
		}
	}

	void autoComplete(string w) {
		node* temp = root;

		for (int i = 0; i < w.size(); ++i)
		{
			char ch = w[i];
			if (temp->h.count(ch) == 1) {
				temp = temp->h[ch];
			}
			else {
				return;
			}
		}

		autoCompleteHelper(temp, w);
	}
};

int main() {

	Trie t;

	t.addWord("Hello");
	t.addWord("Hello World");
	t.addWord("World");
	t.addWord("Coding");
	t.addWord("Code");
	t.addWord("Coder");
	t.autoComplete("Co");
	// while (true) {
	// 	string x;
	// 	cin >> x;

	// 	if (t.searchWord(x)) {
	// 		cout << "Yes\n";
	// 	}
	// 	else {
	// 		cout << "No\n";
	// 	}
	// }


	return 0;
}
















