##Problem 3: Stacking Cups
##Inspired by the song, "Cups" Bessie the cow and her friends invented a new game involving cups. The game is simple: numbers 1 to N (inclusive) are uniquely assigned to cups, and there are two possible operations, PUSH and POP. PUSH takes a cup and puts it on top of the existing cup stack (or starts a new one, if no stack already exists), POP takes the topmost cup off. In particular, a cup may be pushed only once: after a cup is popped from the stack, it is consumed by the cow who popped the cup (since it's biodegradable!), and thus no longer exists.
##
##Given N (1 <= N <= 1,000,000), the number of cups, and M (0 <=  M <= 2N), the number of operations, determine the result given the input sequence.
##
##PROBLEM NAME: cups
##
##INPUT FORMAT:
##* Line 1: Two integers, N and M.
##* Line 2..M+1: Either PUSH k, or POP, where PUSH is always followed by an integer from 1 to N (inclusive). All operations are guaranteed to be valid (e.g. POP will not be called if nothing is on the stack, and PUSH will not be followed by a number that's already been PUSH'ed or that isn't within range).
##
##SAMPLE INPUT (stdin):
##5 5
##PUSH 1
##PUSH 2
##POP
##POP
##PUSH 4
##
##OUTPUT FORMAT:
##* Line k: A single integer that represents the value of the cup popped by the k-th POP command in the input.
##
##SAMPLE OUTPUT (stdout):
##2
##1
##
##OUTPUT DETAILS:
##We start out with an empty stack, and push 1:
##
##1
##
##We then push 2:
##
##2
##1
##
##Now, we pop from the top:
##
##(POP 2)
##1
##
##Again, we pop from the top:
##
##(POP 1)
##(empty stack)
##
##Finally, we push 4:
##
##4
##
##Thus, our output is just:
##
##2
##1

import sys

inputs = sys.stdin.readline()
inputlist = inputs.split()
[N, M] = inputlist
stack = []
for i in range(int(M)):
    currentline = sys.stdin.readline().split()
    if len(currentline) == 2:
        stack.append(int(currentline[1]))
##        (word, num) = currentline
##	if (word == 'PUSH'):
##	    stack.append(int(num))
    else:
        print(stack.pop())
        



