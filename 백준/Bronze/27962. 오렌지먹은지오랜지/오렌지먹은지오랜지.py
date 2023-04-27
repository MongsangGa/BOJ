N = int(input())
word = input()

for i in range(1, N):
    word1 = word[: i]
    word2 = word[-i:]

    diff = 0

    for j in range(i):
        if word1[j] != word2[j]:
            diff += 1
    
    if diff == 1:
        print('YES')
        exit(0)

print('NO')