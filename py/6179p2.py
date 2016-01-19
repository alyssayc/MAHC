## Problem 2: Fibonacci Cows
## Bessie and her cows love Fibonacci numbers. The Fibonacci numbers form a sequence defined by the recurrence:
## F0 = 1
## F1 = 1
## FN = FN-1 + FN-2
##
## Given N (1 <= N <= 500,000), help Bessie find the N-th Fibonacci number.
##
## INPUT FORMAT:
## * Line 1: A single integer, N.
##
## SAMPLE INPUT (stdin):
## 10
##
## OUTPUT FORMAT:
## * Line 1: A single integer that is the N-th Fibonacci number. Because this number can be very large, output the value modulo 1,000,000,007.
##
## SAMPLE OUTPUT (stdout):
## 89
##
## OUTPUT DETAILS:
## We want to find the 10-th Fibonacci number, which is 89.
## N | Value
## ----------
##  0| 1
##  1| 1
##  2| 2
##  3| 3
##  4| 5
##  5| 8
##  6| 13
##  7| 21
##  8| 34
##  9| 55
## 10| 89

import sys

N = int(sys.stdin.readline()) # Find which Fibonacci number Bessie wants.

numbers = [1,1]
if (N < 2):
    print(numbers[N])
else:
    for i in range(N-1):
        length = len(numbers)
        nextnum = numbers[length-2] + numbers[length-1]
        appendnum = nextnum % 1000000007
        numbers.append( appendnum )
    print(numbers[N])

## the code below had runtime error.    
##def fibonacci(num): # implement recursion on the fibonacci numbers
##    if ((num == 0) or (num == 1)):
##        return 1
##    else:
##        return( fibonacci(num-1) + fibonacci(num-2) )
##
##print(fibonacci(N))
