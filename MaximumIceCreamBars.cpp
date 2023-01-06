class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        sort(costs.begin(),costs.end());
        int answer=0;
        for(auto it:costs)
        {
          if(it<=coins)
          {
              answer=answer+1;
              coins=coins-it;
          }
        }
        return answer;
    }
};
