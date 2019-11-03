//clean code using set,directions
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>>directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        set<pair<int,int>>myset;
        for(auto obstacle:obstacles)
        {
            myset.insert(make_pair(obstacle[0],obstacle[1]));
        }
        int x=0,y=0,direction=1,maxDistSquare=0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2)
            {
                direction--;
                if(direction<0)
                    direction+=4;
            }
            else if(commands[i]==-1)
            {
                direction++;
                direction%=4;
            }
            else
            {
                int step=0;
                while(step<commands[i]&&(!myset.count(make_pair(x+directions[direction][0],y+directions[direction][1]))))
                {
                    x+=directions[direction][0];
                    y+=directions[direction][1];
                    step++;
                }
            }
            maxDistSquare=max(maxDistSquare,x*x+y*y);       
        }   
       return maxDistSquare;
    }
        
    

};
