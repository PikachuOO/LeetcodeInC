/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.*/

#include "common.h"
int FindRoot(int *root_id, int idx)
{
	if (idx == root_id[idx])
		return idx;
	idx = FindRoot(root_id, root_id[idx]);
	return idx;
}

int CombineUnion(int *root_id, int idx1, int idx2)
{
	int root_idx1 = FindRoot(root_id, idx1);
	int root_idx2 = FindRoot(root_id, idx2);
	if (root_idx1 != root_idx2)
	{
		root_id[idx2] = root_idx1;
		return 1;
	}
	else
		return 0;
}

int *BuildRoot(int k)
{
	int i;
	int *root_id = calloc(k, sizeof(int));

	for (i = 0; i < k; i++)
		root_id[i] = i;

	return root_id;
}
void test_323()
{
	int n = 5;
	int *root = BuildRoot(n);
	n -= CombineUnion(root, 0, 1);
	n -= CombineUnion(root, 1, 2);
	n -= CombineUnion(root, 3, 4);
	printf("%d", n);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct _graph
{
	struct _graph *next;
	struct _graph *head;
	struct _graph *cur;
	int v;
} graph;

graph *graph_buildtable(int k)
{
	int i;
	graph *table = calloc(k, sizeof(graph));
	for (i = 0; i < k; i++)
	{
		table[i].v = i;
	}
	return table;
}

void graph_addedge(graph *table, int idx1, int idx2)
{
	if (table[idx1].head == 0)
	{
		table[idx1].head = &table[idx2];
		table[idx1].cur = table[idx1].head;
	}
	else
	{
		table[idx1].cur->next = &table[idx2];
		table[idx1].cur = &table[idx2];
	}
	
	if (table[idx2].head == 0)
	{
		table[idx2].head = &table[idx1];
		table[idx2].cur = table[idx2].head;
	}
	else
	{
		table[idx2].cur->next = &table[idx1];
		table[idx2].cur = &table[idx1];
	}
}


int graph_dfs(graph *g, int *visited)
{
	graph *p = g->head;
	int visit_cnt = 0;

	if (visited[g->v] == 0)
	{
		visited[g->v] = 1;
		visit_cnt = 1;

		while (p)
		{
			visit_cnt += graph_dfs(p, visited);
			p = p->next;
		}
	}
	
	return visit_cnt;
}

void test_323II()
{
	int i, cnt = 0;
	int k = 5;
	graph *table = graph_buildtable(5);
	int *visited = calloc(k, sizeof(int));

	graph_addedge(table, 0, 1);
	graph_addedge(table, 1, 2);
	graph_addedge(table, 3, 4);
	for (i = 0; i < k; i++)
	{
		if (graph_dfs(&table[i], visited))
			cnt++;
	}
	printf("%d", cnt);
}