t = int(input())
for i in range(t):
    x, n = map(int, input().split())
    ans = 0
    while x >= n:
        ans += (x//n) * n
        x = (x//n) + (x%n)
    print(ans + x)