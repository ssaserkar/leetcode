class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # Step 1: Build adjacency list representation of the graph
        graph = defaultdict(list)
        in_degree = [0] * n
        
        for from_node, to_node in edges:
            graph[from_node].append(to_node)
            in_degree[to_node] += 1
        
        # Step 2: Perform topological sorting using Kahn's algorithm
        topo_order = []
        zero_in_degree_queue = deque()
        
        for node in range(n):
            if in_degree[node] == 0:
                zero_in_degree_queue.append(node)
        
        while zero_in_degree_queue:
            node = zero_in_degree_queue.popleft()
            topo_order.append(node)
            
            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    zero_in_degree_queue.append(neighbor)
        
        # Step 3: Compute ancestors using the sorted topological order
        ancestors = [[] for _ in range(n)]
        
        for u in topo_order:
            for v in graph[u]:
                ancestors[v].extend(ancestors[u] + [u])
                ancestors[v] = list(set(ancestors[v]))  # Remove duplicates
        
        # Step 4: Sort and prepare the final answer
        for i in range(n):
            ancestors[i].sort()
        
        return ancestors