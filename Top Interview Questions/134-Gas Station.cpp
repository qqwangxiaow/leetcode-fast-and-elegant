//If car starts at A and can not reach B. Any station between A and B
//can not reach B.(B is the first station that A can not reach.)
//A reach C,But can't reach B,then start from B,can't reach C.
//If the total number of gas is bigger than the total number of cost. There must be a solution.
//=运算次序最后 先算< 所以要括号
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,tank=0,total=0;
        for(int i=0;i<gas.size();i++)
        {
            if((tank=tank+gas[i]-cost[i])<0)
            {
                start=i+1;
                total+=tank;
                tank=0;
            }
        }
        return total+tank<0?-1:start;
    }
};