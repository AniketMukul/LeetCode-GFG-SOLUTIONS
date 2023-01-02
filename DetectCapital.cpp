class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        char ch=word[0];
        char bh=word[1];
        if(islower(ch) && isupper(bh))
        {
            return false;
        }
        for(int i=2;i<word.length();i++)
        {
            if(isupper(ch) && isupper(bh))
            {
                if(islower(word[i]))
                {
                return false;
                }
            }
            else 
            {
                if(isupper(word[i]))
                {
                return false;
                }
            }
        }
        return true;
    }
};
