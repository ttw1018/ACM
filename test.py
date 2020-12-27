s = [23, 132, 19, 61, 190, 29, 4, 18, 40]

now = 100
ans = 0
for i in range(9):
    mi = 100000
    tmp = -1
    for j in s:
        if abs(j - now) < mi:
            tmp = j
            mi = abs(j - now)
    s.remove(tmp)
    ans += mi
    now = tmp
    print(tmp)
print(ans / 9.0)
print(s)
