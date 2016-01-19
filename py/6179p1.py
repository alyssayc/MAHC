## Problem 1: Addition Is Awesome
##
## There are N (1 <= N <= 100,000) positive numbers below 100. Help Bessie add them.
##
## INPUT FORMAT:
## * Line 1: A single integer, N.
## * Line 2..N+1: Line i+1 contains an integer that Bessie wants to add.
##
## SAMPLE INPUT (stdin):
## 3
## 1
## 2
## 3
##
## OUTPUT FORMAT:
## * Line 1: A single integer that is the sum of the N integers.
##
## SAMPLE OUTPUT (stdout):
## 6
##
## OUTPUT DETAILS:
## 1 + 2 + 3 = 6

import sys
N = int(sys.stdin.readline()) # read the first line to see how many more lines to read
output = 0 # set up a variable to keep track of the sum of the numbers
for i in range(N): 
    output += int(sys.stdin.readline())
print(output)

