#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
    if(y%x==0) return x;
    return gcd(y%x,x);
}

void findCount(vector<pair<int,int>> &v,int x,int y,int &j1,int &j2,int &target){
    if(x==target || y==target){
        return;
    }
    if(x==0){
        v.push_back(make_pair(j1,y));
        findCount(v,j1,y,j1,j2,target);
    }
    else if(y==j2){
        v.push_back(make_pair(x,0));
        findCount(v,x,0,j1,j2,target);
    }
    else{
        v.push_back(make_pair(x+y-min(j2,x+y),min(j2,x+y)));
        findCount(v,x+y-min(j2,x+y),min(j2,x+y),j1,j2,target);
    }
}

int main(){
    int jug1=3,jug2=5,target=4;
    if(target%gcd(jug1,jug2)!=0){
        cout<<"target cann't be acheived\n";
        return 0;
    }
    vector<pair<int,int>> v1,v2;
    v1.push_back(make_pair(0,0));
    v2.push_back(make_pair(0,0));
    findCount(v1,0,0,jug1,jug2,target);
    findCount(v2,0,0,jug2,jug1,target);
    cout<<v1.size()-1<<"::";
    for(int i=0;i<v1.size();i++){
        cout<<"["<<v1[i].first<<" "<<v1[i].second<<"]";
    }
    cout<<"\n";
    cout<<v2.size()-1<<"::";
    for(int i=0;i<v2.size();i++){
        cout<<"["<<v2[i].first<<" "<<v2[i].second<<"]";
    }
    cout<<"\n";
}
