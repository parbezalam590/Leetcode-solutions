class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else { // -ve elements
            while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
            } // equal element exluding -ve
            if(!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
            }
            else if (st.empty() || st.top() < 0) { // is st is empty or already have -ve weight . add more  
                    st.push(asteroids[i]);
            }
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size()-1 ; i >= 0 ; i--) {
            ans[i] = st.top();
            st.pop();
        } 
        return ans;
    }
};