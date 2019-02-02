//this program prints the path as well.At every level of BFS we are creating new vector from the previous level BFS by extending the current element and then putting all vectors in queue  

#include<bits/stdc++.h>
using namespace std;
bool p[10000];

bool visited[10000];

void seive(){
    p[0]=p[1]=false;
    for(int i=2;i<10000;i++){
        if(p[i]==true){
            for(int j=i*2;j<10000;j+=i){
                p[j]=false;
            }
        }
    }
}

void find(queue<vector<int>> q,int n2,int level){
    int len=q.size(),i,j,x;
    vector<int> v;
    for(j=0;j<len;j++){
        v=q.front();
        x=v[v.size()-1];
        if(v.size()==0) return;
        if(x==n2){
            cout<<level<<":";
            for(i=0;i<v.size();i++) cout<<v[i]<<" ";
            cout<<"\n";
            return;
        }
        // This loop is used to change 1st digit in no from 0 to 9 
        for(i=0;i<=9;i++){
            if((x%1000)+(i*1000)>1000 && p[(x%1000)+(i*1000)] && !visited[(x%1000)+(i*1000)]){
                visited[(x%1000)+(i*1000)]=true;
                v=q.front();
                v.push_back((x%1000)+i*1000);
                q.push(v);
            }
        }
        // This loop is used to change 2nd digit in no from 0 to 9 
        for(i=0;i<=9;i++){
            if((x/1000)*1000+(x%100)+i*100>1000 && p[(x/1000)*1000+(x%100)+i*100] && !visited[(x/1000)*1000+(x%100)+i*100]){
                visited[(x/1000)*1000+(x%100)+i*100]=true;
                v=q.front();
                v.push_back((x/1000)*1000+(x%100)+i*100);
                q.push(v);
            }
        }
        // This loop is used to change 3rd digit in no from 0 to 9
        for(i=0;i<=9;i++){
            if((x/100)*100+(x%10)+i*10>1000 && p[(x/100)*100+(x%10)+i*10] && !visited[(x/100)*100+(x%10)+i*10]){
                visited[(x/100)*100+(x%10)+i*10]=true;
                v=q.front();
                v.push_back((x/100)*100+(x%10)+i*10);
                q.push(v);
            }
        }
         // This loop is used to change 4th digit in no from 0 to 9
        for(i=1;i<=9;i++){
            if((x/10)*10+i>1000 && p[(x/10)*10+i] && !visited[(x/10)*10+i]){
                visited[(x/10)*10+i]=true;
                v=q.front();
                v.push_back((x/10)*10+i);
                q.push(v);
            }
        }
        q.pop();
    }
    find(q,n2,level+1);
}

int main(){
    int n1,n2,i;
    cin>>n1>>n2;
    for(i=0;i<10000;i++){
      p[i]=true; // list of prime numbers
      visited[i]=false;  //make track of visited nodes. here nodes are numbers
    } 
    seive();
    queue<vector<int>> q;
    vector<int> v;
    v.push_back(n1);
    q.push(v); // at start we are having only one vector in queue
    visited[n1]=true; // make starting vertex visited
    find(q,n2,0);
}
