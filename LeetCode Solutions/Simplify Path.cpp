class Solution {
public:
    string simplifyPath(string path) {
        string word = ;
        stack<string> st;
        for(int i = 0; i < path.size(); ++i)
        {
            if(path[i] == '/')
            {
                if(word == .. && st.size())
                    st.pop();
                else if(word != . && word != .. && word != )
                    st.push(word);
                word.clear();
                continue;
            }
            word.push_back(path[i]);
        }
        if(word == .. && st.size())
            st.pop();
        else if(word != . && word != .. && word != )
            st.push(word);
        string ans = ;
        while(st.size())
        {
            string tmp = ;
            tmp.push_back('/');
            ans = tmp + st.top() + ans;
            st.pop();  
        }
        if(ans == )
            return /;
        return ans;
    }
};
