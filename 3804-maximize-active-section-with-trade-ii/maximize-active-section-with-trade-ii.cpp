class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) totalOnes += (c == '1');

        vector<int> zst, zen, zlen;
        zst.reserve(n / 2 + 1);
        zen.reserve(n / 2 + 1);
        zlen.reserve(n / 2 + 1);
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

        vector<int> rightBlock(n, m), leftBlock(n, -1);
        for (int k = 0; k < m; k++) {
            int from = (k == 0) ? 0 : zen[k - 1] + 1;
            for (int i = from; i <= zen[k]; i++) rightBlock[i] = k;
            int to = (k == m - 1) ? n - 1 : zst[k + 1] - 1;
            for (int i = zst[k]; i <= to; i++) leftBlock[i] = k;
        }

        int p = max(0, m - 1);
        int LOG = 0;
        while ((1 << (LOG + 1)) <= max(1, p)) LOG++;
        vector<int> sp((LOG + 1) * max(1, p), 0);
        for (int i = 0; i < p; i++) sp[i] = zlen[i] + zlen[i + 1];
        for (int k = 1; k <= LOG; k++) {
            int* cur = sp.data() + k * p;
            int* prev = sp.data() + (k - 1) * p;
            int half = 1 << (k - 1);
            for (int i = 0; i + (1 << k) <= p; i++) {
                cur[i] = max(prev[i], prev[i + half]);
            }
        }

        auto rangeMax = [&](int l, int r) -> int {
            int k = 31 - __builtin_clz(r - l + 1);
            const int* row = sp.data() + k * p;
            return max(row[l], row[r - (1 << k) + 1]);
        };

        int qn = queries.size();
        vector<int> ans(qn);

        for (int qi = 0; qi < qn; qi++) {
            int l = queries[qi][0], r = queries[qi][1];

            int a = rightBlock[l];
            int b = leftBlock[r];

            int gain = 0;
            if (a < m && b >= 0 && a < b) {
                int lenA = min(zen[a], r) - max(zst[a], l) + 1;
                int lenB = min(zen[b], r) - max(zst[b], l) + 1;
                if (b == a + 1) {
                    gain = lenA + lenB;
                } else {
                    gain = max(lenA + zlen[a + 1], zlen[b - 1] + lenB);
                    if (a + 1 <= b - 2) gain = max(gain, rangeMax(a + 1, b - 2));
                }
            }

            ans[qi] = totalOnes + gain;
        }

        return ans;
    }
};