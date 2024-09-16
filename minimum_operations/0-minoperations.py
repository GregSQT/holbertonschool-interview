#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations needed to result
in exactly n H characters in the file. Be smart about how you utilize the memory!
"""


def minOperations(n):
    """ return min # of operations"""
    copy = 1
    paste = 0
    count = 0
    if copy > n:
        return 0
    while copy < n:
        if n % copy == 0 and copy > paste:
            paste = copy
        else:
            copy += paste
        count += 1
    return count
