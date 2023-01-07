class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int totalgas=0;
        int totalcost=0;
         for(int i=0;i<gas.size();i++)
         {
             totalgas=totalgas+gas[i];
             totalcost=totalcost+cost[i];
         }
        if(totalgas<totalcost)
        {
            return -1;
        }
         int tank=0;
         int station=0;
          for(int i=0;i<cost.size();i++)
          {
              tank=tank+(gas[i]-cost[i]);
              if(tank<0)
              {
                  station=i+1;
                  tank=0;
              }
          }
         return station;
    }
};
