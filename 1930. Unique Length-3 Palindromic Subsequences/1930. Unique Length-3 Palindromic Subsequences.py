class Solution(object):
    def countPalindromicSubsequence(self, s):
        c = 'abcdefghijklmnopqrstuvwxyz'
        a, t = 0, 0

        for x in c:
            l = s.find(x)
            if l == -1:
                continue
            r = s.rfind(x)
            if l >= r:
                continue

            v = [False] * 128
            t = 0
            for i in range(l + 1, r):
                if not v[ord(s[i])]:
                    v[ord(s[i])] = True
                    t += 1
                    if t == 26:
                        break
            a += t
        return a
        