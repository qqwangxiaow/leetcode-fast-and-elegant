//回溯，一行一行来
//主要是对角线，用2n的数组表示，行减列的值相同，为列处理负数，加一个n
//反对角线，行和列想加相同
//主要是发现对角线的规律，回溯的话把访问都置为1，单元格置为'Q'
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>>res; //最终结果
        vector<string>a(n,string(n,'.'));//一个结果
        vector<int>col(n,0);//列是否重复
        vector<int>dg(2*n,0);//对角线
        vector<int>adg(2*n,0);//反对角线
        dfs(0,n,res,a,col,dg,adg);
        return res.size();
    }
    void dfs(int row,int n,vector<vector<string>>&res,vector<string>&a,vector<int>&col,vector<int>&dg,vector<int>&adg)
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