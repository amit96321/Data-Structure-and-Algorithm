#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> g[],int s,int e){
    g[s].push_back(e);
    //g[e].push_back(s); if grapg is undirected
}

void topologicalUtil(vector<int> g[],int s,int *visited,vector<int> &stk){
    visited[s]=1;
    for(int i=0;i<g[s].size();i++){
        if(visited[g[s][i]]==0){
            topologicalUtil(g,g[s][i],visited,stk);
        }
    }
    stk.push_back(s);
}

void topologicalSort(vector<int> g[],int size){
    int visited[size]={0};
    vector<int> stk;
    for(int i=0;i<size;i++)
       if(visited[i]==0)
            topologicalUtil(g,i,visited,stk);
    for(int i=stk.size()-1; i>=0; i--){
        cout<<stk[i]<<" "; 
    }
    cout<<"\n";
    return;
}

int main(){
    vector<int> g[6];
    addEdge(g, 5, 2); 
    addEdge(g, 5, 0); 
    addEdge(g, 4, 0); 
    addEdge(g, 4, 1); 
    addEdge(g, 2, 3); 
    addEdge(g, 3, 1);
    topologicalSort(g,6);
}
