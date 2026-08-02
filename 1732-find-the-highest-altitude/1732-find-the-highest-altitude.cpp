class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int pref = 0;
        for(int i : gain){
            pref += i;
            ans = max(pref, ans);
        }
        return ans;
    }
};