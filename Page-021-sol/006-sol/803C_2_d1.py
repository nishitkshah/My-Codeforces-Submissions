#07:50 13-03-2019 to 07:53 13-03-2019
#08:02 13-03-2019
#08:14 13-03-2019

N_ = 10000000001
SQN_ = 100001

n, k = map(int, input().split())
mxg = 1

def ul(k):
    return k*(k-1)//2

if n<ul(k):
    print(-1)
else:
    for g in range(1, SQN_):
        if g<=n and n%g==0 and n//g>=ul(k):
            mxg = g
    a = []
    for i in range(1, k+1):
        a.append(mxg*i)
    a[-1] += n-g*ul(k)
    print(' '.join(map(str, a)))

#08:13 13-03-2019
#08:15 13-03-2019
