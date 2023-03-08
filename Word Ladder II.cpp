class Solution {
public:
    unordered_map<string,int>mp;
    vector<vector<string>>answer;
    string begin;
    void solve(string word,vector<string>&sequence)
    {
        if(word==begin)
        {
            reverse(sequence.begin(),sequence.end());
            answer.push_back(sequence);
            reverse(sequence.begin(),sequence.end());
            return;
        }
        int level=mp[word];
        int size=word.size();
        for(int i=0;i<size;i++)
        {
            char orignal=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(mp.count(word) && mp[word]+1==level)
                {
                    sequence.push_back(word);
                    solve(word,sequence);
                    sequence.pop_back();
                }
            }
            word[i]=orignal;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string>q;
        unordered_set<string>s(wordList.begin(),wordList.end());
        mp[beginWord]=1;
        s.erase(beginWord);
        vector<string>sequence;
        begin=beginWord;
        sequence.push_back(endWord);
        q.push(beginWord);
        while(!q.empty())
        {
            string word=q.front();
            int level=mp[word];
            q.pop();
            if(word==endWord)
            {
                break;
            }
            int size=word.size();
            for(int i=0;i<size;i++)
            {
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(s.count(word))
                    {
                        q.push(word);
                        s.erase(word);
                        mp[word]=level+1;
                        
                    }
                }
                word[i]=orignal;
            }
        }
        if(mp.count(endWord))
        {
            solve(endWord,sequence);
        }
        return answer;
    }
};
