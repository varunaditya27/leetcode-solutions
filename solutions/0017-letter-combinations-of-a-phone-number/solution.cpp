class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> dict = {
            {'2', "abc"}, 
            {'3', "def"}, 
            {'4', "ghi"}, 
            {'5', "jkl"}, 
            {'6', "mno"}, 
            {'7', "pqrs"}, 
            {'8', "tuv"}, 
            {'9', "wxyz"}
        };

        vector<string> ans;
        int len = digits.size();
        string res;

        if (len == 4) {
            for (char c1: dict[digits[0]]) {
                res += c1;
                for (char c2: dict[digits[1]]) {
                    res += c2;
                    for (char c3: dict[digits[2]]) {
                        res += c3;
                        for (char c4: dict[digits[3]]) {
                            res += c4;
                            ans.push_back(res);
                            res.pop_back();
                        }
                        res.pop_back();
                    }
                    res.pop_back();
                }
                res.pop_back();
            }
        }

        else if (len == 3) {
            for (char c1: dict[digits[0]]) {
                res += c1;
                for (char c2: dict[digits[1]]) {
                    res += c2;
                    for (char c3: dict[digits[2]]) {
                        res += c3;
                        ans.push_back(res);
                        res.pop_back();
                    }
                    res.pop_back();
                }
                res.pop_back();
            }
        }

        else if (len == 2) {
            for (char c1: dict[digits[0]]) {
                res += c1;
                for (char c2: dict[digits[1]]) {
                    res += c2;
                    ans.push_back(res);
                    res.pop_back();
                }
                res.pop_back();
            }
        }

        else {
            for (char c1: dict[digits[0]]) {
                res += c1;
                ans.push_back(res);
                res.pop_back();
            }
        }

        return ans;
    }
};
