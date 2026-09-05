class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ind(n+1);
        for(auto const& e : trust){
            ind[e[0]]--;
            ind[e[1]]++;
        }
        for(int i = 1; i < n+1; i++){
            if(ind[i] == n-1) return i;
        }
        return -1;
    }
};