#!/usr/bin/python3
""" Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains. """

def rain(walls):
    """ Calculate retained water """
    total = 0
    n = len(walls)

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])
        total = total + (min(left, right) - walls[i])
    return total