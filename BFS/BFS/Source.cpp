#include<iostream>
#include<vector>
#include <queue>
using namespace std;

const int oo = 10000000;
const int dr[4] = {-1,0,1,0};
const int dc[4] = { 0,1,0,-1 };

vector<int> BFS_V2(vector<vector<int>>& adj_list, int start)
{
	vector<int>len(adj_list.size(), oo);
	queue<int>q;

	q.push(start);
	len[start] = 0;

	for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size())
	{
		while (sz--)
		{
			int cur = q.front();
			q.pop();

			for (int neighbour : adj_list[cur])
			{
				if (len[neighbour] == oo)
				{
					q.push(neighbour);
					len[neighbour] = level + 1;
				}
			}
		}
	}
	return len;
}

vector<int> BFS_V2_to_print_path(vector<vector<int>>& adj_list, int start)
{
	vector<int>len(adj_list.size(), 00);
	vector<int>parent(adj_list.size(), -1);
	queue<int>q;

	q.push(start);
	len[start] = 0;

	for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size())
	{
		while (sz--)
		{
			int cur = q.front();
			q.pop();

			for (int neighbour : adj_list[cur])
			{
				if (len[neighbour] == 00)
				{
					q.push(neighbour);
					len[neighbour] = level + 1;
					parent[neighbour] = cur;
				}
			}
		}
	}

	return parent;
}

void print_path(vector<int>& parent, int cur_node)
{
	if (cur_node == -1)
		return;

	print_path(parent, parent[cur_node]);
	cout << cur_node << " ";
}

vector<int> BFS(vector<vector<int>>& adj_list, int start)
{
	vector<int>len(adj_list.size(), 00);
	queue<pair<int, int>>q;

	q.push({ start,0 });
	len[start] = 0;

	while (!q.empty())
	{
		int cur = q.front().first, level = q.front().second;
		q.pop();

		for (int neighbour : adj_list[cur])
		{
			if (len[neighbour] == 00)
			{
				q.push({ neighbour ,level + 1 });
				len[neighbour] = level + 1;
			}
		}
	}

	return len;
}

int main() {

	return 0;
}