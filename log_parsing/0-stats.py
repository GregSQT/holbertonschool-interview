#!/usr/bin/python3
""" parse log and print status codes """
import sys

count = 0
size = 0
status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def printer():
    print("File size: " + str(size))
    for x in sorted(status):
        if status[x] != 0:
            print(str(x) + ": " + str(status[x]))

if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                if count == 10:
                    printer()
                    count = 0
                splt = line.split()
                size += int(splt[8])
                status[int(splt[7])] += 1
                count = count + 1
            except:
                sys.exit()
    except KeyboardInterrupt:
        printer()
        raise
    printer()