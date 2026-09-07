class Solution(object):
    def waysToBuildRooms(self, prevRoom):
        MOD = 10**9 + 7
        n = len(prevRoom)

        tree = [[] for _ in range(n)]

        for i in range(1, n):
            tree[prevRoom[i]].append(i)

        fact = [1] * (n + 1)
        inv_fact = [1] * (n + 1)

        for i in range(1, n + 1):
            fact[i] = fact[i - 1] * i % MOD

        inv_fact[n] = pow(fact[n], MOD - 2, MOD)

        for i in range(n, 0, -1):
            inv_fact[i - 1] = inv_fact[i] * i % MOD

        def dfs(node):
            size = 1
            ans = 1

            for child in tree[node]:
                child_size, child_ways = dfs(child)

                ans = ans * child_ways % MOD
                ans = ans * inv_fact[child_size] % MOD
                size += child_size

            ans = ans * fact[size - 1] % MOD
            return size, ans

        return dfs(0)[1]