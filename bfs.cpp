#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> g[],int s,int e){
    g[s].push_back(e);
    //g[e].push_back(s); if graph is undirected
}

void bfsUtil(vector<int> g[],int s,int visited[]){
    visited[s]=1;
    vector<int> v;
    v.push_back(s);
    while(v.size()!=0){
        cout<<v[0]<<" ";
        for(int i=0;i<g[v[0]].size();i++){
            if(visited[g[v[0]][i]]==0){
                v.push_back(g[v[0]][i]);
                visited[g[v[0]][i]]=1;
            }
        }
        v.erase(v.begin());
    }
}

void bfs(vector<int> g[],int size){
    int visited[size]={0};
    for(int i=0;i<size;i++)
        if(visited[i]==0)
            bfsUtil(g,i,visited);
    return;
}

int main(){
    vector<int> g[4];
    addEdge(g,0, 1); 
    addEdge(g,0, 2); 
    addEdge(g,1, 2); 
    addEdge(g,2, 0); 
    addEdge(g,2, 3); 
    addEdge(g,3, 3); 
    bfs(g,4);
}
