class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n, 0);
        queue<int>q;
        int ret = 0;
        for(int i = 0; i<n; ++i){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    visited[temp] = 1;
                    for(int j = 0; j < n; ++j){
                        if(!visited[j] && isConnected[temp][j] == 1){
                            q.push(j);
                        }
                    }
                }
                ret++;
            }
        }
        return ret;
    }
};