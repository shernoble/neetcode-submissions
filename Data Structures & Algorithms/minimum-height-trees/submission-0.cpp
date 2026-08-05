class Solution {
public:
    int helper(int node, vector<vector<int>> &adj)
    {
        //find distance of all nodes from this node
        vector<int> dist(adj.size(),INT_MAX);
        queue<int> q;
        q.push(node);
        int maxdist = 0;
        dist[node] = 0;
        while(!q.empty())
        {
            int top = q.front();
            int distance = dist[top];
            q.pop();
            maxdist = max(maxdist, distance);
            dist[top] = 0;
            for(auto neigh : adj[top])
            {
                if(dist[neigh] != 0)
                {
                    //not visited
                    dist[neigh] = distance + 1;
                    q.push(neigh);
                }
            }
        }
        return maxdist;
    };
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //make every node the root and calculate the height
        vector<vector<int>> adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> output;
        int mindist = INT_MAX;

        for(int i=0;i<n;i++)
        {
            //check for each node as root
            int root = i;
            //find max distance
            int res = helper(root,adj);
            if(res<mindist)
            {
                mindist = res;
                output.clear();
            }
            if(res == mindist)
            {
                output.push_back(root);
            }
        }
        return output;
    }
};