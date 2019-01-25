//this is done using BFS next level is node is obtained by changing just 1 digit in numbers and those no should not be visited 

#include<bits/stdc++.h>
using namespace std;
bool p[10000];

bool visited[10000];

void seive(){
    p[0]=p[1]=false;
    for(int i=2;i<10000;i++){
        if(p[i]==true){
            for(int j=i*2;j<10000;j+=i){
                p[j]=false;
            }
        }
    }
}

void find(vector<int> v,int n2,int level){
    int len=v.size(),i,j,x;
    vector<int> temp;
    for(j=0;j<len;j++){
        if(v[j]==n2){
            cout<<level<<"\n";
            return;
        }
        //This loop is used to change 1st digit in number from 0 to 9
        for(i=0;i<=9;i++){
            if((v[j]%1000)+(i*1000)>1000 && p[(v[j]%1000)+(i*1000)] && !visited[(v[j]%1000)+(i*1000)]){
                visited[(v[j]%1000)+(i*1000)]=true;
                temp.push_back((v[j]%1000)+i*1000);
            }
        }
        //This loop is used to change 2nd digit in number from 0 to 9
        for(i=0;i<=9;i++){
            if((v[j]/1000)*1000+(v[j]%100)+i*100>1000 && p[(v[j]/1000)*1000+(v[j]%100)+i*100] && !visited[(v[j]/1000)*1000+(v[j]%100)+i*100]){
                visited[(v[j]/1000)*1000+(v[j]%100)+i*100]=true;
                temp.push_back((v[j]/1000)*1000+(v[j]%100)+i*100);
            }
        }
        //This loop is used to change 3rd digit in number from 0 to 9
        for(i=0;i<=9;i++){
            if((v[j]/100)*100+(v[j]%10)+i*10>1000 && p[(v[j]/100)*100+(v[j]%10)+i*10] && !visited[(v[j]/100)*100+(v[j]%10)+i*10]){
                visited[(v[j]/100)*100+(v[j]%10)+i*10]=true;
                temp.push_back((v[j]/100)*100+(v[j]%10)+i*10);
            }
        }
        //This loop is used to change 4th digit in number from 0 to 9
        for(i=1;i<=9;i++){
            if((v[j]/10)*10+i>1000 && p[(v[j]/10)*10+i] && !visited[(v[j]/10)*10+i]){
                visited[(v[j]/10)*10+i]=true;
                temp.push_back((v[j]/10)*10+i);
            }
        }
    }
    v.clear();
    find(temp,n2,level+1);
}

int main(){
    int n1,n2,i;
    cin>>n1>>n2;
    for(i=0;i<10000;i++){
      p[i]=true;   //list of prime numbers
      visited[i]=false; //list of visited primes
    } 
    seive();
    vector<int> v;
    v.push_back(n1);
    visited[n1]=true;
    find(v,n2,0);
}
