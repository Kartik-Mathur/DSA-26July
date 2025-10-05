#include <iostream>
using namespace std;

template<typename T>
class Vector {
public:
	T *a;
	int cs;
	int ts;
	Vector(int s = 1) {
		a = new T[s];
		ts = s;
		cs = 0;
	}

	void push_back(T d) {
		if (cs == ts) {
			T* olda = a;
			int oldts = ts;
			ts *= 2;
			a = new T[ts];
			for (int i = 0; i < oldts; ++i)
			{
				a[i] = olda[i];
			}

			delete []olda;
		}

		a[cs++] = d;
	}

	void pop_back() {
		if (cs > 0) {
			cs--;
		}
	}

	int size() {
		return cs;
	}

	int capacity() {
		return ts;
	}

	// Operator overloading
	T operator[](int idx) {
		return a[idx];
	}
};

int main() {
	Vector<int> v;
	// for (int i = 1; i <= 5; ++i)
	// {
	// 	v.push_back(i);
	// }
	char ch = 'A';
	for (int i = 1; i <= 5; ++i)
	{
		v.push_back(ch);
		ch++;
	}

	cout << "Size: " << v.size() << ", capacity : " << v.capacity() << endl;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;


	return 0;
}
















