class Solution:
    def numberOfWays(self, corridor):
        MOD = 10**9 + 7
        zero = 0
        one = 0
        two = 1

        for thing in corridor:
            if thing == 'S':
                zero = one
                one, two = two, one
            else:
                two = (two + zero) % MOD

        return zero