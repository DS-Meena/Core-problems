def getMinimumMultipleOfBinaryDigit(num):
    frontier = []

    visited = set()
    curr = '1'
    frontier.append(curr)
    while frontier:           # until frontier becomes empty
        curr = frontier.pop()  # check pop(0)
        remainder = int(curr) % num
        if remainder == 0:
            return curr
        if remainder not in visited:
            visited.add(remainder)
            frontier.append(curr + '0')
            frontier.append(curr + '1')

n = 18
print(getMinimumMultipleOfBinaryDigit(n))
