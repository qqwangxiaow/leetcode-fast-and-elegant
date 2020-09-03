//回溯 从每行开始搜
//col保存是否被列覆盖过
//dg跟adg保存对角线，dg是行和列的差值，adg是和
//总计有2n行斜对角线，dg因为差值可能为负 需要加上n
//感觉使用引用更好
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>a(n,string(n,'.'));
        vector<int>col(n,0);
        vector<int>dg(2*n,0);
        vector<int>adg(2*n,0);
        dfs(0,n,res,a,col,dg,adg);
        return res;
        
    }
    void dfs(int row,int n,vector<vector<string>>&res,vector<string>a,vector<int>col,vector<int>dg,vector<int>adg)
    {
        if(row==n)
        {
            res.push_back(a);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!col[i]&&!dg[row-i+n]&&!adg[row+i]) //合法
            {
                col[i]=dg[row-i+n]=adg[row+i]=1;
                a[row][i]='Q';
                dfs(row+1,n,res,a,col,dg,adg);
                col[i]=dg[row-i+n]=adg[row+i]=0;
                a[row][i]='.';
            }
        }
    }
};