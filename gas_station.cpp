class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int total_gas = 0, end = -1;
        
        for (int i = 0, end_gas = 0; i < gas.size(); ++i)
        {
            end_gas += gas[i] - cost[i];
            total_gas += gas[i] - cost[i];
            if (end_gas < 0)
            {
                end = i;
                end_gas = 0;
            }
        }
        
        return  total_gas >= 0 ? end + 1 : -1;
    }
};
