class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const string& str: strs) {
            res += '[' + to_string(str.size()) + ']' + str; 
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                string len = "";
                i++;
                while (s[i] != ']') len += s[i++];
                int leng = stoi(len);
                res.push_back(s.substr(i + 1, leng));
                i += leng;
            }
        }

        return res;
    }
};
