//This algorithm is not efficient.
//https://www.geeksforgeeks.org/water-jug-problem-using-bfs/
//I have implimented it using dfs although can be done using bfs
#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;

void dfs(vector<pair<int,int>> v,int j1,int j2,int &x,int &y,int &t){
    if(m[make_pair(j1,j2)]) return;
    m[make_pair(j1,j2)]=1;
    if((j1==t && j2==0)||(j1==0 && j2==t)){
        for(int i=0;i<v.size();i++){
            cout<<"["<<v[i].first<<" "<<v[i].second<<"]";
        }
        cout<<"\n";
        return;
    }
    if(j1==0){
        v.push_back(make_pair(j1+x,j2));
        dfs(v,j1+x,j2,x,y,t);
    } 
    if(j2==0){
        v.push_back(make_pair(j1,j2+y));
       dfs(v,j1,j2+y,x,y,t); 
    } 
    if(j1>0 && j2!=0){
         v.push_back(make_pair(0,j2));
        dfs(v,0,j2,x,y,t);
    } 
    if(j2>0 && j1!=0){
         v.push_back(make_pair(j1,0));
       dfs(v,j1,0,x,y,t); 
    } 
    if(j1>0 && j2<y){
        if(j1+j2>=y){
             v.push_back(make_pair(j1+j2-y,y));
           dfs(v,j1+j2-y,y,x,y,t); 
        } 
        else{
             v.push_back(make_pair(0,j1+j2));
            dfs(v,0,j1+j2,x,y,t);
        } 
    }
    if(j2>0 && j1<x){
        if(j1+j2>=x){
             v.push_back(make_pair(x,j1+j2-x));
            dfs(v,x,j1+j2-x,x,y,t);
        } 
        else{
             v.push_back(make_pair(j1+j2,0));
            dfs(v,j1+j2,0,x,y,t);
        } 
    }
}

int main() 
{ 
    int Jug1 = 4, Jug2 = 3, target = 2; 
    cout << "Path from initial state "
            "to solution state :\n"; 
    vector<pair<int,int>> v;      
    dfs(v,0,0,Jug1, Jug2, target); 
    return 0; 
}
