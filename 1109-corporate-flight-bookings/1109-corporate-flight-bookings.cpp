class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for(vector<int> book : bookings){
            for(int i = book[0] - 1; i < book[1]; i++){
                ans[i] += book[2];
            }
        }
        return ans;
    }
};