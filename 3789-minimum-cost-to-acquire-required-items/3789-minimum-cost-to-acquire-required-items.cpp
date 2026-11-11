class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int nj = min(need1, need2);
        long long op1 = ((long long)cost1 * (long long)need1) + ((long long)cost2 * (long long)need2);
        long long op2 = (long long)nj * (long long)costBoth + (long long)(need1 - nj) * (long long)cost1 + (long long)(need2 - nj) * (long long)cost2;
        nj = max(need1, need2);
        long long op3 = (long long)nj * (long long)costBoth;
        return min({op1, op2, op3});
    }
};