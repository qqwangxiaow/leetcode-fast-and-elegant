//dfs
//需要考虑[i][j]是否=old color
//判断原来的颜色不能是newcolor
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
            dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
    void dfs(vector<vector<int>>&image,int i,int j,int oc,int nc)
    {
        if(i<0||j<0||j>=image[0].size()||i>=image.size()||image[i][j]!=oc)
            return ;
        image[i][j]=nc;
        dfs(image,i+1,j,oc,nc);
        dfs(image,i,j+1,oc,nc);
        dfs(image,i-1,j,oc,nc);
        dfs(image,i,j-1,oc,nc);
        
    }
};