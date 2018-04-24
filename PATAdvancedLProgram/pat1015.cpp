/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: ubuntu
 *
 * Created on April 24, 2018, 4:39 PM
 */

#include <cstdlib>
#include <iostream>  
#include <math.h>

using namespace std;

/*
 * 
 */ 
int reverse(int rp,int radix){
    int reverse = 0;
    while(rp>0){
        reverse = reverse*radix+rp%radix;
        rp/=radix;
    }
    return reverse;
}
bool isPrime(int p){
    if(p<2)
        return false;
    for(int i=2;i<=sqrt(p);i++){
        if(p%i==0)
            return false;
    }
    return true;
}
int main(int argc, char** argv) {
    
    int d,n;
    while(cin >>n&&n>0){
        cin >>d;
        if(isPrime(n)&&isPrime(reverse(n,d)))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

