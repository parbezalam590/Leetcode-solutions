class Solution {
public:

    void backtrack(int n , vector<string> &ans , string curr , int open , int close) {
        if(curr.length() == 2 * n) { // as total size becomes double when including both open and close braces 
            ans.push_back(curr);
            return;
        }
        if(open < n ) { // we can add more open braces  
            backtrack(n , ans , curr + "(" , open + 1 , close);
        }
        if(close < open ) { // add close only when close is lelss than open 
            backtrack(n , ans , curr + ")" , open , close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        backtrack(n , ans , "" , 0 , 0 );
        return ans;

        
    }
};