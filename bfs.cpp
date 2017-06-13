// This program counts distances from start vertex to others using breadth-first search

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

const long INF = 100000000;

using namespace std;

int main() {

    long n, s;

	scanf("%li %li", &n, &s); // Input number of vertexes and start number

	vector <bool> used(n, false);
	vector <long> t;
	vector <long> d(n, INF);
	vector < vector <long> > graph(n, t);
	queue <long> q;

	for(long i = 0; i < n; i++) {
		long k;
		scanf("%li", &k); // Number of neighbours of i vertex
		for(long j = 0; j < k; j++) {
			long cur;
			scanf("%li", &cur);  // Input neighbour of i vertex
			graph[i].push_back(cur);
		}
	}

	q.push(s);
	used[s] = true;
	d[s] = 0;

	while(!q.empty()) {   // bfs
		long v = q.front();
		q.pop();
		for(long j = 0; j < graph[v].size(); j++) {
			long cur = graph[v][j];
			if(!used[cur]) {
				used[cur] = true;
				q.push(cur);
				d[cur] = d[v] + 1;
			}
		}
	}

	for(long i = 0; i < n; i++) { // Output of distances 
		printf("Distance to vertex %li from start vertex %li: %li \n", i, s, d[i]);
	}

	return 0;
}