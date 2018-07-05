/*
 * pat1025.cpp
 *
 *  Created on: Jul 3, 2018
 *      Author: ubuntu
 *      PAT (Advanced Level): 1025 PAT Ranking
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct student {
	long long int no;
	int score, finalRank, loca, localRank;
};

bool cmp(student a, student b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.no < b.no;
}

int main() {
	int n, m;
	scanf("%d", &n);
	vector<student> finalRanklist;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		vector<student> v(m);
		for (int j = 0; j < m; j++) {
			scanf("%lld %d", &v[j].no, &v[j].score);
			v[j].loca = i;
		}
		sort(v.begin(), v.end(), cmp);
		v[0].localRank = 1;
		finalRanklist.push_back(v[0]);
		for (int j = 1; j < m; j++) {
			v[j].localRank =
					(v[j].score == v[j - 1].score) ?
							(v[j - 1].localRank) : (j + 1);
			finalRanklist.push_back(v[j]);
		}
	}
	sort(finalRanklist.begin(), finalRanklist.end(), cmp);
	finalRanklist[0].finalRank = 1;
	for (int j = 1; j < finalRanklist.size(); j++)
		finalRanklist[j].finalRank =
				(finalRanklist[j].score == finalRanklist[j - 1].score) ?
						(finalRanklist[j - 1].finalRank) : (j + 1);
	printf("%d\n", finalRanklist.size());
	for (int i = 0; i < finalRanklist.size(); i++)
		printf("%013lld %d %d %d\n", finalRanklist[i].no, finalRanklist[i].finalRank, finalRanklist[i].loca,
				finalRanklist[i].localRank);
	return 0;
}
