class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long INF = 2000000000000000LL;

        char ch;
        
        vector<long long> window(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ch = s[i];

            if (ch == '*') window[i+1] = max(0LL, window[i] - 1);
            else if (ch == '#') window[i+1] = min(INF, window[i] * 2);
            else if (ch == '%') window[i+1] = window[i];
            else window[i+1] = window[i] + 1;
        }
        
        if (k >= window[n]) return '.';
        
        long long pos = k;
        long long prev;
        for (int i = n - 1; i >= 0; i--) {
            ch = s[i];
            prev = window[i];
            
            if (ch == '*') {
                
            }
            else if (ch == '#') {
                pos %= prev;
            }
            else if (ch == '%') {
                pos = prev - 1 - pos;
            }
            else {
                if (pos == prev) return ch;
            }
        }
        
        return '.';
    }
};
