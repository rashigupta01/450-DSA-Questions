// https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
// Approach : 
// Find the indegree of each node and insert the nodes with indegree 0 into a queue
// Pop each node from the queue and decrease the indegree of each of its adj nodes, if indegree gets 0 insert into the queue
// also keep a timer and evaluate the job time simultaneously


// MY APPROACH : find topological sort. Now call dfs visit for unexplored notes (they will have indegree 0 so job time = 1)
// update the child with one more than its job time and call for children
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

vector<int> graph[maxN];

int job[maxN];

void addEdge(int u, int v) {
	graph[u].push_back(v);
}

void util(int s, vector<bool>& visited, vector<int>& res) {
    
    visited[s] = true;
    for (auto ele : graph[s]) {
        if (!visited[ele])
            util(ele, visited, res);
    }
    res.push_back(s);
}

vector<int> get_top_sort (int V) {
    vector<int> res;
    vector<bool> visited (V, false);
    
    for (int i=0; i<V; i++) {
        if (!visited[i])
            util (i, visited, res);
    }
    reverse (res.begin(), res.end());
    return res;
}

void dfs_util (int source, vector<bool> &visited) {
    visited[source] = true;

    for (auto ele : graph[source]) {
        if (job[ele] < job[source]+1) {
            job[ele] = job[source] +1;
            dfs_util(ele, visited);
        }
    }

}

// Function to find the minimum time
// needed by each node to get the task
void printOrder(int n)
{
    vector<int> top_sort = get_top_sort(n);
    vector<bool> visited(n);

    for (int i=0; i<top_sort.size(); i++) {
        if (!visited[top_sort[i]]) {
            job[top_sort[i]] = 1;
            dfs_util (top_sort[i], visited);
        }
    }

    for (int i=0; i<n; i++) cout<<job[i]<<" ";
}