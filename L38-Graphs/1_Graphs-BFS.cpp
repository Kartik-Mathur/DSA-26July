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

	void SSSP(string src, string des) {
		unordered_map<string, bool> visited;
		unordered_map<string, int> dist;
		unordered_map<string, string> par;

		queue<string> q;
		visited[src] = true;
		par[src] = src;
		dist[src] = 0;

		q.push(src);

		while (!q.empty()) {
			string f = q.front();
			q.pop();

			for (auto ch : adj[f]) {
				if (!visited[ch]) {
					par[ch] = f;
					dist[ch] = dist[f] + 1;
					q.push(ch);
					visited[ch] = true;
				}
			}
		}

		cout << "Distance between " << src << " to " << des << " : " << dist[des] << endl;
		vector<string> v;
		cout << "Reverse Path: ";
		while (des != par[des]) {
			// cout << des << "<--";
			v.push_back(des);
			des = par[des];
		}
		// cout << des << endl;
		v.push_back(des);
		reverse(v.begin(), v.end());
		for (auto d : v) {
			cout << d << "-->";
		}
		cout << endl;
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

	g.SSSP("A", "F");

	return 0;
}
















