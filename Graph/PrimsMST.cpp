//Coding interview question by narasimha karumanchi
//A group of edges that connects two set of vertices in a graph is called cut in graph theory.
//So, at every step of Prim’s algorithm, we find a cut (of two sets, one contains the vertices
//already included in MST and other contains rest of the verices), pick the minimum weight edge
//from the cut and include this vertex to MST Set (the set that contains already included vertices).

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
    g[v].push_back(make_pair(u,weight));
    return;
}

void shortest_path(vector<pair<int,int>> g[],int n){
    int distance[n],path[n],i;
    //visited is used to trace that the src of min cut edges will not be visited again
    bool visited[n];
    for(i=0;i<n;i++) visited[i]=false;
    visited[0]=true;
    pair<int,int> temp;
    for(i=0;i<n;i++) distance[i]=-1; //-1 is used to track weather the node is visited or not
    distance[0]=0;
    path[0]=0;  //path is used to store the vertex just a level before any vertex
    priority_queue<pair<int,int>, vector<pair<int,int> >, compare> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        temp=pq.top();
        pq.pop();
        //once a node is popped that node's previous vertex will not be relaxed later
        visited[temp.first]=true; 

        for(i=0;i<g[temp.first].size();i++){
            if(!visited[g[temp.first][i].first] && (distance[g[temp.first][i].first]==-1 || distance[g[temp.first][i].first]>g[temp.first][i].second)){
                distance[g[temp.first][i].first]=g[temp.first][i].second;
                pq.push(make_pair(g[temp.first][i].first,distance[g[temp.first][i].first]));
                path[g[temp.first][i].first]=temp.first;

            }
        }
    }
    for(i=1;i<n;i++){
        cout<<path[i]<<"->"<<i<<"::"<<distance[i]<<"\n";
    }
}

int main(){
    int vertices;
    int src;
    vertices=9;
    src=0;
    vector<pair<int,int>> g[vertices];
    add(g,0,1,4);
    add(g,0,7,8);
    add(g,1,7,11);
    add(g,1,2,8);
    add(g,7,6,1);
    add(g,7,8,7);
    add(g,2,8,2);
    add(g,8,6,6);
    add(g,2,5,4);
    add(g,2,3,7);
    add(g,6,5,2);
    add(g,3,5,14);
    add(g,3,4,9);
    add(g,5,4,10);
    
    shortest_path(g,vertices); 
    return 0;
}
