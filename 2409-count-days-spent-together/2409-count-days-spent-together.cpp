class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> ps(13, 0);
        for(int i = 1; i < 13; i++) ps[i] = ps[i-1] + days[i];
        auto toDayOfYear = [&](const string& date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3));
            return ps[month - 1] + day;
        };

        int aa = toDayOfYear(arriveAlice);
        int la = toDayOfYear(leaveAlice);
        int ab = toDayOfYear(arriveBob);
        int lb = toDayOfYear(leaveBob);

        int res = min(la, lb) - max(aa, ab) + 1;
        return max(res, 0);
    }
};