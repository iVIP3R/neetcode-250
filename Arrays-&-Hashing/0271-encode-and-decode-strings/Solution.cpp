class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (const string& str: strs) {
            res += '{' + to_string(str.length()) + '}';
            res.append(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                string c = "";
                i++;
                while (s[i] != '}') {
                    c += s[i++];
                }
                int len = stoi(c);
                string str = "";
                str += s.substr(i + 1, len);
                i += len;
                res.push_back(str);
            }
        }
        return res;
    }
};
