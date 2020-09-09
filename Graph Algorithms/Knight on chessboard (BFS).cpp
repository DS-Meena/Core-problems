
from queue import Queue    #list with pop(0) and append also works fine

def minMoves(m, n, knightx, knighty, targetx, targety):
    frontier = Queue()
    frontier.put((knightx, knighty))

    x = [2, 2, 1, 1, -1, -1, -2, -2]
    y = [1, -1, 2, -2, 2, -2, 1, -1]
    visited = [(knightx, knighty)]
    
    moves = 0
    while frontier.empty() == False:
        size = frontier.qsize()
        for _ in range(size):
            currx, curry = frontier.get() 
            visited.append((knightx, knighty))

            for i in range(8):
                newx = currx + x[i]
                newy = curry + y[i]

                if newx == targetx and newy == targety:
                    return moves + 1

                if 1<= newx and newx <= n and 1 <= newy and newy <= n and (newx, newy) not in visited:
                    frontier.put((newx, newy))
        
        moves += 1 
    
    return -1
          

if __name__ == "__main__":
    m = 8
    n = 8     # always square 
    c, d = (1, 1)
    e, f = (8, 8)
    print(minMoves(m, n, c, d, e, f)) 

