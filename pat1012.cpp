/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ubuntu
 *
 * Created on April 16, 2018, 7:31 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int num = 2010;
    int ID[1000000];
    double score[num][4];
    char Rank[4] = {'A', 'C', 'M', 'E'};
    int n, m, id, t;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> id;
        ID[id] = i;
        for (int j = 1; j <= 3; j++)
            cin >> score[i][j];
        score[i][0] = (score[i][1] + score[i][2] + score[i][3]) / 3;
    }
    while (m--) {
        cin>>id;
        if (!ID[id]) {
            cout << "N/A\n";
            continue;
        }

        int high[] = {1, 1, 1, 1};
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 4; j++)
                if (score[i][j] > score[ID[id]][j])
                    high[j]++;
        t = 0;
        for (int j = 1; j < 4; j++)
            if (high[j] < high[t])
                t = j;
        cout << high[t] << " " << Rank[t] << endl;
    }
    return 0;
}

