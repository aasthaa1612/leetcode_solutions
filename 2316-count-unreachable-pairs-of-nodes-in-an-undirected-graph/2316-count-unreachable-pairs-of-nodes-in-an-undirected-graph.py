class Solution(object):
    def countPairs(self, n, edges):
        graph = [[] for _ in range(n)]

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = [False] * n
        sizes = []

        def dfs(node):
            visited[node] = True
            count = 1

            for nei in graph[node]:
                if not visited[nei]:
                    count += dfs(nei)

            return count

        for i in range(n):
            if not visited[i]:
                sizes.append(dfs(i))

        ans = 0
        remaining = n

        for size in sizes:
            remaining -= size
            ans += size * remaining

        return ans