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
int phi[1000006];
int res[1000006];
void euler_phi(int n)
{
       for(int i=0; i<=n; i++) phi[i]=i;
       for(int i=2; i<=n; i++)
       {
           if(phi[i]!=i) continue;
           for(int j=i; j<=n; j+=i)
            {

                phi[j]-=(phi[j]/i);
            }
       }
}
void pre_calc(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
            {
                if(i==j) continue;
                res[j]+=(phi[j/i]*i);
            }
    }
   for(int i=1; i<=n; i++)
        res[i]+=res[i-1];
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     euler_phi(1000001);
     pre_calc(1000001);

     while(1)
     {
         int n;
         cin>>n;
         if(n==0) break;
         cout<<res[n]<<endl;
     }
}

