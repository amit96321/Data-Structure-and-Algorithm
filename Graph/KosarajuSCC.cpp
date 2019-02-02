// https://www.geeksforgeeks.org/strongly-connected-components/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> g[],int s,int e){
    g[s].push_back(e);
}

void dfs(vector<int> g[],int s,vector<int> &v,bool visited[]){
    visited[s]=true;
    for(int i=0;i<g[s].size();i++){
        if(!visited[g[s][i]]) dfs(g,g[s][i],v,visited);
    }
    v.push_back(s);
}

void dfsreverse(vector<int> rev[],int s,bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<rev[s].size();i++){
        if(!visited[rev[s][i]]) dfsreverse(rev,rev[s][i],visited);
    }
}

void reverseEdge(vector<int> rev[],vector<int> g[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            addEdge(rev,g[i][j],i);
        }
    }
}

void findConnectedComponent(vector<int> g[],int n){
    vector<int> v; int i;
    bool visited[n];
    memset(visited,false,sizeof(visited));
    for(i=0;i<n;i++){
        if(!visited[i])
            dfs(g,i,v,visited);
    }
    vector<int> rev[n];
    reverseEdge(rev,g,n);
    memset(visited,false,sizeof(visited));
    while(v.size()!=0){
        if(!visited[v[v.size()-1]]){
            dfsreverse(rev,v[v.size()-1],visited);
            cout<<"\n";
        }
        v.pop_back();
    }
}

int main(){
    vector<int> g[5];
    addEdge(g, 1, 0); 
    addEdge(g, 0, 2); 
    addEdge(g, 2, 1); 
    addEdge(g, 0, 3); 
    addEdge(g, 3, 4); 
    findConnectedComponent(g,5);
}
