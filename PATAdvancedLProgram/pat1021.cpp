/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pat1021.cpp
 * Author: ubuntu
 * pat1021:Deepest Root (25)
 * pat advanced
 *
 * Created on May 27, 2018, 8:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> adjm;
vector<int> visited;
int deepest = -1;
int components = 0;
int n;
set<int> res;
set<int> ans;

void dfs(int v, int d, set<int> &res){
    visited[v] = 1;
    if(d>deepest){
        deepest = d;
        res.clear();
        res.insert(v);
    }else if(d==deepest){
        res.insert(v);
    }
    for(int i=0; i<adjm[v].size();i++){
        if(visited[adjm[v][i]]==0)
            dfs(adjm[v][i],d+1,res);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    cin >> n;
    adjm.resize(n);
    visited.resize(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adjm[a].push_back(b);
        adjm[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            components++;
            dfs(i,1,res);
        }
    }
    if(components>1){
        cout<<"Error: "<<components<<" components\n";
        return 0;
    }
    for(int i=0;i<n;i++)
        visited[i]=0;
    deepest=-1;
    dfs(*res.begin(),1,ans);
    for(set<int>::iterator itr = res.begin();itr != res.end();++itr)
        ans.insert(*itr);  
    for(set<int>::iterator itr = ans.begin();itr != ans.end();++itr)
        cout<<*itr+1<<endl;  
    return 0;
}