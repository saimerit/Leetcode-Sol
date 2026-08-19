class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> rn;
        unordered_map<char, int> m;
        for(char i : ransomNote){
            rn[i] += 1;
        }
        for(char i : magazine){
            m[i] += 1;
        }
        for(auto const& [key, val] : rn){
            if(m[key] < val) return false;
        }
        return true;
    }
};