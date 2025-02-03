#!/usr/bin/python3
"""
this file will be combined with
generator to make a resumed of
incoming request
"""
import sys
import signal
import re


def print_result(dictstatus: dict[str, int], filesize: int):
    print(f"File size: {filesize}")
    array_keys: [str] = []
    for k in dictstatus.keys():
        array_keys.append(k)
    array_keys.sort()
    for keys in array_keys:
        print(f"{keys}: {dictstatus[keys]}")


def denied(_signalno, _stack):
    print_result(d, fileSize)
    sys.exit(0)

if __name__ == '__main__':
    fileSize: int = 0
    status: str = ""
    d: dict[str, int] = {}
    nbLine: int = 0

    signal.signal(signal.SIGTERM, denied)
    signal.signal(signal.SIGINT, denied)

   import sys
import re

# Initialize variables
fileSize = 0
d = {}

# Use a raw string for regex to avoid escape sequence warnings
pattern = r"^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d+\] \"GET \/projects\/260 HTTP\/1\.1\" \d{3} \d{1,4}$"

for line in sys.stdin:
    line = line.strip()  # Remove leading/trailing spaces and newlines
    
    # Validate the line format
    if not re.search(pattern, line):
        print(f"skipped: {line}")
        continue
    
    # Split the line into parts
    inputSplit = line.split(" ")
    
    if len(inputSplit) < 2:  # Ensure the line has enough elements
        continue
    
    # Extract status code and file size
    n = inputSplit.pop()
    status = inputSplit.pop()
    
    # Ensure the file size is valid
    if not n.isdigit():
        continue

    fileSize += int(n)

    # Update status code count
    d[status] = d.get(status, 0) + 1

        nbLine += 1
        if nbLine % 10 == 0:
            print_result(d, fileSize)
    print_result(d, fileSize)
