#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH& graph, int from, int to) {
	graph[from].push_back(to);
}

vector<int> topsort(const GRAPH& adjlist)
{
	int sz = adjlist.size();
	vector<int> indegree(sz, 0);

	for (int i = 0; i < sz; i++)
		for (int j : adjlist[i])
			indegree[j]++;

	priority_queue<int , vector<int> , greater<int>>ready;

	for (int i = 0; i < sz; i++)
		if(!indegree[i])
		ready.push(i);

	vector<int>ordering;
	while (!ready.empty()) {
		int i = ready.top();
		ready.pop();
		ordering.push_back(i);

		for (int j : adjlist[i])
			if (--indegree[j] == 0)
				ready.push(j);
	}

	if (ordering.size() != sz)
		ordering.clear();

	return ordering;
}

int longest_path(const GRAPH& adjlist)
{
	int sz = adjlist.size();
	vector<int> indegree(sz, 0);

	for (int i = 0; i < sz; i++)
		for (int j : adjlist[i])
			indegree[j]++;

	queue<int> ready;

	for (int i = 0; i < sz; i++)
		if (!indegree[i])
			ready.push(i);

	int level = 0, found_nodes = 0, level_sz;
	while (!ready.empty()) {

		level_sz = ready.size();

		while (level_sz--)
		{
			int i = ready.front();
			ready.pop();
			found_nodes++;

			for (int j : adjlist[i])
				if (--indegree[j] == 0)
					ready.push(j);
		}

		level++;
	}

	if (found_nodes != sz)
		return -1;

	return level;
}





void add_directed_edge_hashtable(unordered_map<int, vector<int>>& graph, int from, int to) {
	graph[from].push_back(to);
}

vector<int> topsort_hashtable(unordered_map<int, vector<int>>& adj) {	
	unordered_map<int, int> indegree;

	for (auto& nodeNeighbours : adj)
		for (int j : nodeNeighbours.second)
			indegree[j]++;

	queue<int> ready;
	for (auto& nodeNeighbours : adj)
		if (!indegree.count(nodeNeighbours.first))
			ready.push(nodeNeighbours.first);

	vector<int> ordering;
	while (!ready.empty()) {
		if (ready.size() > 1)
			return vector<int>();
		int i = ready.front();
		ready.pop();
		ordering.push_back(i);

		for (int j : adj[i])
			if (--indegree[j] == 0)	
				ready.push(j);
	}
	if (ordering.size() != adj.size())
		return vector<int>();				
	return ordering;
}

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
	unordered_map<int, vector<int>> graph(org.size());
	for (auto& seq : seqs) {
		for (int i = 0; i < (int)seq.size() - 1; ++i)
			add_directed_edge_hashtable(graph, seq[i], seq[i + 1]);
	}
	for (auto& seq : seqs) {
		if (seq.size() == 1 && graph.count(seq[0]) == 0)
			graph[seq[0]] = vector<int>();
	}

	vector<int> ordering = topsort_hashtable(graph);
	return ordering == org;
}