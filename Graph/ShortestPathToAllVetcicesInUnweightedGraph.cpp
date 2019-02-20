//Coding interview question by narasimha karumanchi

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void add(vector<int> g[],int u,int v){
    g[u].push_back(v);
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
    int vertices;
    int src;
    vertices=7;
    src=2;
    vector<int> g[7];
    add(g,0,1);
    add(g,0,3);
    add(g,1,3);
    add(g,1,4);
    add(g,2,0);
    add(g,2,5);
    add(g,3,5);
    add(g,3,6);
    add(g,4,6);
    add(g,6,5);
    
    shortest_path(g,vertices,src); 
    return 0;
}
