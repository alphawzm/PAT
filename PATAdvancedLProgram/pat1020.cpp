/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pat1020.cpp
 * 1020. Tree Traversals (25)
 * pat advanced
 * Author: ubuntu
 *
 * Created on May 22, 2018, 9:33 AM
 */

#include <cstdlib>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> postorder,inorder,level;

//给定一棵二叉树的后序遍历和中序遍历，输出其层序遍历的序列
void levelorder(int root, int start, int end, int index){
    if(start>end)
        return;
    int i = start;
    while(i<end && inorder[i]!=postorder[root])
        i++;
    level[index] = postorder[root];
    levelorder(root-1-end+i,start, i-1,2*index+1);
    levelorder(root-1,i+1,end,2*index +2);
}

/*
 * 
 */
int main(int argc, char** argv) {
    int n,cnt=0;
    scanf("%d",&n);
    postorder.resize(n);
    inorder.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&postorder[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&inorder[i]);
    levelorder(n-1,0,n-1,0);
    for(int i=0;i<level.size();i++){
        if(level[i]!=-1){
            if(cnt !=0) 
                printf(" ");
            printf("%d",level[i]);
            cnt++;
        }
        if(cnt==n)
            break;
    }

    return 0;
}

