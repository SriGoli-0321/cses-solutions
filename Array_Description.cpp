#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define MOD int(1e9+7)

int main()
{
    int n, m;
    cin>>n>>m;
    vll a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    ll ans=1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            int count=0;
            if(i==0){
                if(a[i+1]>1 && a[i+1]<m+1)count=3;
                else if(a[i+1]==0 || a[i+1]==m)  count=2;
            }
            else if(i==n-1){
                if(a[i-1]>1 && a[i-1]<m+1)count=3;
                else if(a[i-1]==0 || a[i-1]==m)  count=2;
            }
            else{
                if(a[i-1]==a[i+1]){
                    if(a[i-1]>1 && a[i-1]<m+1)count=3;
                    else if(a[i-1]==0 || a[i-1]==m)  count=2;
                }
                else{
                    if(abs(a[i-1]-a[i+1])<=1)   count=2;
                    else    count=0;
                }
            }
            ans=ans*count;
        }
    }
    cout<<ans<<endl;
}