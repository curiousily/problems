#include <fcntl.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <climits>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define FOR(upperLimit) \
	for(unsigned i = 0; i < upperLimit; i++)

#define FOREACH(var, upperLimit) \
	for(unsigned var = 0; var < upperLimit; var++)

unsigned N, K, M;

unsigned StartNode;

struct Node {
	int index;
	int weight;
};

vector<Node> AdjList[1000000];
bool InTree[1000000];

void FindMinimumDistance() {
	FOREACH(i, M) {
		InTree[i] = false;
	}
	int totalWeight = 0;
	while (!InTree[StartNode]) {
		InTree[StartNode] = true;
		Node adjNode;
		FOREACH(adjNodeIndex, AdjList[StartNode].size()) {
			adjNode = AdjList[StartNode][adjNodeIndex];
			int minWeight = INT_MAX;
			if (!InTree[adjNode.index] && minWeight > adjNode.weight) {
				minWeight = adjNode.weight;
			}
			totalWeight += minWeight;
		}
		StartNode = adjNode.index;
	}
	printf("total min weight is %d\n", totalWeight);
}

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	int tc = 0;
	while (scanf("%d\n", &N) != EOF) {
		if (tc++) {
			printf("\n");
		}
		int parent, child, weight;
		FOR(N - 1) {
			scanf("%d %d %d\n", &parent, &child, &weight);
			Node childNode;
			childNode.index = child;
			childNode.weight = weight;
			AdjList[parent].push_back(childNode);
			// the link is bidirectional
			childNode.index = parent;
			AdjList[child].push_back(childNode);
			StartNode = parent;
		}
		FOREACH(i, N - 1) {
			FOREACH(j, N - 1) {
				printf("%d", AdjList[i][j].weight);
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d\n", &K);
		FOR(K) {

		}
		scanf("%d\n", &M);
		FOR(M) {

		}
		FindMinimumDistance();
	}
	return 0;
}
