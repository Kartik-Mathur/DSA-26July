#include <iostream>
#include <unordered_map> // unordered_map
using namespace std;

int main() {
	auto a = 1.11;
	// auto t; // Cannot be done
	unordered_map<string, int> h; // O(1) in average time

	pair<string, int> p; // p.first-> string, p.second -> int
	p.first = "Mango";
	p.second = 120;

	h.insert(p);
	h.insert({"Apple", 100}); // Aise bhi insert kr skte hai directly
	h.insert({"Guava", 200}); // Aise bhi insert kr skte hai directly
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


	// ISSE YAAD KARO ABHI AAGE WALI CLASSES MEI SAMJH AA JAEGA
	for (int i = 0; i < h.bucket_count(); ++i)
	{
		cout << i << ": ";
		for (auto it = h.begin(i) ; it != h.end(i) ; it++) {
			cout << "(" << it->first << ", " << it->second << ") ";
		}

		cout << endl;
	}




	return 0;
}
















