class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int str_idx = 0; 
        
        while (true) {
            char target = strs[0][str_idx];
            
            for(string word: strs) {                
                if (word[str_idx] != target) {
                    return result;
                }

                else if (word[str_idx] == '\0') {
                    return result;
                }
            }

            result.push_back(target);
            str_idx ++;
        }

        return result;
    }
};
