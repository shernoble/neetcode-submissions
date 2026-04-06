class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total =0;
        int start = 0;

        int sum1=0 , sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=gas[i];
            sum2+=cost[i];
        }
        if(sum1<sum2) return -1;

        for(int i=0;i<n;i++)
        {
            total+=gas[i]-cost[i];
            
            if(total<0)
            {
                total =0;
                start =i+1;
            }

        }
        return start;
    }
};
