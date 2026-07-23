class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        long long totalOnes = count(s.begin(), s.end(), '1');

        vector<int> zst, zen, zlen;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                zst.push_back(i);
                zen.push_back(j - 1);
                zlen.push_back(j - i);
                i = j;
            } else {
                i++;
            }
        }

        int m = zst.size();
        int p = max(0, m - 1);
        int LOG = 1;
        while ((1 << LOG) < max(1, p)) LOG++;
        vector<vector<int>> sp(LOG + 1, vector<int>(max(1, p), 0));
        for (int i = 0; i < p; i++) sp[0][i] = zlen[i] + zlen[i + 1];
        for (int k = 1; k <= LOG; k++) {
            for (int i = 0; i + (1 << k) <= p; i++) {
                sp[k][i] = max(sp[k - 1][i], sp[k - 1][i + (1 << (k - 1))]);
            }
        }

        auto rangeMax = [&](int l, int r) -> int {
            if (l > r) return 0;
            int k = 31 - __builtin_clz(r - l + 1);
            return max(sp[k][l], sp[k][r - (1 << k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int a = lower_bound(zen.begin(), zen.end(), l) - zen.begin();
            int b = int(upper_bound(zst.begin(), zst.end(), r) - zst.begin()) - 1;

            long long gain = 0;
            if (a < m && b >= 0 && a < b) {
                long long lenA = min(zen[a], r) - max(zst[a], l) + 1;
                long long lenB = min(zen[b], r) - max(zst[b], l) + 1;
                if (b == a + 1) {
                    gain = lenA + lenB;
                } else {
                    gain = max(lenA + zlen[a + 1], (long long)zlen[b - 1] + lenB);
                    if (a + 1 <= b - 2) gain = max(gain, (long long)rangeMax(a + 1, b - 2));
                }
            }

            ans.push_back((int)(totalOnes + gain));
        }

        return ans;
    }
};