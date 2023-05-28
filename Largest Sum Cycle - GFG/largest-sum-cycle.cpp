//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    long long ans = -1;
    long long dfs(int n, vector<vector<int>>&adj, vector<int>& vst, vector<long long>& sm)
    {
        vst[n] = 1;
        sm[n] += n;
        
        for (auto i : adj[n])
        {
            if (!vst[i])
            {
                sm[i] += sm[n];
                dfs(i, adj, vst, sm);
            }
            else if (vst[i] == 1)
                ans = max(ans, sm[n] - sm[i] + i);
        }
        
        vst[n]++;
    }
    
    long long largestSumCycle(int n, vector<int> ed)
    {
        vector<vector<int>> adj(n);
        vector<long long> sm(n, 0);
        for (int i = 0; i < n; ++i)
            if (ed[i] != -1)
                adj[i].emplace_back(ed[i]);
        
        vector<int> vst(n, 0);
        for (int i = 0; i < n; ++i)
            if (!vst[i])
                dfs(i, adj, vst, sm);
        
        return ans;
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends