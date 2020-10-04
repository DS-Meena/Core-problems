from queue import Queue
from string import ascii_lowercase

def shortestPath(start, target, wordDict):
    frontier = Queue()
    frontier.put(start)

    level = 0
    visited = []

    while frontier.empty() == False:  # O(M) because word changes by one character
        level += 1
        size = frontier.qsize()   

        for _ in range(size):         #for this level # O(N)
            curr = frontier.get()
            visited.append(curr)

            if curr == target:       # if current is target
                return level

            for pos in range(len(curr)):     # O(M)* 26 check all possible neighbors
                tmp = curr
                for ch in ascii_lowercase:
                    curr = list(curr)  # string to list
                    curr[i] = ch        # push 
                    curr = ''.join(curr) # list to string
                    if curr not in visited and curr in wordDict:  # if not visited and is in wordDict
                        frontier.put(curr) 
                curr = tmp

            # time complexity O(N * M)
            # for i in range(len(wordDict)):  #check all possible neigbors 
            #     if oneDiff(curr, wordDict[i]) and wordDict[i] not in visited:
            #         frontier.put(wordDict[i]) 
    
    return 0
                

if __name__ == "__main__":
    start = "fool"
    target = "sage"
    wordDict = ["cool", "pool", "poll", "foil", "fail", "pole", "pope", "pale", "page", "sage", "sale", "fall"]
    
    print(shortestPath(start, target, wordDict))
