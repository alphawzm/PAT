/*
 * pat1026.cpp
 *
 *  Created on: Jul 3, 2018
 *      Author: ubuntu
 *      PAT (Advanced Level): 1026 Table Tennis (30)
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct person{
	int arrive,start,time;
	bool vip;
}Person;
struct tables{
	int end = 8*3600;
	int num;
	bool vip;
};

bool cmpArrive(person a, person b){
	return a.arrive < b.arrive;
}
bool cmpStart(person a, person b){
	return a.start < b.start;
}

vector<person> player;
vector<tables> table;

void allocTable(int pson, int tbl){
	if(player[pson].arrive<=table[tbl].end)
		player[pson].start = table[tbl].end;
	else
		player[pson].start = player[pson].arrive;
	table[tbl].end = player[pson].start + player[pson].time;
	table[tbl].num++;
}
int findNextVip(int vipid){
	vipid++;
	while(vipid < player.size() && player[vipid].vip==false)
		vipid++;
	return vipid;
}

int main(){
	int n,k,m,viptable;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int h,m,s,time,flag;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &time, &flag);
		Person.arrive = h*3600 +m*60+s;
		Person.start = 21*3600;
		if(Person.arrive>=21*3600)
			continue;
		Person.time = time <=120 ? time*60:7200;
		Person.vip = ((flag==1)? true:false);
		player.push_back(Person);
	}
	scanf("%d%d",&k,&m);
	table.resize(k+1);
	 for(int i = 0; i < m; i++) {
		scanf("%d", &viptable);
		table[viptable].vip = true;
	}
	 sort(player.begin(),player.end(),cmpArrive);
	 int i=0,vipid=-1;
	 vipid=findNextVip(vipid);
	 while(i<player.size()){
		 int index = -1, endtime = 999999999;
		 for(int j = 1; j <= k; j++) {
			 if(table[j].end < endtime) {
				 endtime = table[j].end;
				 index = j;
			 }
		 }
		 if(table[index].end >= 21 * 3600)
			 break;
		 if(player[i].vip == true && i < vipid) {
			 i++;
			 continue;
		 }
		 if(table[index].vip == true) {
			 if(player[i].vip == true) {
				 allocTable(i, index);
				 if(vipid == i)
					 vipid = findNextVip(vipid);
				 i++;
			 } else {
				 if(vipid < player.size() && player[vipid].arrive <= table[index].end) {
					 allocTable(vipid, index);
					 vipid = findNextVip(vipid);
				 } else {
					 allocTable(i, index);
					 i++;
				 }
			 }
		 } else {
			 if(player[i].vip == false) {
				 allocTable(i, index);
				 i++;
			 } else {
				 int vipindex = -1, vipendtime = 999999999;
				 for(int j = 1; j <= k; j++) {
					 if(table[j].vip == true && table[j].end < vipendtime) {
						 vipendtime = table[j].end;
						 vipindex = j;
					 }
				 }
				 if(vipindex != -1 && player[i].arrive >= table[vipindex].end) {
					 allocTable(i, vipindex);
					 if(vipid == i)
						 vipid = findNextVip(vipid);
					 i++;
				 } else {
					 allocTable(i, index);
					 if(vipid == i)
						 vipid = findNextVip(vipid);
					 i++;
				 }
			 }
		 }
	 }
	 sort(player.begin(), player.end(), cmpStart);
	 for(i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
		 printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
		 printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
		 printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
	 }
	 for(int i = 1; i <= k; i++) {
		 if(i != 1)
			 printf(" ");
		 printf("%d", table[i].num);
	 }
	return 0;
}
