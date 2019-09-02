/*map*/
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int>mymap;
        for(int i=0;i<list1.size();i++)
        {
            mymap[list1[i]]=i;
        }
        int min=INT_MAX;
        vector<string>ret;
        for(int i=0;i<list2.size();i++)
        {
            if(mymap.count(list2[i]))
            {
                if((i+mymap[list2[i]])<min)
                {
                    min=i+mymap[list2[i]];
                    ret.clear();
                    ret.push_back(list2[i]);
                }
                else if((i+mymap[list2[i]])==min)
                {
                    ret.push_back(list2[i]);
                }
                
            }
                
        }
        return ret;
        
        
    }
};