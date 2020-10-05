
def dfs(i, graph, visited, stack):
    visited[i] = True
    stack[i] = True       # which are processing
    
    for j in graph[i]:
        if visited[j] == False:
            if dfs(j, graph, visited, stack) == True:
                return True
        elif stack[j] == True and j != i:
            return True
    
    stack[i] = False     # i is fully processed
    return False

def canFinish(numCourses, prerequisites):    
    # create graph
    graph = [[] for _ in range(numCourses)]   
    for pair in prerequisites:
        x, y = pair
        graph[x].append(y)
    
    visited = [0 for _ in range(numCourses)]
    stack = [0 for _ in range(numCourses)]
    for i in range(numCourses):
        if  visited[i] == False and dfs(i, graph, visited, stack):   # if cycle found
            print("cycle  found")
            return False
    return True

if __name__ == '__main__':
    n = 3
    prerequisite_Pairs = [[1, 0], [0, 2]]

    if canFinish(n + 1, prerequisite_Pairs):   # n also works fine
        print("YES") 
    else:
        print("NO")
