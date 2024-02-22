#include <bits/stdc++.h>
using namespace std;

/* check EDGE cases  */
/* read question until the idea is clear  */
typedef long long int ll ;
const int mx = 1e7+123;
ll ara[mx];
//output= 1ll * output//
   
void solve(){
   int n;
   cin>>n;
   vector<pair<int,int>>ara1;
   vector<pair<int,int>>ara2;
   for (int i = 0; i < n; i++)
   {
        int x;
        cin>>x;
        ara1.push_back({i,x});
   }
   for (int i = 0; i < n; i++)
   {
        int x;
        cin>>x;
        ara2.push_back({i,x});
   }
   

   for (int i = 0; i < n; i++)
   {
        int t = ara1[i].second;

        int pos = lower_bound(ara2.begin(),ara2.end(),t) - ara2.begin();

        if(pos>n){
            cout<<"nai"<<" ";
        }else{
            cout<<ara2[pos].first<<" ";
        }
   }
   cout<<endl;
   


   

}


int f = 1;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    if (f == 0) solve();
    else{
        int t;
        cin>>t;
        while(t--){
            solve();
        }
    }
 cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC <<" ms " << endl; 
/* edgerunner */
}