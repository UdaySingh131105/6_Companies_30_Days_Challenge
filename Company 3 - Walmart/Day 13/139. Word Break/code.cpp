/*
bool solve(int idx,string s,set<string>&se,int prev,map<pair<int,int>,bool>&dp){
    
    if(idx>=s.length()){
        return true;
    }
    
    if(idx==s.length()-1){
        
        string str = s.substr(prev+1,idx+1);
        
        if(se.find(str)!=se.end()){
            return true;
        }
        else{
            return false;
        }
    }
    
    if(dp.count({idx,prev})>0){
        return dp[{idx,prev}];
    }
    
    
    for(int i=idx;i<s.length();i++){
        string str = s.substr(prev+1,i+1-prev-1);
        
        if(se.find(str)!=se.end()){
            
            bool val1 = solve(i+1,s,se,i,dp);
            
            bool val2 = solve(i+1,s,se,prev,dp);
            
            return dp[{idx,prev}] = val1 | val2;
        }
    }
    return false;
    
}

bool wordBreak(string s, vector<string>& wordDict) {
    
    set<string> se;
    
    for(auto word : wordDict){
        se.insert(word);
    }
    
    map<pair<int,int>,bool> dp;
    
    return solve(0,s,se,-1,dp);
}*/