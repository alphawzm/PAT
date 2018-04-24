/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pat1013.cpp
 * Author: ubuntu
 *
 * Created on April 17, 2018, 7:58 PM
 */

#include <cstdio>
#include <algorithm>

using namespace std;

/*
 * 
 */
int v[1001][1001];
bool visit[1001];
int n;

void dfs(int node) {
    visit[node] = true;
    for (int i = 1; i <= n; i++)
        if (visit[i] == false && v[node][i] == 1)
            dfs(i); 
}

int main(int argc, char** argv) {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for (int i = 0; i < k; i++) {
        // Assigns val to all the elements in the range [first,last).
        fill(visit, visit + 1001, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for (int j = 1; j <= n; j++) {
            if (visit[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}

