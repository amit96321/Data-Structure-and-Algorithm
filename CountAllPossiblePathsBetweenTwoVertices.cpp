#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> g[],int s,int e){
    g[s].push_back(e);
}

void dfs(vector<int> v,vector<int> g[],int s,int e,bool visited[]){
    visited[s]=true;
    if(s==e){
        for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<"\n";
        v.clear();
    }
    else{
        for(int i=0;i<g[s].size();i++){
            if(!visited[g[s][i]]){
                v.push_back(g[s][i]);
                dfs(v,g,g[s][i],e,visited);
                v.pop_back();
            }
        }
    }
    visited[s]=false;
}

void countPaths(vector<int> g[],int s,int e,bool visited[]){
    vector<int> temp;
    temp.push_back(s);
    dfs(temp,g, s,e,visited);
}

int main(){
    vector<int> g[5];
    addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 0, 4); 
    addEdge(g, 1, 4); 
    addEdge(g, 1, 3); 
    addEdge(g, 2, 4);
    addEdge(g, 3, 2);
    bool visited[5];
    for(int i=0;i<5;i++) visited[i]=false;
    int s = 0, d = 4; 
    countPaths(g, s, d,visited); 
  
    return 0; 
}
