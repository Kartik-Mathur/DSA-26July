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

	void dfs(string src) {
		unordered_map<string, bool> visited;
		dfsHelper(src, visited);
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

	g.dfs("A");

	return 0;
}
















