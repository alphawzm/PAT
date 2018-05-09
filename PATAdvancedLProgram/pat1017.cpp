/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pat1017.cpp
 * Author: ubuntu
 *
 * Created on May 9, 2018, 3:39 PM
 * pat advanced 1017
 */

#include <iostream>  
#include <iomanip>  
#include <queue>  
#include <stdio.h> 

using namespace std;

struct Person {
    int hour;
    int minute;
    int second;
    int last;
    int total;

    Person(int h, int m, int s, int l) : hour(h), minute(m), second(s), last(l * 60) {
        total = h * 3600 + m * 60 + s;
    }

    bool operator<(const Person& p) const {
        if (total > p.total) {
            return true;
        } else {
            return false;
        }
    }
};

struct window {
    int total;

    window(int t) : total(t) {
    }

    bool operator<(const window& w) const {
        if (total > w.total) {
            return true;
        } else {
            return false;
        }
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    priority_queue<Person> persons;
    priority_queue<window> windows;

    int N, K;
    cin >> N>> K;
    int base = 28800; // 8:00:00
    int limit = 61201; // 17:00:01
    int wait_total = 0;

    for (int i = 0; i < K; i++) {
        windows.push(window(base));
    }

    int h, m, s, l;
    for (int i = 0; i < N; i++) {
        scanf("%d:%d:%d:%d", &h, &m, &s, &l);
        persons.push(Person(h, m, s, l));
    }
    int cnt = 0;
    Person p = Person(0, 0, 0, 0);
    window w = window(0);
    while (!persons.empty()) {
        p = persons.top();
        persons.pop();
        if (p.total >= limit)
            break;
        cnt++;
        w = windows.top();
        windows.pop();
        if (p.total < w.total) {
            wait_total += w.total - p.total;
            w.total += p.last;
        } else {
            w.total = p.total + p.total;
        }
        windows.push(w);
    }
    printf("%0.1f", wait_total / cnt / 60.0);
    return 0;
}

