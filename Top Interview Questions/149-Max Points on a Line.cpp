//O(n2)的方法 用string来代表key 存储斜率 用都除以__gcd后的正y值来保存斜率
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ret=0;
        for(int i=0;i<points.size();i++)
        {
            int same=0;
            int overflow=0;
            int curmax=0;
            unordered_map<string,int>mymap;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])
                    same++;
                else if(points[i][0]==points[j][0])
                    overflow++;
                else{
                    int xdiff=points[i][0]-points[j][0];
                    int ydiff=points[i][1]-points[j][1];
                    int g=__gcd(ydiff,xdiff);
                    xdiff/=g;
                    ydiff/=g;
                    if(ydiff<0)
                    {
                        ydiff=-ydiff;
                        xdiff=-xdiff;
                    }
                    stringstream str;
                    str<<ydiff<<","<<xdiff;
                    mymap[str.str()]++;
                    curmax=max(curmax,mymap[str.str()]);
                }
                curmax=max(curmax,overflow);
            }
            ret=max(ret,curmax+same+1);
        }
        return ret;
    }
};
//这题目有点傻逼啊 关键其实是long long 
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<3)
            return points.size();
        int ret=0;
        for(int i=0;i<points.size();i++)
        {
            int same=1;
            for(int j=i+1;j<points.size();j++)
            {
                int count=0;
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])
                    same++;
                else
                {
                    count++;
                    long long xdiff=(long long)(points[i][0]-points[j][0]);
                    long long ydiff=(long long)(points[i][1]-points[j][1]);
                    for(int k=j+1;k<points.size();k++)
                    {
                        if(xdiff*(points[i][1]-points[k][1])==ydiff*(points[i][0]-points[k][0]))
                            count++;
                    }
                    
                }
                ret=max(ret,same+count);
            }
            if(ret>points.size()/2)
                return ret;
        }
        return ret;
    }
};
