class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> mpp;
        for (int i = 0; i < s.size(); i++) {
            char original = s[i];
            char replacement = t[i];

            // now we will check if original is not already mapped
            if (!mpp.count(original)) { // not mapped
                bool alreadyM = false;

                // now check that replacements is not used
                for (auto& p : mpp) {
                    if (p.second == replacement) { // replacement marked with other
                        alreadyM = true;
                        break;
                    }
                }
                if (alreadyM) // if replacemnt marked ..already m is true and therefore ans is false 
                    return false;
                mpp[original] = replacement;
            } else { // org is mapped
                if (mpp[original] != replacement)
                    return false;
            }
        }
        return true;
    }
};