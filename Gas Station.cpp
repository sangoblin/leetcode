class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (gas.empty() || cost.empty() || gas.size()!=cost.size())    return -1;
        int len = gas.size(), tank = 0, idx = -1, tmp = 0, tmpi = -1;
        
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;
        
        vector<int> gap(len), back;
        transform(gas.begin(), gas.end(), cost.begin(), gap.begin(), minus<int>());
        back = gap;
        gap.resize(len*2);
        move(back.begin(), back.end(), gap.begin()+len);
        
        for (int i=0; i<2*len; ++i)
        {
            if (gap[i] < 0)
            {
                if (tmp > tank)
                {
                    tank = tmp;
                    idx = tmpi;
                }
                tmpi = -1;
                tmp = 0;
            }
            else
            {
                tmpi = tmpi==-1?i:tmpi;
                tmp += gap[i];
            }
        }
        return idx==-1?0:idx;
    }
};
