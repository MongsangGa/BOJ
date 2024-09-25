from sys import stdin
from itertools import combinations

while 1:
    arr = list(map(int, stdin.readline().split()))
    if arr[0] == 0: break
    arr.pop(0)
    for i in combinations(arr, 6):
        print(*i)
    print()
