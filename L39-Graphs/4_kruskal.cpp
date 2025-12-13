#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class dsu {
	unordered_map<int, int> parent;
	unordered_map<int, int> size;
public:
	dsu(int n) {
		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
			size[i] = 1; // every set will size 1 initially
		}
	}

	int get(int x) {
		if (x == parent[x]) {
			return x;
		}

		return parent[x] = get(parent[x]); // Path compression
	}

	void union_set(int u, int v) {
		int leader_u = get(u);
		int leader_v = get(v);
		if (size[leader_v] > size[leader_u]) {
			// By chance leader_u ki size choti hai leader_v se
			swap(leader_u, leader_v);
		}

		// Humesha leader_u ki hi size badi hogi
		parent[leader_v] = leader_u;
		size[leader_u] += size[leader_v];
	}
};

class Tuple {
public:
	int u, v, wt;
};

bool cmp(Tuple a, Tuple b) {
	return a.wt < b.wt;
}

int main() {
	// MST: Minimum Spanning Tree

	vector<Tuple> v;
	v.push_back({0, 1, 1});
	v.push_back({1, 3, 3});
	v.push_back({2, 5, 3});
	v.push_back({4, 5, 4});
	v.push_back({4, 3, 2});
	v.push_back({0, 2, 1});
	v.push_back({3, 2, 1});
	v.push_back({4, 2, 1});

	sort(v.begin(), v.end(), cmp);

	dsu d(6);

	int ans = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		Tuple t = v[i];
		int u = t.u;
		int v = t.v;
		int wt = t.wt;

		int leader_u = d.get(u);
		int leader_v = d.get(v);
		if (leader_v != leader_u) {
			ans += wt;
			d.union_set(leader_u, leader_v);
		}
	}

	cout << ans << endl;

	return 0;
}
















