class Solution {
public:

  int MOD = 1e9 + 7;
    int distinctSubseqII(string s){
        long long total = 1; // empty subsequence
        vector<long long> last(26, 0);
        for(char ch : s){
            long long old = total;
            total = (2 * total)%MOD;
            total = (total - last[ch - 'a'] + MOD)%MOD;
            last[ch - 'a'] = old;
        }
        return (total - 1 + MOD)%MOD;
    }
        
    
};