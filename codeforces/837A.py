n = input()
words = input().split()
ans = 0
for word in words:
    ans = max(sum(1 for c in word if c.isupper()), ans)
print (ans)