#include <iostream>
using namespace std;

int main() {

	/*
	char a[100];
	a = "Hello World"; // Not allowed
	strcpy(a,"Hello World"); // Yeh chlega

	strcat(a,", Learning strings"); // Yeh chlega
	for (int i = 0; a[i] != '\0'; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	char x[100] = "pineapple";
	char y[100] = "zilly dragon";
	if (strcmp(x,y) == 0) {
		cout << s1 << " is greater than " << s2 << endl;
	}
	else {
		cout << s2 << " is greater than " << s1 << endl;
	}

	*/

	/*
	char a[100];
	cin.getline(a,100);
	*/

	string s; // string class ka object hai 's'
	// cin >> s;
	getline(cin, s);
	// s = "Hello World"; // This is allowed

	// cin>>s;
	s += ", Learning Strings";

	cout << s << endl;

	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	string s1 = "pineapple";
	string s2 = "zilly dragon";
	if (s1 == s2) {
		cout << s1 << " is equal to " << s2 << endl;
	}
	else if (s1 > s2) {
		cout << s1 << " is greater than " << s2 << endl;
	}
	else {
		cout << s2 << " is greater than " << s1 << endl;
	}


	char x[100] = "zillydragon";
	char y[100] = "zilly dragon";
	if (strcmp(x, y) == 0) {
		cout << x << " is equal to " << y << endl;
	}
	else if (strcmp(x, y) > 0) {
		cout << x << " is greater than " << y << endl;
	}
	else {
		cout << x << " is less than " << y << endl;
	}


	return 0;
}
















