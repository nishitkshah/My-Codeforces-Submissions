#00:13 08-10-2018

MAXN = 1000001
b = [0 for i in range(0, MAXN)]
p = []

def sieve():
	global b, p, MAXN
	b[0] = 1
	b[1] = 1
	b[2] = 0
	for i in range(2, MAXN):
		if b[i]!=0:
			j = i*i
			while j<MAXN:
				b[j] = 1
				j+=i
			p.append(i)

def solve():
	a, b = map(int, input().split())
	if (a-b)!=1:
		print("NO")
		return
	a += b
	for i in range(len(p)):
		if(a==p[i]):
			print("YES")
			return
	print("NO")

sieve();
t = int(input())
for i in range(t):
	solve()

#00:24 08-10-2018
