//segment tree for minimum range query


#include<bits/stdc++.h>
using namespace std;

void constructSegmentTree(int a[],int segmentTree[],int s,int e,int pos){
    if(s==e){
        segmentTree[pos]=a[s];
        return;
    }
    int mid=(s+e)/2;
    constructSegmentTree(a,segmentTree,s,mid,pos*2+1);  //left child at pos*2+1
    constructSegmentTree(a,segmentTree,mid+1,e,pos*2+2); //right child at pos*2+2
    segmentTree[pos]=min(segmentTree[pos*2+1],segmentTree[pos*2+2]);
}

int rangeQuery(int segmentTree[],int startRange,int endRange,int s,int e,int pos){
    if(s>=startRange && e<=endRange) return segmentTree[pos];  //total overlap
    if(s>endRange || e<startRange) return INT_MAX;            //no overlap
    int mid=(s+e)/2; 
    return min(rangeQuery(segmentTree,startRange,endRange,s,mid,pos*2+1),
                rangeQuery(segmentTree,startRange,endRange,mid+1,e,pos*2+2));  //partial overlap
}

int main(){
    int a[]={1,2,-1,0,1,6,4,8,7};
    int n=sizeof(a)/sizeof(a[0]),i;
    
    //if n is power of 2 then size of segment tree=2*n-1
    //else find next power of 2 let x(for eg. if n=5 next power of 2=8) then size of 
    //segment tree will be 2*x-1
    int s=2*(int)pow(2,ceil(log2(n*1.0)))-1;
    int segmentTree[s];
    for(i=0;i<s;i++) segmentTree[i]=INT_MAX;
    constructSegmentTree(a,segmentTree,0,n-1,0);  //here last argument 0 indicate root of segment tree
    //for(i=0;i<s;i++) cout<<segmentTree[i]<<" ";
    int startRange=3,endRange=6;
    cout<<rangeQuery(segmentTree,startRange,endRange,0,n-1,0); //here last argument 0 indicate root of segment tree
    
    return 0;
}
