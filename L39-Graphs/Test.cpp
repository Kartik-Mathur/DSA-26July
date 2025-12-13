#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

template<typename T>
class Graph {
public:
	map<T , list<T> > adj;

	void addEdge(T u, T v,
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

	void SSSP(T src, T des) {
		unordered_map<T, bool> visited;
		unordered_map<T, int> dist;
		unordered_map<T, T> par;

		queue<T> q;
		visited[src] = true;
		par[src] = src;
		dist[src] = 0;

		q.push(src);

		while (!q.empty()) {
			T f = q.front();
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
		vector<T> v;
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

	void snakeGame(T src, T des) {
		SSSP(src, des);
	}


};

int main() {

	Graph<int> g;

	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for (int u = 0; u <= 36; ++u)
	{
		for (int dice = 1; dice <= 6; ++dice)
		{
			int v = u + dice;
			v += board[v];

			g.addEdge(u, v, false);
		}
	}

	g.snakeGame(0, 36);

	return 0;
}
















