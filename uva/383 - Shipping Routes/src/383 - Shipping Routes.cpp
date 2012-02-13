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

#define Foreach(var, upperLimit) \
	for(unsigned var = 0; var < upperLimit; var++)

int DataSets;
int WarehouseCount, LegCount, ShippingRequestCount;
map<string, int> WarehouseToIntMap;

vector<int> AdjList[31];

const int NO_SHIPPING_POSSIBLE = -1;

int FindDistanceBetween(int warehouse1, int warehouse2) {
	map<int, int> distance;
	distance[warehouse1] = 0;
	queue<int> nodeQueue;
	nodeQueue.push(warehouse1);
	while (!nodeQueue.empty()) {
		long node = nodeQueue.front();
		nodeQueue.pop();
//		for (unsigned i = 0; i < AdjList[node].size(); i++) {
		Foreach(i, AdjList[node].size()) {
			int neighbour = AdjList[node][i];
			// if it isn't already visited
			if (!distance.count(neighbour)) {
				int distanceToNeighbour = distance[node] + 1;
				if (neighbour == warehouse2) {
					return distanceToNeighbour;
				}
				distance[neighbour] = distanceToNeighbour;
				nodeQueue.push(neighbour);
			}
		}
	}
	return NO_SHIPPING_POSSIBLE;
}

string inline ReadWarehouse() {
	return ( {	string tmp; cin >> tmp; tmp;});
}

int main() {
#ifndef ONLINE_JUDGE
	close(0);
	open("in.txt", O_RDONLY);
//	        close (1); open ("out.txt", O_WRONLY | O_CREAT, 0600);
#endif
	printf("SHIPPING ROUTES OUTPUT\n\n");
	scanf("%d\n", &DataSets);
	for (int dataSet = 1; dataSet <= DataSets; dataSet++) {
		WarehouseToIntMap.clear();
		for (int i = 0; i < 31; i++) {
			AdjList[i].clear();
		}
		printf("DATA SET  %d\n\n", dataSet);
		scanf("%d %d %d\n", &WarehouseCount, &LegCount, &ShippingRequestCount);
		for (int i = 1; i <= WarehouseCount; i++) {
			WarehouseToIntMap[ReadWarehouse()] = i;
		}
		string temp;
		getline(cin, temp);
		for (int i = 0; i < LegCount; i++) {
			int warehouse1Int = WarehouseToIntMap[ReadWarehouse()];
			int warehouse2Int = WarehouseToIntMap[ReadWarehouse()];
			AdjList[warehouse1Int].push_back(warehouse2Int);
			AdjList[warehouse2Int].push_back(warehouse1Int);
		}
		int shippingSize;
		for (int i = 0; i < ShippingRequestCount; i++) {
			scanf("%d", &shippingSize);
			int warehouse1Int = WarehouseToIntMap[ReadWarehouse()];
			int warehouse2Int = WarehouseToIntMap[ReadWarehouse()];
			int distance = FindDistanceBetween(warehouse1Int, warehouse2Int);
			if (distance == NO_SHIPPING_POSSIBLE) {
				printf("NO SHIPMENT POSSIBLE\n");
			} else {
				printf("$%d\n", shippingSize * 100 * distance);
			}
		}
		printf("\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
