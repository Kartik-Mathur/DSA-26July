#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string &str) {
	stack<char> s;
	for (int i = 0 ; i < str.size(); i++) {
		char ch = str[i];
		switch (ch) {
		case '(':
		case '{':
		case '[':
			s.push(ch);
			break;
		case ')':
			if (!s.empty() and s.top() == '(') s.pop();
			else return false;
			break;
		case ']':
			if (!s.empty() and s.top() == '[') s.pop();
			else return false;
			break;
		case '}':
			if (!s.empty() and s.top() == '{') s.pop();
			else return false;
			break;
		}
	}

	if (s.empty()) {
		return true; // sabhi bracket sahi se open hokar close ho gaye
	}
	else {
		return false; // kch brackets close nhi ho paaye...
	}
}

int main() {

	string s = "{ a + [ b+ (c + d)] + (e + f) }";

	if (isBalanced(s)) {
		cout << "Balanced hai\n";
	}
	else {
		cout << "Not Balanced\n";
	}

	return 0;
}
















