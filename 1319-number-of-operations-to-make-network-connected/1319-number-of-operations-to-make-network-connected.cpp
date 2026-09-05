class Solution {
public:
    int findPar(int x, vector<int>& par){
        if(par[x] == x){
            return x;
        }
        return par[x] = findPar(par[x], par);
    }
    void unionBySize(int x, int y, vector<int>& par, vector<int>& size){
        int v_x = findPar(x, par);
        int v_y = findPar(y, par);
        if(v_x == v_y) return;
        if(size[v_x] < size[v_y]){
            par[v_x] = v_y;
            size[v_y] += size[v_x]; 
        }else{
            par[v_y] = v_x;
            size[v_x] += size[v_y];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int es = connections.size();
        if(es < n-1) return -1;
        vector<int> size(n, 1);
        vector<int> par(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        int ex = 0;
        for(auto const& e : connections){
            int u = e[0];
            int v = e[1];
            if(findPar(u, par) == findPar(v, par)){
                ex++;
            }else{
                unionBySize(u, v, par, size);
            }
        }
        int cc = 0;
        for(int i = 0; i < n; i++){
            if(par[i] == i){
                cc++;
            }
        }
        if(ex >= cc-1) return cc-1;
        return -1;
    }
};