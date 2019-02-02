//Coding interview question by narasimha karumanchi

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void add(vector<int> g[],vector<int> &indegree,int u,int v){
    g[u].push_back(v);
    indegree[v]++;
    return;
}

void topological_sort(vector<int> g[],vector<int> &indegree,int n){
    queue<int> q;
    int i,x,topological_order[n],count=0;
    for(i=0;i<n;i++){
        if(indegree[i]==0) q.push(i); 
    }
    while(!q.empty()){
        x=q.front();
        q.pop();
        topological_order[x]=++count;
        for(i=0;i<g[x].size();i++){
            if(--indegree[g[x][i]]==0) q.push(g[x][i]);
        } 
    }
    if(count!=n){
        cout<<"graph contains cycle\n";
        return;
    }
    for(i=0;i<n;i++){
        cout<<i<<":"<<topological_order[i]<<"\n";
    }
}

int main(){
    vector<int> g[8];
    vector<int> indegree(8);
    for(int i=0;i<8;i++) indegree[i]=0;
    add(g,indegree,0,3);
    add(g,indegree,0,4);
    add(g,indegree,1,3);
    add(g,indegree,2,4);
    add(g,indegree,2,7);
    add(g,indegree,3,5);
    add(g,indegree,3,6);
    add(g,indegree,3,7);
    add(g,indegree,4,6);
    //add(g,indegree,5,0); //this edge after adding graph becomes cyclic
    
    topological_sort(g,indegree,8);
    return 0;
}
