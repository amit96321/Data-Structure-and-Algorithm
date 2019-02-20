//Coding interview question by narasimha karumanchi

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//By default heap is max heap and if heap of pair then order is done by 1st element here we need min heap
// and order by 2nd element
struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void add(vector<pair<int,int>> g[],int u,int v,int weight){
    g[u].push_back(make_pair(v,weight));
    return;
}

void shortest_path(vector<pair<int,int>> g[],int n,int src){
    int distance[n],path[n],i;
    pair<int,int> temp;
    for(i=0;i<n;i++) distance[i]=-1; //-1 is used to track weather the node is visited or not
    distance[src]=0;
    path[src]=src;  //path is used to store the vertex just a level before any vertex
    priority_queue<pair<int,int>, vector<pair<int,int> >, compare> pq;
    pq.push(make_pair(src,0));
    while(!pq.empty()){
        temp=pq.top();
        pq.pop();    
        //it is guranteed that node which is popped has minimal distance from source but in case of negative
        //weights popped node can have less distance than current in future hence dijkstra does not work 
        //work in case of negative weight edges
        //although if there is negative weight cycle shortest path has no any meaning
        //see bellman ford algorithm for negative weight edges
        
        for(i=0;i<g[temp.first].size();i++){
            //if node is visited 1st then just make its distance equal to sum of distance upto previous node
            //and weight of path from previous to current node
            if(distance[g[temp.first][i].first]==-1){
                pq.push(make_pair(g[temp.first][i].first,g[temp.first][i].second+distance[temp.first]));
                distance[g[temp.first][i].first]=g[temp.first][i].second+distance[temp.first];
                path[g[temp.first][i].first]=temp.first;
            }
            else if(distance[g[temp.first][i].first]>distance[temp.first]+g[temp.first][i].second){
                distance[g[temp.first][i].first]=distance[temp.first]+g[temp.first][i].second;
                pq.push(make_pair(g[temp.first][i].first,distance[g[temp.first][i].first]));
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
    vertices=5;
    src=0;
    vector<pair<int,int>> g[vertices];
    add(g,0,1,4);
    add(g,0,2,1);
    add(g,1,4,4);
    add(g,2,1,2);
    add(g,2,3,4);
    add(g,3,4,4);
    
    shortest_path(g,vertices,src); 
    return 0;
}
