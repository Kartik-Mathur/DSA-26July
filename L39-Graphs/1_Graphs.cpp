#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

class Graph {
public:
	map<string, list< pair<string, int> > > adj;

	void addEdge(string u, string v, int d, bool bidir = true) {
		adj[u].push_back({v, d});
		if (bidir == true) {
			adj[v].push_back({u, d});
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " : ";
			for (auto cp : p.second) {
				cout << "(" << cp.first << ", " << cp.second << ") ";
			}
			cout << endl;
		}
	}

	void dijkstras(string src, string des) {
		unordered_map<string, int> dist;
		unordered_map<string, string> parent;

		for (auto p : adj) {
			dist[p.first] = INT_MAX;
		}

		dist[src] = 0;
		parent[src] = src;

		set<pair<int, string> > s;
		s.insert({0, src});

		while (!s.empty()) {
			auto p = *(s.begin());
			s.erase(s.begin());

			int cd = p.first;
			string x = p.second;
			for (auto cp : adj[x]) {
				string neigh = cp.first;
				int ed = cp.second;

				if (dist[neigh] > cd + ed) {
					auto t = s.find({dist[neigh], neigh});
					if (t != s.end()) {
						s.erase(t);
					}

					s.insert({cd + ed, neigh});
					parent[neigh] = x;
					dist[neigh] = cd + ed;
				}
			}
		}
		cout << "Distance from " << src << " to " << des << " : " << dist[des] << endl;
		while (des != parent[des]) {
			cout << des << " ";
			des = parent[des];
		}
		cout << des << endl;

	}
};

int main() {

	Graph g;

	g.addEdge("A", "B", 1);
	g.addEdge("D", "B", 2);
	g.addEdge("D", "C", 3);
	g.addEdge("A", "C", 10);
	g.addEdge("A", "D", 8);

	// g.print();
	g.dijkstras("A", "C");

	return 0;
}














