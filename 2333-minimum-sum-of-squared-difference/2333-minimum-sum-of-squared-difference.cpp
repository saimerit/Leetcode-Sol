class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff;
        for(int i = 0; i < n; i++){
            diff.push_back(abs(nums1[i] - nums2[i]));
        }
        int m = 0;
        for(int i : diff) if(m < i) m = i;
        vector<int> buck(m+1, 0);
        for(int i : diff) buck[i] += 1;
        long long  k = (long long) k1 + k2;
        for(int i = m; i > 0; i--){
            if(buck[i] > 0){
                long long moves = min((long long)buck[i], k);
                buck[i] -= moves;
                buck[i-1] += moves;
                k-=moves;
                if(k == 0) break;
            }
        }
        long long res = 0;
        for(long long i = 0; i <= m; i++){
            res += (long long)(buck[i] * i * i);
        }
        return res;
    }
};