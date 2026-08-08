class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
          //We will do a pre computation that in word1 how many chnaracters of word2 are matching thill that index
        vector<int> countMatchingTillIndex((word1.size()+1), 0);
        int i = word1.size()-1;
        int j = word2.size()-1;
        int countFound = 0;

        while(i >= 0){
            if(j >= 0 && word1[i] == word2[j]){
                countFound++;
                j--;
            }
            countMatchingTillIndex[i] = countFound;
            i--;
        }


        i = 0;
        j = 0;
        bool canChange = true;
        vector<int> ans;

        while(i < word1.size() && j < word2.size()){
            if((word1[i] == word2[j]) || (canChange && countMatchingTillIndex[i+1] >= (word2.size()-1-j))){
                ans.push_back(i);
                if(word1[i] != word2[j]) canChange = false;
                j++;
            }
            
            i++;
        }

        if(j < word2.size()){
            ans.clear();
        }

        return ans;
    
        

    }
};