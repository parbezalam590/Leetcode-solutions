class Solution {
public:
    int t[101][101];

    bool solve(int i , int open , string& s , int n) {
        if(i == n) {
            return open == 0;
        }

        if(t[i][open] != -1) {
            return t[i][open];
        }
        bool isvalid = false;

        if(s[i] == '*'){
            isvalid |= solve(i+1 , open+1, s,n);
            isvalid |= solve(i+1 , open, s,n);

            if(open > 0 ) {
                isvalid |= solve(i+1, open-1,s,n);
            }
        }
        else if(s[i] == '(') {
            isvalid = solve(i+1 , open+1, s,n);
        }
        else if(open > 0) {
            isvalid = solve(i+1 , open-1, s,n);
        }
        return t[i][open] = isvalid;
    }
    bool checkValidString(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0 , 0 , s , n);
    }
};