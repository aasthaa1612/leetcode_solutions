class Solution(object):
    def largestPathValue(self, colors, edges):
        n = len(colors)
        graph = [[] for _ in range(n)]
        indegree = [0] * n

        for u, v in edges:
            graph[u].append(v)
            indegree[v] += 1

        # dp[node][color] = maximum count of that color
        dp = [[0] * 26 for _ in range(n)]

        # Topological sort
        queue = [i for i in range(n) if indegree[i] == 0]
        count = 0
        ans = 0

        while queue:
            u = queue.pop(0)
            count += 1

            c = ord(colors[u]) - ord('a')
            dp[u][c] += 1
            ans = max(ans, dp[u][c])

            for v in graph[u]:
                for j in range(26):
                    dp[v][j] = max(dp[v][j], dp[u][j])

                indegree[v] -= 1
                if indegree[v] == 0:
                    queue.append(v)

        # If not all nodes were processed, graph has a cycle
        if count != n:
            return -1

        return ans        