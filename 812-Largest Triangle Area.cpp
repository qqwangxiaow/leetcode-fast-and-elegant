//math
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res=0;
        for(auto &i:points)
            for(auto &j:points)
                for(auto &k:points)
                    res=max(res,0.5*abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return res;
    }
};

//海伦公式
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res=0;
        for(auto &i:points)
            for(auto &j:points)
                for(auto &k:points)
                    res=max(res,getarea(i,j,k));
        return res;
    }
    double getarea(vector<int>&a,vector<int>&b,vector<int>&c)
    {
        double dis1=getdis(a,b);
        double dis2=getdis(a,c);
        double dis3=getdis(b,c);
        double s=(dis1+dis2+dis3)/2;
        double area=sqrt(s*(s-dis1)*(s-dis2)*(s-dis3));
        return area;
        
    }
    double getdis(vector<int>&a,vector<int>&b)
    {
        return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
    }
};