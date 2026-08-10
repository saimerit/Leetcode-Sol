class Solution {
public:
    vector<int> memo = vector<int>(100001, -1);
    bool dp(int rem){
        if(rem == 0) return false;
        if(memo[rem] != -1) return memo[rem];
        for(int i = 1; i*i <= rem; i++){
            if(!dp(rem - i*i)) return memo[rem] = 1;
        }
        return memo[rem] = 0;
    }

    bool winnerSquareGame(int n) {
        return dp(n);
    }
};