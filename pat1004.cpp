// 1004. Counting Leaves (30)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100];
int pedigree[100], maxdepth = -1;

void dfs(int index, int depth) {
	if (v[index].size() == 0) {
		pedigree[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}
	for (int i = 0; i < v[index].size(); i++)
		dfs(v[index][i], depth + 1);
}
int main() {
	int n, m, k, node, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> node >> k;
		for (int j = 0; j < k; j++) {
			cin >> c;
			v[node].push_back(c);
		}
	}
	dfs(1, 0);
	cout << pedigree[0];
	for (int i = 1; i <= maxdepth; i++)
		cout << " " << pedigree[i];
	cout << endl;
	return 0;
}