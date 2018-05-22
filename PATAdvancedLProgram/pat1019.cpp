/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pat1019.cpp
 * 1019. General Palindromic Number (20)
 * pat advanced
 * Author: ubuntu
 *
 * Created on May 22, 2018, 9:14 AM
 */

#include <cstdlib>
#include <cstdio>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int a,b;
    scanf("%d %d",&a,&b);
    int arr[40], index=0;
    while(a!=0){
        arr[index++]=a%b;
        a=a/b;
    }
    int flag=0;
    for(int i=0;i<index/2;i++){
        if(arr[i]!=arr[index-i-1]){
            printf("No\n");
            flag=1;
            break;
        }
    }
    if(!flag)
        printf("Yes\n");
    for(int i=index-1;i>=0;i--){
        printf("%d",arr[i]);
        if(i!=0)
            printf(" ");
    }
    if(index==0)
        printf("0");
    
    return 0;
}

