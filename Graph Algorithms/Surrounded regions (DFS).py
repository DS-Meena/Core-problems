
def dfs(board, i, j):
    if board[i][j] == 'O':
        board[i][j] = '-'
        for x , y in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:   # movement like respectable horse also works fine
            if 0 <= x < m and 0 <= y < n:
                dfs(board, x, y) 

def replaceSurrounded(board, m, n):
    for i in range(m):             # make boundary O as '-'  , simple flood-fill algorithms also works fine
        dfs(board, i, 0)
        dfs(board, i, n - 1)

    for i in range(n):            # make boundary O as '-'
        dfs(board, 0, i)
        dfs(board, m - 1, i) 
    
    for i in range(m):            # make all '-' as O and remaining as X
        for j in range(n):
            if board[i][j] == '-':
                board[i][j] = 'O'
            else:
                board[i][j] = 'X'


if __name__ == '__main__':
    board = [
        ['X', 'O', 'X', 'X', 'X', 'X'],
        ['X', 'O', 'X', 'X', 'O', 'X'],
        ['X', 'X', 'X', 'O', 'O', 'X'],
        ['O', 'X', 'X', 'X', 'X', 'X'],
        ['X', 'X', 'X', 'O', 'X', 'O'],
        ['O', 'O', 'X', 'O', 'O', 'O'],
    ]
    m , n = len(board) , len(board[0]) 

    replaceSurrounded(board, m, n)

    for i in range(m):
        print(board[i])
