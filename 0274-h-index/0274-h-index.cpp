class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buck(n+1, 0);
        for(int cite : citations){
            buck[min(n, cite)]++;
        }
        int citation = 0;
        for(int i = n; i >= 0; i--){
            citation += buck[i];
            if(citation>=i) return i;
        }
        return 0;
    }
};