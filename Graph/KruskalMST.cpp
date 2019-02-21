//Coding interview question by narasimha karumanchi
//Union By Rank and Path Compression is used

#include<bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct edge{
    int src;
    int dest;
    int weight;
}edge;

typedef struct subset{
    int parent;
    int rank;   //rank is height of tree, initially there will be n tree each of height 0
}subset;

bool comp(edge x,edge y){
    return x.weight<y.weight;
}

int findParent(subset s[],int x){
    if(s[x].parent==x) return x;
    return findParent(s,s[s[x].parent].parent);   //this statement is used for path compression
}

void findUnion(subset s[],int src,int dest){
    int x=findParent(s,s[src].parent);
    int y=findParent(s,s[dest].parent);
    if(x==y) return;
    //Attach smaller rank tree under root of high rank tree 
    else if(s[x].rank>s[y].rank){
        s[y].parent=s[x].parent;
    }
    else if(s[x].rank<s[y].rank){
        s[x].parent=s[y].parent;
    }
    else {
        s[x].parent=s[y].parent;
        s[y].rank++; //if both tree of same rank will be merged height will be increased by 1
    }
}

void mst(vector<edge> v,int n){
    int count=0,i;
    subset s[n];
    for(i=0;i<n;i++){
        s[i].parent=i;
        s[i].rank=0;
    }
    for(i=0;i<v.size();i++){
        if(findParent(s,v[i].src)==findParent(s,v[i].dest)) continue;
        cout<<v[i].src<<"->"<<v[i].dest<<"::"<<v[i].weight<<"\n";
        findUnion(s,v[i].src,v[i].dest);
        count++;
        if(count==n-1) break;
    }
}

int main(){
    edge x;
    vector<edge> e;
    int vertices =9;
    x.src=0; x.dest=1; x.weight=4; e.push_back(x);
    x.src=0; x.dest=7; x.weight=8; e.push_back(x);
    x.src=1; x.dest=7; x.weight=11; e.push_back(x);
    x.src=1; x.dest=2; x.weight=8; e.push_back(x);
    x.src=7; x.dest=6; x.weight=1; e.push_back(x);
    x.src=7; x.dest=8; x.weight=7; e.push_back(x);
    x.src=2; x.dest=8; x.weight=2; e.push_back(x);
    x.src=8; x.dest=6; x.weight=6; e.push_back(x);
    x.src=2; x.dest=5; x.weight=4; e.push_back(x);
    x.src=2; x.dest=3; x.weight=7; e.push_back(x);
    x.src=6; x.dest=5; x.weight=2; e.push_back(x);
    x.src=3; x.dest=5; x.weight=14; e.push_back(x);
    x.src=3; x.dest=4; x.weight=9; e.push_back(x);
    x.src=5; x.dest=4; x.weight=10; e.push_back(x);
    sort(e.begin(),e.end(),comp);
    mst(e,vertices);
    
    return 0;
}
