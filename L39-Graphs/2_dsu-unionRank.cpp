#include <iostream>
#include <unordered_map>
using namespace std;

class dsu {
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;
public:
	dsu(int n) {
		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
			rank[i] = 1; // every set will rank 1 initially
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
		if (leader_u == leader_v) return;

		if (rank[leader_v] > rank[leader_u]) {
			// By chance leader_u ki rank choti hai leader_v se
			swap(leader_u, leader_v);
		}
		// Humesha leader_u ki hi rank badi hogi
		parent[leader_v] = leader_u;
		if (rank[leader_u] == rank[leader_v]) rank[leader_u]++;
	}
};

int main() {


	return 0;
}
















