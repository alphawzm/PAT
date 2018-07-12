/*
 * pat1028.cpp
 *
 *  Created on: Jul 11, 2018
 *      Author: ubuntu
 *      PAT Advanced: 1028. List Sorting (25)
 */

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXNUM = 100001;
struct Stu {
	int no, score;
	char name[10];
} stu[MAXNUM];

int c;
int cmp(Stu a, Stu b) {
	if (c == 1)
		return a.no < b.no;
	else if (c == 2) {
		if (strcmp(a.name, b.name) == 0)
			return a.no < b.no;
		return strcmp(a.name, b.name) <= 0;
	} else {
		if (a.score == b.score)
			return a.no < b.no;
		return a.score <= b.score;
	}
}

int main() {
	int n;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d %s %d", &stu[i].no, &stu[i].name, &stu[i].score);
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%06d %s %d\n", stu[i].no, stu[i].name, stu[i].score);
	return 0;
}
