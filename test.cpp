#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  ll  long long
#define fastread() (ios_base::sync_with_stdio(0),cin.tie(0));
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1e9+7;
void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n+1);
    vector<ll> b(n+1);
    map<ll,ll> mp;
    for(ll i = 1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
    }
    for(ll i = 1;i<=n;i++)
    {
        cin>>b[i];
    }
    bool bad=false;
    bool nisi=false;
    stack<ll> cur;
    cur.push(0);
    ll cnt=0;
    for(ll i=1;i<=n;i++)
    {
        if(mp[b[i]]==0 || mp[b[i]]<=cur.top())
        {
            if(nisi && bad)
            {
                if(cur.size()==1)
                {
                    cnt=n;
                    break;
                }
                cnt+=2;
                // cout<<i<<" "<<cnt<<endl;
                cur.pop();
                continue;
            }
            bad=true;
            cnt++;
        }
        else 
        {
            nisi=true;
            cur.push(i);
        }
        // cout<<i<<" "<<cnt<<endl;
    }
    cout<<cnt<<endl;
   
    
}
 
int main()
{
    fastread();
    ll t;
    cin>>t;
    ll tt = 1;
    while(t--)
    {
        cout<<"Case "<<tt<<": ";
       solve();
       tt++;
       
    }
     
    return 0;
}