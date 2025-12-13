#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

class Graph {
public:
	map<string , list<string> > adj;

	void addEdge(string u, string v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir) {
			adj[v].push_back(u);
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " : ";
			for (auto ch : p.second) {
				cout << ch << " ";
			}
			cout << endl;
		}
	}

	void dfsHelper(string src, unordered_map<string, bool> &visited) {
		cout << src << " ";
		visited[src] = true;

		for (auto ch : adj[src]) {
			if (!visited[ch]) {
				dfsHelper(ch, visited);
			}
		}
	}

	void componentsCount() {
		unordered_map<string, bool> visited;
		int component = 0;
		for (auto p : adj) {
			if (!visited[p.first]) {
				component++;
				// cout << "Component " << component << " : ";
				dfsHelper(p.first, visited);
				// cout << endl;
			}
		}

		cout << "\nTotal components: " << component << endl;
	}
};

int main() {

	Graph g;

	g.addEdge("D", "B");
	g.addEdge("D", "C");
	g.addEdge("A", "B");
	g.addEdge("A", "C");
	g.addEdge("E", "C");
	g.addEdge("E", "D");
	g.addEdge("E", "F");
	g.addEdge("G", "H");
	g.addEdge("I", "K");

	g.componentsCount();

	return 0;
}
















