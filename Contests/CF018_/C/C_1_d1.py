#21:30 18-04-2019 to 21:34 18-04-2019 and 21:57 18-04-2019
#22:13 18-04-2019
#22:21 18-04-2019

M = 1000000007

def s_sum(d):
	if d<1:
		return 0
	s = [0, 0]	#odd, even
	p = 1
	t = 0
	while p<=d:
		s[t] += p
		d -= p
		p *= 2
		t = 1-t
	s[t] += d
	nodd = s[0]
	neven = s[1]
	return ((nodd*nodd)%M + (neven*(neven+1))%M)%M

l, r = map(int, input().split())
ans = (s_sum(r)-s_sum(l-1))%M
ans += M
ans %= M
print(ans)

#22:20 18-04-2019
#22:22 18-04-2019
#22:23 18-04-2019
