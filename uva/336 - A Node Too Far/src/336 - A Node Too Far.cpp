#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int NC;
//vector<int> AdjList[65];

set<long> nodes;

map<long, vector<long> > AdjVector;

long FindReachableNodes(long startNode, long ttl) {
	map<long, long> distance;
	distance[startNode] = 0;
	queue<long> nodeQueue;
	nodeQueue.push(startNode);
	long reachableNodes = 0;
	while (!nodeQueue.empty()) {
		long node = nodeQueue.front();
		nodeQueue.pop();
		for (unsigned i = 0; i < AdjVector[node].size(); i++) {
			long neighbour = AdjVector[node][i];
			// if it isn't already visited
			if (!distance.count(neighbour)) {
				int distanceToNeighbour = distance[node] + 1;
				if (distanceToNeighbour > ttl) {
					continue;
				}
				distance[neighbour] = distance[node] + 1;
				nodeQueue.push(neighbour);
				reachableNodes++;
			}
		}
	}
	return reachableNodes;
}

int FindNotReachableNodes(long startNode, long ttl) {
	return (nodes.size() - 1) - FindReachableNodes(startNode, ttl);
}

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	int tc = 0;
	long a, b;
	while (scanf("%d\n", &NC) && NC != 0) {
		AdjVector.clear();
		nodes.clear();
		for (int i = 0; i < NC; i++) {
			scanf("%ld %ld", &a, &b);
//			printf("Pair a=%d b=%d\n", a, b);
			if (a != b) {
				AdjVector[a].push_back(b);
				AdjVector[b].push_back(a);

			}
			nodes.insert(a);
							nodes.insert(b);
//			AdjList[a].push_back(b);
		}
		long startNode, ttl;
		while (scanf("%ld %ld", &startNode, &ttl) && (startNode != 0 || ttl != 0)) {
			tc++;
//			printf("startNode=%d ttl=%d\n", startNode, ttl);
			printf(
					"Case %d: %d nodes not reachable from node %ld with TTL = %ld.\n",
					tc, FindNotReachableNodes(startNode, ttl), startNode, ttl);
		}
//		printf("Case END\n");
	}
	return 0;
}
