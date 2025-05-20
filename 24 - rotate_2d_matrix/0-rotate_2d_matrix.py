#!/usr/bin/python3
""" function to rotate a 2D matrix 90 degrees """


def rotate_2d_matrix(matrix):
    """ rotate 2D matrix """

    temp = [[0 for i in range(len(matrix[0]))] for j in range(len(matrix))]
    index = len(matrix[0]) - 1
    for i in range(len(matrix)):
        row = 0
        for j in range(len(matrix[i])):
            temp[row][index] = matrix[i][j]
            row += 1
        index -= 1

    for x in range(len(temp)):
        matrix[x] = temp[x]
