#!/usr/bin/python3
""" n queens problem """
import sys


def printBoard(board):
    """ print solutions """
    ret = []
    for i in range(len(board)):
        index = board[i].index(1)
        ret.append([i, index])
    print(ret)


def isValid(board, col, row, n):
    """ checks if valid """
    for i in range(col):
        if board[row][i] == 1:
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while i < n and j >= 0:
        if board[i][j] == 1:
            return False
        i += 1
        j -= 1
    return True


def nQueens(board, col, n):
    """ places queens on the board """
    stat = False
    if col == n:
        printBoard(board)
        return True
    for row in range(n):
        if isValid(board, col, row, n):
            board[row][col] = 1
            stat = nQueens(board, col + 1, n) or stat
            board[row][col] = 0
    return stat


def main():
    """ main function """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        exit(1)
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        exit(1)
    board = [[0 for i in range(n)]for j in range(n)]
    nQueens(board, 0, n)

if __name__ == "__main__":
    main()
