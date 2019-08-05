#21:00 08-03-2019 to 21:11 08-03-2019 - read problem
#21:39 08-03-2019

n = int(input())
a = map(int, input().split())
sm = 0
ans = 0
mp = {}
for i in range(n):
    ans += i*a[i]-sm
    ans -= mp.get(a[i]-1, 0)
    ans += mp.get(a[i]+1, 0)
    mp[a[i]] = mp.get(a[i], 0)+1
    sm += a[i]
print(ans)

#21:45 08-03-2019
