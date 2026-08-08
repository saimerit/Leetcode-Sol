class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        if(word1.empty() || word2.empty()) return {};
        int n = static_cast<int>(word1.size()), m = static_cast<int>(word2.size());
        vector<int> last(m, -1);
        int j = m-1;
        int i = n-1;
        while(i >= 0 &&  j >= 0){
            if(word1[i] == word2[j]){
                last[j] = i;
                j--;
            }
            i--;
        }
        bool ch = false;
        vector<int> r(m);
        j = 0;
        for(i = 0; i < n; ++i){
            if(j == m) break;
            if(word1[i] == word2[j]){
                r[j++] = i;
            }else if(!ch && (j + 1== m || last[j+1] > i)){
                r[j++] = i;
                ch = true;
            }
        }
        return (j == m) ? r : vector<int>();
    }
};