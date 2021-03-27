/*
https://leetcode.com/problems/accounts-merge/
*/

class DSU {
    private:
    int prnt[10004];
    
    public:
    
    DSU() {
        for(int i=0;i<10004;i++) {
            prnt[i] = i;
        }
    }
    
    int find(int val) {
        if(val != prnt[val])
            return find(prnt[val]);
        return val;
    }
    
    void _union(int v1,int v2) {
        prnt[find(v1)] = find(v2);
    }
    
};

class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        DSU dsu;
        unordered_map<string,string> emToNm;
        unordered_map<string,int> emToId;
        
        int id = 0;
        for(auto it : accounts) {
            for(int i=1;i<it.size();i++) {
                emToNm[it[i]] = it[0];
                if(emToId.find(it[i]) == emToId.end())
                    emToId.insert(make_pair(it[i], id++));
                dsu._union(emToId[it[1]],emToId[it[i]]);
            }
        }
        
        unordered_map<int,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto it : emToNm) {
            int idx = dsu.find(emToId[it.first]);
            if(mp.find(idx) == mp.end()) {
                mp.insert(make_pair(idx,vector<string>()));
                mp[idx].push_back(it.second);
            }
            mp[idx].push_back(it.first);
        }
        
        vector<string> tmp;
        for(auto it : mp) {
            sort(it.second.begin()+1,it.second.end());
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};
