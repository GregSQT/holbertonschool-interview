#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ Returns 2D list of ints representing Pascal's Triangle """
    lst = []
    for row in range(n):
        temp = [None] * (row + 1)
        for x in range(len(temp)):
            if row - 1 >= 0 and x - 1 >= 0 and x != len(temp) - 1:
                temp[x] = lst[row - 1][x] + lst[row - 1][x - 1]
            else:
                temp[x] = 1
        lst.append(temp)
    return lst
