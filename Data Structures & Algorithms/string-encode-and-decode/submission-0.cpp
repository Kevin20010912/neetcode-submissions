class Solution {
public:

    string encode(vector<string>& strs) {
        string res_enc = "";
        for(auto& str : strs){
            res_enc += (to_string(str.size()) + "#" + str);
        }
        return res_enc;
    }

    vector<string> decode(string s) {
        vector<string> res_dec;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[i] != '#'){
                i++;
            }
            i++;
            int size = stoi(s.substr(j, i - j));
            string collect_str = "";
            for(int k = 0; k < size; k++){
                collect_str += s[i];
                i++;
            }
            res_dec.push_back(collect_str);
        }
        return res_dec;
    }
};
