#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH& graph, int from, int to) {
	graph[from].push_back(to);
}

const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

void print_adjaceny_matrix(GRAPH& graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		cout << "Node " << from << " has neighbors: ";
		for (int to = 0; to < (int)graph[from].size(); ++to)
			cout << graph[from][to] << " ";
		cout << "\n";
	}
}


void dfs(GRAPH& graph, int node, vector<bool>& visited)
{
	visited[node] = true;
	for (auto neighbour : graph[node])
	{
		if (!visited[neighbour])
		{
			cout << "\tWe can reach " << neighbour << "\n";
			dfs(graph, neighbour, visited);
		}
	}

}

int counted_components(GRAPH& graph)
{
	int nodes = graph.size(),count=0;
	vector<bool>visited(nodes);
	for (int i = 0; i< nodes; i++)
	{
		if (!visited[i])
		{
			count++;
			dfs(graph, i, visited);
		}
	}
}

void reachability(GRAPH& graph)
{
	int nodes = graph.size();
	for (int i = 0; i <nodes; i++)
	{
		vector<bool>visited(nodes);
		cout << "Reachable nodes of node " << i << " are: ";
		dfs(graph, i, visited);
	}
}




int main() {

	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to;
		cin >> from >> to;
		add_directed_edge(graph, from, to);
	}
	reachability(graph);

	return 0;
}