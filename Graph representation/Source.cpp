#include<iostream>
#include<vector>

using namespace std;

/* adjacency matrix codes
typedef vector<vector<int>>GRAPH;

void add_directed_edge_matrix(GRAPH& graph, int from, int to, int cost)
{
	graph[from][to] = cost;
}

void add_undirected_edge_matrix(GRAPH& graph, int from, int to,int cost)
{
	graph[from][to] = cost;
	graph[to][from] = cost;
}

void print_adjaceny_matrix(GRAPH& graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		for (int to = 0; to < nodes; ++to) {
			if (graph[from][to] > 0)
				cout << "From " << from << " to " << to
				<< " the cost is " << graph[from][to] << " \n";
		}
	}
}*/

/*
edge list code 

struct edge {
	int from, to, weight;

	edge(int from, int to, int weight): from(from), to(to), weight(weight) {}

	bool operator < (const edge & e) const {
		return weight < e.weight;
	}

	void print() {
		cout<<"Edge ("<<from<<" "<<to<<" "<<weight<<")\n";
	}
};

typedef vector<edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost) {
	graph.push_back({from, to, cost});
}

void print_adjaceny_matrix(GRAPH &graph) {
	for (int edge = 0; edge < (int)graph.size(); ++edge)
		graph[edge].print();
}


*/


/*
Hash set representation code

typedef vector<unordered_set<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to) {
	graph[from].insert(to);
}

void add_undirected_edge(GRAPH &graph, int from, int to) {
	graph[from].insert(to);
	graph[to].insert(from);
}

void print_adjaceny_matrix(GRAPH &graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		cout << "Node " << from << " has neighbors: ";
		for(int to : graph[from])
			cout << to << " ";
		cout << "\n";
	}
}

	*/


/*
Airport problem

struct Edge {
	string to;
	int weight;

	bool operator < (const Edge & e) const {
		if (to != e.to)
			return to < e.to;
		return weight < e.weight;
	}
};

typedef map<string, multiset<Edge>> GRAPH;

void add_directed_edge(GRAPH &graph, string from, string to, int cost) {
	graph[from].insert({to, cost});
}

void print_adjaceny_matrix(GRAPH &graph) {

	for(auto node : graph) {
		cout << "Flights from " << node.first<<": \n";
		for(const Edge &edge : node.second)
			cout<<"\tTo "<<edge.to<<" with cost "<<edge.weight<<"\n";
	}
}

*/

struct edge {
	int to;
	int cost;
};

typedef vector<vector<edge>>GRAPH;

void add_directed_edge_list(GRAPH& graph, int from, int to,int cost)
{
	graph[from].push_back({ to,cost });
}

void add_undirected_edge_list(GRAPH& graph, int from, int to, int cost)
{
	graph[from].push_back({ to,cost });
	graph[to].push_back({ from,cost });
}

void print_adjaceny_list(GRAPH& graph) {
	int nodes = graph.size();
	for (int from = 0; from < nodes; ++from) {
		cout << "Node " << from << " has neighbors: ";
		for (int edge = 0; edge < (int)graph[from].size(); ++edge)
			cout << "(to " << graph[from][edge].to
			<< " cost " << graph[from][edge].cost << ") ";
		cout << "\n";
	}
}

// true if this location inside the matrix-->for image as graph problem
bool isValid(int nr, int nc, int rows, int cols) {
	if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
		return false;
	return true;
}

void print_chain(GRAPH& graph, int from)
{
	cout << graph[from][0].to << ' ';

	if (graph[from].empty())
		return;

	else
		print_chain(graph, graph[from][0].to);
	
}

void print_paths_len2(GRAPH& graph)
{
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (graph[j].size())
			{
				for (int k = 0; k < graph[j].size(); k++)
				{
					cout << i << ' ' << graph[i][j].to <<' '<< graph[j][k].to << endl;
				}
			}
		}
	}
}

int main() {

	/*adjacency matrix codes
	* 
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes, vector<int>(nodes)); in every slot make an array of zeros

	for (int e = 0; e < edges; ++e) {
		int from, to, cost;
		cin >> from >> to >> cost;
		add_undirected_edge(graph, from, to, cost);
	}
	print_edge_list(graph);

	*/


	/*
	edge list code

		int edges;
	cin >> edges;

	GRAPH graph;

	for (int e = 0; e < edges; ++e) {
		int from, to, cost;
		cin >> from >> to >> cost;
		add_edge(graph, from, to, cost);
	}
	sort(graph.begin(), graph.end());
	print_edge_list(graph);

	*/


	/*
	Hash set representation code
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to;
		cin >> from >> to;
		add_directed_edge(graph, from, to);
	}
	print_adjaceny_matrix(graph);
	*/


	/*
	image as graph problem code

	int rows, cols;

	cin >> rows >> cols;

	GRAPH graph(rows * cols);	// observe: empty lists

	int nr, nc, to;
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			int from = r * cols + c;

			nr = r + 1, nc = c, to = nr * cols + nc;
			if (isValid(nr, nc, rows, cols))
				add_directed_edge(graph, from, to);

			nr = r - 1, nc = c, to = nr * cols + nc;
			if (isValid(nr, nc, rows, cols))
				add_directed_edge(graph, from, to);

			nr = r, nc = c + 1, to = nr * cols + nc;
			if (isValid(nr, nc, rows, cols))
				add_directed_edge(graph, from, to);

			nr = r, nc = c - 1, to = nr * cols + nc;
			if (isValid(nr, nc, rows, cols))
				add_directed_edge(graph, from, to);

			// later we will see a more elegant way than these copy-paste lines
			// Feel free to try
		}
	}
	print_adjaceny_matrix(graph);
	
	*/

	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to, cost;
		cin >> from >> to >> cost;
		add_directed_edge_list(graph, from, to, cost);
	}
	print_adjaceny_list(graph);
	
	return 0;
}