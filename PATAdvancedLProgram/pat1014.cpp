/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pat1014.cpp
 * Author: ubuntu
 *
 * Created on April 24, 2018, 9:50 AM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct customer {
    int customerTime;
    int customerEndTime;
};

struct window {
    int firstEndTime;
    int qEndTime;
    queue<int> qCustomer;
};

/*
 * 
 */
int main(int argc, char** argv) {

    int n, m, k, q;
    int index = 1;
    cin >> n >> m >> k >> q;
    vector<window> windows(n + 1);
    vector<customer> customers(k + 1);
    vector<bool> sorry(k + 1, false);
    for (int i = 1; i <= k; i++) {
        cin >> customers[i].customerTime;
        customers[i].customerEndTime=0;
    }
    // 处理黄线内 m*n
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (index <= k) {
                windows[j].qCustomer.push(customers[index].customerTime);
                if (windows[j].qEndTime >= 540)
                    sorry[index] = true;
                windows[j].qEndTime += customers[index].customerTime;
                customers[index].customerEndTime = windows[j].qEndTime;
                index++;
            }
        }
    }
    // 未进入黄线
    while (index <= k) {
        int minFirstEndTime = windows[1].firstEndTime, minWindow = 1;
        for (int i = 2; i <= n; i++) {
            if (windows[i].firstEndTime < minFirstEndTime) {
                minFirstEndTime = windows[i].firstEndTime;
                minWindow = i;
            }
        }
        windows[minWindow].qCustomer.pop();
        windows[minWindow].qCustomer.push(customers[index].customerTime);
        windows[minWindow].firstEndTime += windows[minWindow].qCustomer.front();
        if (windows[minWindow].qEndTime >= 540)
            sorry[index] = true;
        windows[minWindow].qEndTime += customers[index].customerTime;
        customers[index].customerEndTime = windows[minWindow].qEndTime;
        index++;
    }

    for (int i = 1; i <= q; i++) {
        int cus;
        cin >> cus;
        int time = customers[cus].customerEndTime;
        if (sorry[cus] == true)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", (time + 480) / 60, (time + 480) % 60);
    }

    return 0;
}

