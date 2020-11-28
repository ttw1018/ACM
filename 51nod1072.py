import math
T = int(input())

for t in range(0, T):
    a, b = map(int, input().split())
    if a > b:
        tmp = a
        a = b
        b = tmp
    if a == int((math.sqrt(5) + 1) / 2 * (b - a)):
        print("B")
    else:
        print("A")


