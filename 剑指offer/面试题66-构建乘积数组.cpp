//if(i) not if(!i)
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        vector<int>fromleft(n,1);
        vector<int>fromright(n,1);
        vector<int>ret(n,1);
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                fromleft[i]=fromleft[i-1]*a[i-1];    
                fromright[n-i-1]=fromright[n-i]*a[n-i];
            }
                
        }
        for(int i=0;i<n;i++)
        {
            ret[i]=fromleft[i]*fromright[i];
        }
        return ret;


    }
};