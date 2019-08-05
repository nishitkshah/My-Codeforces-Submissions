#21:16 08-08-2018
#21:28 08-08-2018
#21:52 08-08-2018

n, m, q = map(int, input().split())

w = [x for x in map(int, input().split())]

d = {}

for i in range(m):
	s = input()
	num = int(s, 2)
	d[num] = d.get(num, 0)+1

val = {}

for i in range(2**n):
	s = ("{0:b}".format(2**n+i))[-n:]
	v = 0
	for ind, c in enumerate(s):
		if(c=='0'):
			v += w[ind]
	val[i] = v

for i in range(q):
	t, k = input().split()
	num = int(t, 2)
	k = int(k)
	cnt = 0
	for s in d:
		if val[s^num] <= k:
			cnt += d[s]
	print(cnt)

#21:51 08-08-2018
#21:53 08-08-2018
#21:55 08-08-2018
