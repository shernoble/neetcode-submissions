class Solution {

private:

    bool dfs(int x, int y, int idx, string word, vector<int> &visited,
    vector<vector<char>> &grid)
    {
        //sanity check
        if(x<0 || y<0 || x == grid.size() || y == grid[0].size()) return false;
        //if idx in word doesnt match the current letter - ret false
        if(visited[y + grid[0].size()*x]) return false;
        if(word[idx] != grid[x][y]) return false;
        //only true case
        if(idx == word.size()-1) return true;
        visited[y + grid[0].size()*x] = 1;
        cout<<grid[x][y]<<" ";
        bool found =  (dfs(x-1,y,idx+1,word,visited,grid) ||
                dfs(x+1,y,idx+1,word,visited,grid) ||
                dfs(x,y+1,idx+1,word,visited,grid) ||
                dfs(x,y-1,idx+1,word,visited,grid));
        
        visited[y + grid[0].size()*x] = 0;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        

        for(int x = 0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                if(board[x][y] == word[0])
                {
                    vector<int> visited(n*m);
                    bool val = dfs(x,y,0,word,visited,board);
                    if(val) return true;
                }
            }
        }
        return false;
    }
};
