#include <iostream>
#include <unordered_map>
using namespace std;

class dsu {
	unordered_map<int, int> parent;
public:
	dsu(int n) {
		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
		}
	}

	int get(int x) {
		if (x == parent[x]) {
			return x;
		}

		return get(parent[x]);
	}

	int union_set(int u, int v) {
		int leader_u = get(u);
		int leader_v = get(v);

		parent[leader_v] = leader_u;
	}
};

int main() {


	return 0;
}
















