
def isInside(x, y, n):
    if x >= 1 and x <= n and y >= 1 and y <= n:
        return True
    return False

def minStepToReachTarget(knightPos, targetPos, n):
    dx = [2, 2, -2, -2, 1, 1, -1, -1]
    dy = [1, -1, 1, -1, 2, -2, 2, -2]

    frontier = [] 
    start = (knightPos[0], knightPos[1])
    frontier.append(start)
    steps = 0
    visited = [[False for _ in range(n + 1)] for __ in range(n + 1)]
    visited[knightPos[0]][knightPos[1]] = True

    while frontier:      
        size = len(frontier)
        for _ in range(size):               # level-wise to get steps
            currx, curry = frontier.pop(0)   # get curr node
            if currx == targertPos[0] and curry == targertPos[1]:  # if curr is target
                return steps

            for i in range(8):               # get the neighbour node
                x = currx + dx[i]
                y = curry + dy[i]
                if isInside(x, y, n) and not visited[x][y]:
                    visited[x][y] = True
                    tmp = (x, y)
                    frontier.append(tmp) 
        steps += 1

        

if __name__ == '__main__':
    a = 6
    b = 6 
    c = 4
    d = 5
    e = 3
    f = 2
    n = a
    knightPos = [c, d]
    targertPos = [e, f]

    print(minStepToReachTarget(knightPos, targertPos, n))
