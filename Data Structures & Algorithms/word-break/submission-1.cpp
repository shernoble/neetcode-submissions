struct Node{
    Node* links[26];
    bool flag = false;
    // methods
    bool check(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node* node)
    {
        // set the node link
        links[ch-'a']=node;
    }
    Node* getLink(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }

};

class Trie{
    private: Node* root;
    public:
    Trie()
    {
        root = new Node();
    }
    bool isPresent(string s)
    {
        Node* node = root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->check(s[i])) return false;
            node=node->getLink(s[i]);
        }
        return node->isEnd();
    }
    bool isPrefix(string s)
    {
        Node* node = root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->check(s[i])) return false;
            node=node->getLink(s[i]);
        }
        return true;
    }
    void insert(string s)
    {
        Node* node = root;
        for(int i=0;i<s.size();i++)
        {
            // if node link doesnt exist, create
            if(!node->check(s[i]))
            {
                // create
                node->put(s[i],new Node());
            }
            node=node->getLink(s[i]);
        }
        node->setEnd();
    }
};

class Solution {
public:
    Trie* trie;
    vector<int> dp; // Memoization array
    
    bool helper(int start, const string& s) {
        if (start == s.size()) return true; // Reached the end successfully

        if (dp[start] != -1) return dp[start]; // Return memoized result if exists

        int n = s.size();
        for (int i = start; i < n; i++) {
            if (trie->isPresent(s.substr(start, i - start + 1))) {
                if (helper(i + 1, s)) {
                    return dp[start] = 1; // Store result in dp and return
                }
            }
        }
        
        return dp[start] = 0; // Store result as 0 if no segmentation is possible
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Create Trie with all the words in the dictionary
        trie = new Trie();
        for (const auto& word : wordDict) {
            trie->insert(word);
        }
        
        dp.assign(s.size(), -1); // Initialize dp array with -1 (unvisited)
        
        // Use the helper function to determine if the word break is possible
        return helper(0, s);
    }
};
