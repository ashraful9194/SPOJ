#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int phi[1000005];
int res[1000006];
void euler_phi(int n)
{
    phi[0]=0;
    phi[1]=1;
    for(int i=2; i<=n; i++) phi[i]=i;
    for(int i=2; i<=n; i++)
    {
        if(phi[i]!=i) continue;
        for(int j=i; j<=n; j+=i)
            phi[j]-=(phi[j]/i);
    }
}
void pre_calc(int n)
{
    for(int i=2; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
            res[j]+=(phi[i]*i);
    }

}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     euler_phi(1000000);
     pre_calc(1000000);
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
        cout<<(res[n]*n)/2+n<<endl;
     }
}
