int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {

    set<string> st ;
    int l = targetWord.size();

    int n = wordList.size();
    for(int i=0; i<n; i++){
        st.insert(wordList[i]);
    }

    queue<pair<string, int>> q;

    q.push({startWord, 1});

    while(!q.empty()){
        string str = q.front().first;
        int lvl = q.front().second;

        q.pop();
        
        
        for(int j=0; j<l; j++)
        for(int i=0; i<26; i++){
            string strc = str;
            strc[j] = char('a' + i);
            if(st.count(strc)!=0){
                if(strc == targetWord) return lvl+1;
                q.push({strc, lvl+1});
                st.erase(str);
            }
        }
        
    }
    
    return 0;

}