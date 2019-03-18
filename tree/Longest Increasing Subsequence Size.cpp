//Longest Increasing subsequence on O(log(n!))==O(n logn)

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &v,int s,int e,int key){
    if(s==e) return s;
    int mid=(s+e)/2;
    if(key>v[mid] && key<=v[mid+1]) return mid+1;
    else if(key>v[mid+1]) return find(v,mid+1,e,key);
    else return find(v,s,mid,key);
}

int lis(int a[],int n){
    if(n==0) return 0;
    vector<int> v;
    v.push_back(a[0]);      //start the vector by 1st element
    for(int i=1;i<n;i++){
        if(a[i]>v[v.size()-1]) v.push_back(a[i]);
        else if(a[i]<v[0]) v[0]=a[i];
        else {
            int index=find(v,0,v.size()-1,a[i]);   //find returns the index of that element
                                                //whose value is less than or equal to the element
                                                // and strictly greater than the previous element
            v[index]=a[i];              //after getting the element just replace the vector element
                                        //at that elemnt by array element
        }
        /*for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<"\n";*/
    }
    
    return v.size();
}

int main(){
    int a[]={2, 5, 3, 7, 11, 8, 10, 13, 6};
    cout<<lis(a,sizeof(a)/sizeof(a[0]))<<"\n";
    return 0;
}
