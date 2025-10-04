#include <iostream>
using namespace std;

char keys[][10] = {
	"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};

void phoneKeypad(char *ip, char *op, int i, int j) {
	if (ip[i] == '\0') {
		op[j] = '\0';
		cout << op << endl;
		return;
	}

	int digit = ip[i] - '0';
	for (int k = 0; keys[digit][k] != '\0'; ++k)
	{
		op[j] = keys[digit][k];
		phoneKeypad(ip, op, i + 1, j + 1);
	}
}

int main() {

	char a[100];
	cin >> a;
	char op[100];
	phoneKeypad(a, op, 0, 0);

	// cout << keys[digit] << endl;
	// for (int i = 0; keys[digit][i] != '\0'; ++i)
	// {
	// 	cout << keys[digit][i] << "-";
	// }

	return 0;
}
















