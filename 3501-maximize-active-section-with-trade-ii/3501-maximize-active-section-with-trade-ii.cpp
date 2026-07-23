class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        int totalOnes = 0;
        for (char c : s)
            totalOnes += (c == '1');

        vector<int> zst, zen, zlen;
        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0')
                    j++;
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
            for (int i = from; i <= zen[k]; i++)
                rightBlock[i] = k;

            int to = (k == m - 1) ? n - 1 : zst[k + 1] - 1;
            for (int i = zst[k]; i <= to; i++)
                leftBlock[i] = k;
        }

        int p = max(1, m - 1);
        int LOG = 0;
        while ((1 << (LOG + 1)) <= p)
            LOG++;

        vector<vector<int>> sp(LOG + 1, vector<int>(p));

        if (m > 1) {
            for (int i = 0; i < m - 1; i++)
                sp[0][i] = zlen[i] + zlen[i + 1];

            for (int k = 1; k <= LOG; k++) {
                int len = 1 << k;
                int half = len >> 1;
                for (int i = 0; i + len <= p; i++) {
                    sp[k][i] = max(sp[k - 1][i], sp[k - 1][i + half]);
                }
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

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

                    if (a + 1 <= b - 2) {
                        int lo = a + 1;
                        int hi = b - 2;
                        int k = 31 - __builtin_clz(hi - lo + 1);

                        gain = max(
                            gain,
                            max(
                                sp[k][lo],
                                sp[k][hi - (1 << k) + 1]
                            )
                        );
                    }
                }
            }

            ans.push_back(totalOnes + gain);
        }

        return ans;
    }
};