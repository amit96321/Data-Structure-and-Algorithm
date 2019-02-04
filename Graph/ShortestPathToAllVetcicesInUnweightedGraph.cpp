//Coding interview question by narasimha karumanchi

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void add(vector<int> g[],vector<int> &indegree,int u,int v){
    g[u].push_back(v);
    indegree[v]++;
    return;
}

void shortest_path(vector<int> g[],int n,int src){
    int distance[n],path[n],temp,i;
    for(i=0;i<n;i++) distance[i]=-1;
    distance[src]=0;
    path[src]=src;  //path is used to store the vertex just a level before any vertex
    std::queue<int> q;
    q.push(src);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        for(i=0;i<g[temp].size();i++){
            if(distance[g[temp][i]]==-1){
                q.push(g[temp][i]);
                distance[g[temp][i]]=distance[temp]+1;
                path[g[temp][i]]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<i<<":"<<distance[i]<<" "<<path[i]<<"\n";
    }
}

int main(){
    vector<int> g[7];
    vector<int> indegree(7);
    for(int i=0;i<7;i++) indegree[i]=0;
    add(g,indegree,0,1);
    add(g,indegree,0,3);
    add(g,indegree,1,3);
    add(g,indegree,1,4);
    add(g,indegree,2,0);
    add(g,indegree,2,5);
    add(g,indegree,3,5);
    add(g,indegree,3,6);
    add(g,indegree,4,6);
    add(g,indegree,6,5);
    
    shortest_path(g,7,2);
    return 0;
}
