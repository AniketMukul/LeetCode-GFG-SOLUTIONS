class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int answer=0;
        for(auto it:tasks)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            if(it.second==1)
            {
                return -1;
            }
            if(it.second%3==0)
            {
              answer=answer+it.second/3;
            }
            else 
            {
                answer=answer+it.second/3+1;
            }
        }
        return answer;
    }
    
};
