#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool canplace(vector<int>&v,int n,int b,int sep){
    int birds=1;
    int previous=v[0];
    for(int i=1;i<n;i++){
        int current=v[i];
        if(current-previous>=sep){
            birds++;
            previous=v[i];
        }
        if(birds==b)return true;
    }
    return false;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    sort(v.begin(),v.end());
    int s=0;
    int e=v[n-1];
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(canplace(v,n,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
}
