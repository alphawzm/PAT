// 1003. Emergency(25)

#include <iostream>
#include <cstdio>  
#include <cstdlib>  
#include <climits> 

using namespace std;

const int MAX = 501;

int weight[MAX], visit[MAX], map[MAX][MAX];
int mindist, cnt, maxteam, n;

void init(int n) {
	int i, j;

	for (i = 0; i < n; ++i) {
		visit[i] = 0;
		for (j = 0; j < n; ++j) {
			map[i][j] = INT_MAX;
		}
	}
}

void dfs(int p, const int end, int dist, int weit) {
	if (p == end) {
		if (dist<mindist) {
			cnt = 1;
			mindist = dist;
			maxteam = weit;
		}
		else if (dist == mindist) {
			++cnt;
			if (maxteam<weit) {
				maxteam = weit;
			}
		}
		return;
	}

	int i;

	if (dist>mindist)return; 

	for (i = 0; i<n; ++i) {
		if (visit[i] == 0 && map[p][i] != INT_MAX) {
			visit[i] = 1;
			dfs(i, end, dist + map[p][i], weit + weight[i]);
			visit[i] = 0;
		}
	}
}

int main() {
	int m, c1, c2, x, y, dist, i;
	mindist = INT_MAX;
	cnt = 0;

	cin >> n >> m >> c1 >> c2;
	init(n);
	for (i = 0; i < n; ++i) {
		cin >> weight[i];
	}
	while (m--) {
		cin >> x >> y >> dist;
		if (map[x][y] > dist) {
			map[x][y] = map[y][x] = dist;
		}
	}

	dfs(c1, c2, 0, weight[c1]);

	printf("%d %d\n", cnt, maxteam);
	return 0;
}