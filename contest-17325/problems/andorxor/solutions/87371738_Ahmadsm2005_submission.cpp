#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
int acc[100002][21],XOR[100002],arr[100001];
unordered_map<int,vector<int>>lolz(100001);
int32_t main(){
iostream::sync_with_stdio(0),cin.tie(0);
int testcases,n,a,o,x;
cin>>testcases;
vector<int>empt;
while(testcases--){
cin>>n>>a>>o>>x;
int result=0;
for(int i=0;i<n;i++)
cin>>arr[i];
for(int i=0;i<n;i++){
for(int l=0;l<21;l++){
acc[i+1][l]=acc[i][l]+((arr[i]&(1<<l))?1:0);
}
XOR[i+1]=(XOR[i]^arr[i]);
lolz.insert({XOR[i+1],empt});
lolz[XOR[i+1]].push_back(i);
}
for(int i=0;i<n;i++){
int L=i+1,R=n,mid,ANDMIN=INT_MAX,ANDMAX=INT_MIN,ORMIN=INT_MAX,ORMAX=INT_MIN;
while(L<=R){
mid=(L+R)/2;
int CC=0;
//cout<<mid<<' ';
for(int l=0;l<21;l++){
int RESULT=acc[mid][l]-acc[i][l];
if(RESULT==(mid-i))
CC+=(1<<l);
}
//cout<<CC<<endl;
if(CC>a)
L=mid+1;
else if(CC<a)
R=mid-1;
else
R=mid-1,ANDMIN=min(ANDMIN,mid);
}
L=i+1,R=n;
while(L<=R){
mid=(L+R)/2;
int CC=0;
for(int l=0;l<21;l++){
int RESULT=acc[mid][l]-acc[i][l];
if(RESULT==(mid-i))
CC+=(1<<l);
}
if(CC>a)
L=mid+1;
else if(CC<a)
R=mid-1;
else
L=mid+1,ANDMAX=max(ANDMAX,mid);
}
L=i+1,R=n;
while(L<=R){
mid=(L+R)/2;
int CC=0;
for(int l=0;l<21;l++){
int RESULT=acc[mid][l]-acc[i][l];
if(RESULT)
CC+=(1<<l);
}
if(CC<o)
L=mid+1;
else if(CC>o)
R=mid-1;
else
R=mid-1,ORMIN=min(ORMIN,mid);
}
L=i,R=n;
while(L<=R){
mid=(L+R)/2;
int CC=0;
for(int l=0;l<20;l++){
int RESULT=acc[mid][l]-acc[i][l];
if(RESULT)
CC+=(1<<l);
}
if(CC<o)
L=mid+1;
else if(CC>o)
R=mid-1;
else
L=mid+1,ORMAX=max(ORMAX,mid);
}
auto itr=lower_bound(lolz[x].begin(),lolz[x].end(),max(ORMIN,ANDMIN)-1);
auto itr2=upper_bound(lolz[x].begin(),lolz[x].end(),min(ORMAX,ANDMAX)-1);
result+=max((int)(itr2-itr),(int)0);
//cout<<max(ORMIN,ANDMIN)-1<<' '<<min(ORMAX,ANDMAX)-1<<' ';
//cout<<result<<endl;
x^=arr[i];
}
cout<<result<<endl;
lolz.clear();
}
return 0;
}
