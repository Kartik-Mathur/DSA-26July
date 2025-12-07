#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

class Graph {
public:
	map<string , list<string> > adj;

	void addEdge(string u, string v,
	             bool bidir = true) {
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

	void bfs(string src) {
		unordered_map<string, bool> visited;
		queue<string> q;

		visited[src] = true;

		q.push(src);

		while (!q.empty()) {
			string f = q.front();
			q.pop();

			cout << f << " ";

			for (auto ch : adj[f]) {
				if (!visited[ch]) {
					q.push(ch);
					visited[ch] = true;
				}
			}
		}

		cout << endl;
	}
};

int main() {

	Graph g;
	g.addEdge("Modi", "Trump", true);
	g.addEdge( "Modi", "Yogi", true);

	g.addEdge( "Yogi", "Prabhu", false);
	g.addEdge("Prabhu", "Modi", false);
	g.addEdge("Putin", "Modi", false);
	g.addEdge("Putin", "Trump", false);
	g.addEdge("Putin", "Pope", false);

	g.print();

	return 0;
}
















