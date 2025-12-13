#include <iostream>
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

		return get(parent[x]);
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

int main() {


	return 0;
}
















