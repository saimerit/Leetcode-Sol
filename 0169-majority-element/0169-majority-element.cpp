class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int frq = 0, ans = 0;
        for(int i : nums){
            if(frq == 0) ans = i;
            if(ans == i) frq++;
            else frq--;
        }
        return ans;
    }
};