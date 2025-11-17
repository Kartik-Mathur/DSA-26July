#include <iostream>
#include <map> // unordered_map
using namespace std;

int main() {
	// Time complexity : O(logN)
	map<string, int> h; // Data is sorted on the basis of key

	pair<string, int> p; // p.first-> string, p.second -> int
	p.first = "mango";
	p.second = 120;

	h.insert(p);
	h.insert({"apple", 100}); // Aise bhi insert kr skte hai directly
	h.insert({"guava", 200}); // Aise bhi insert kr skte hai directly
	h["orange"] = 22;
	h["pineapple"] = 22;
	h["kiwi"] = 221;
	h["papaya"] = 221;
	h["grapes"] = 221;
	h["dragonfruit"] = 221;
	h["chiku"] = 221;
	h["melon"] = 221;
	h["banana"] = 221;

	// FOR EACH LOOP
	// for (pair<string, int> x : h) { // for every pair x that belongs to hashmap h
	for (auto x : h) {
		cout << x.first << ", " << x.second << endl;
	}



	return 0;
}
















