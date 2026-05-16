class Solution {
    public:
        string countAndSay(int n) {
            string res = "1";
            string str;
            int len;
            int j;
            int length;
            string num;

            for (int i = 2; i <= n; i++) {
                len = res.size();
                j = 0;
                str = "";
                cout << "n = " << i << ", len = " << len << endl;

                for (int idx = 0; idx < len; ) {
                    while (j < len && res[j] == res[idx]) {
                        j++;
                    }

                    length = j - idx;
                    cout << length << endl;
                    num = res[idx];
                    str.append(to_string(length));
                    str.append(num);

                    idx = j;
                }

                cout << i << " -> " << str << endl << endl;

                res = str;
            }

            return res;
        }
};
