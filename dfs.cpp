
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> g[],int s,int e){
    g[s].push_back(e);
    //g[e].push_back(s); if not directed graph
}

void dfsUtil(vector<int> g[],int s,int visited[]){
    visited[s]=1;
    vector<int> v;
    v.push_back(s);
    cout<<s<<" ";
    int flag;
    while(v.size()!=0){
        flag=0;
        for(int i=0;i<g[v[v.size()-1]].size();i++){
            if(visited[g[v[v.size()-1]][i]]==0){
                visited[g[v[v.size()-1]][i]]=1;
                cout<<g[v[v.size()-1]][i]<<" ";
                v.push_back(g[v[v.size()-1]][i]);
                flag=1;
                break;
            }
        }
        if(flag==0){
            v.pop_back();
        }
    }
}

void dfs(vector<int> g[],int size){
    int visited[size]={0};
    for(int i=2;i<size;i++)
        if(visited[i]==0)
            dfsUtil(g,2,visited);
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
    
    dfs(g,4);
}
