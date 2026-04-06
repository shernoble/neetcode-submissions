class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis,int parent)
    {
        vis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                // parent= node;
                if(dfs(it,adj,vis, node)) return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // keep adding edge to adjacency list and check if cycle is there
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        // vector<int> vis(n+1,0);
        // vector<int> ans = {};

        for (auto& edge : edges) {
            // Clear visited array for each new edge check
            vector<int> vis(n + 1, 0);

            // Temporarily add the edge to adjacency list
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            // Check for cycle with this edge
            if (dfs(edge[0], adj, vis, -1)) {
                return edge;
            }
        }
        return {};

    }
};
