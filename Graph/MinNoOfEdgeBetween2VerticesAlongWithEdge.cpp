//This question is like finding min distance between two primes. Here we store all the path to a node in queue. Each time we pop a path
//from a queue and find the last node in it and push a path by appending the popped path with last node connections which are not visited
#include<bits/stdc++.h>
using namespace std;

void add(vector <int> edges[], int u, int v) 
{ 
   edges[u].push_back(v); 
   edges[v].push_back(u); 
}

void bfs(vector<int> g[],vector<bool> &visited,int dest,vector<vector<int>> path){
    int len=path.size(),i,j,curr;
    //cout<<len<<"\n";
    vector<vector<int>> temp;
    vector<int> x;
    for(i=0;i<len;i++){
        curr=path[i][path[i].size()-1];
        if(curr==dest){
            cout<<path[i].size()<<":";
            for(j=0;j<path[i].size();j++){
                cout<<path[i][j]<<" ";
            }
            cout<<"\n";
            return;
        }
        for(j=0;j<g[curr].size();j++){
           if(!visited[g[curr][j]]){
              visited[g[curr][j]]=true;
               x=path[i];
               x.push_back(g[curr][j]);
               temp.push_back(x);
           } 
        }
    }
    bfs(g,visited,dest,temp);
}

int main(){
    vector<int> g[7];
    int src,dest;
    src=1;
    dest=6;
    add(g,0,1);
    add(g,0,2);
    add(g,1,2);
    add(g,0,4);
    add(g,2,5);
    add(g,3,4);
    add(g,4,6);
    add(g,4,5);
    vector<bool> visited(7);
    for(int i=0;i<7;i++) visited[i]=false;
    vector<vector<int>> path;
    vector<int> v;
    v.push_back(src);
    path.push_back(v);
    visited[src]=true;
    bfs(g,visited,dest,path);
    return 0;
}
