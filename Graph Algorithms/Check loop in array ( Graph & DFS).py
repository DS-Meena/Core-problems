
def dfs(u, adj, visited, stack):
    visited[u] = True
    stack[u] = True
    for v in adj[u]:     # for all neighbors O(E)
        if visited[v] == False and dfs(v, adj, visited, stack):
            return True
        elif stack[v] == True and v != u:
            return True

    stack[u] = False
    return False

def circularArrayLoop(nums, n):
    adj1 = [[] for i in range(n)]  # positive cycle
    adj2 = [[] for i in range(n)]  # negative cycle
    for i, j in enumerate(nums):
        if j >= 0:
            adj1[i].append((i + j) % n) 
        else:
            adj2[i].append((i + j) % n)

    visited = [False] * n
    stack = [False] * n 
    # search for positive cycle
    for i in range(n):             # for all vertices O(V)
        if visited[i] == 0 and dfs(i, adj1, visited, stack) == True:
            print(i)
            return True
    
    visited = [False] * n
    stack = [False] * n
    #search for negative cycle
    for i in range(n):            # for all vertices O(V)
        if visited[i] == 0 and dfs(i, adj2, visited, stack) == True:
            print(i)
            return True

    return False
    
    

if __name__ == '__main__':
    arr = [2, -1, 2, 2, 1]
    n = len(arr)

    if (circularArrayLoop(arr, n)): 
        print("YES")
    else:
        print("NO")
