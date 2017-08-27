t = int(input())
for i in range(t):
    dates = list(map(int, input().split(",")))
    actives = []
    for i in range(200000):
        actives.append(0)
    for date in dates:
        actives[date] = 1
    for i in range(1, 100005):
        actives[i] += actives[i-1]
    nxt = 0
    ans = 0
    for i in range(1, 100005):
        if (i < nxt or actives[i] - actives[i-1] <= 0):
            continue
        if (actives[i+29] > 23):
            ans += 25
            nxt = i + 30
        elif (actives[i+6] - actives[i-1] > 3):
            ans += 7
            nxt = i + 7
        elif (actives[i] - actives[i-1] > 0):
            ans += 2
            nxt = i + 1
    print(ans)