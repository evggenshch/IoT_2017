// This program presents depth-first search in graph and prints enter and exit time for vertexes during dfs

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

long n, s, timer = 0;

vector <long> color;
vector <long> time_in;
vector <long> time_out;
vector < vector <long> > graph;

long dfs(long v) {  // dfs
	time_in[v] = timer++;
	color[v] = 1;
	for(long i = 0; i < graph[v].size(); i++) {
		if(!color[graph[v][i]]) {
			dfs(graph[v][i]);
		}
	}
	color[v] = 2;
	time_out[v] = timer++;
}

int main() {

	scanf("%li %li", &n, &s); // Input number of vertexes and start number

	color.assign(n, 0);
	time_in.assign(n, 0);
	time_out.assign(n, 0);

	vector <long> t;

	graph.assign(n, t);

	for(long i = 0; i < n; i++) {
		long k;
		scanf("%li", &k); // Number of neighbours of i vertex
		for(long j = 0; j < k; j++) {
			long cur;
			scanf("%li", &cur);  // Input neighbour of i vertex
			graph[i].push_back(cur);
		}
	}

	dfs(s);

	for(long i = 0; i < n; i++) { // Output of enter and exit time
		printf("Enter time/exit time of %li vertex: %li/%li \n", i, time_in[i], time_out[i]);
	}

	return 0;
}