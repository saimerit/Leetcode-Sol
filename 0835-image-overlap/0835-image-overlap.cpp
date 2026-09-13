class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans= 0;
        for(int dx = -(n-1); dx <= (n-1); dx++){
            for(int dy = -(n-1); dy <= (n-1); dy++){
                int cnt = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        int nx = i + dx;
                        int ny = j + dy;
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n) if(img1[i][j] == 1 && img2[nx][ny] == 1) cnt++;
                    }
                }
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};