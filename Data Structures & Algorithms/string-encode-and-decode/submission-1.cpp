class Solution {
public:

    string encode(vector<string>& strs) {
        // concatenate the size 
        string s="";
        for(string it:strs)
        {
            int len= it.size();
            s+=to_string(len)+"#"+it;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i=0;
        while(i<s.size())
        {
            int j= s.find('#',i);

            int len = stoi(s.substr(i, j-i));

            string str = s.substr(j+1, len);

            strs.push_back(str);

            i=j+1+len;
        }
        return strs;
    }
};
