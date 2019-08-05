n = 260
m = 500
print(str(n)+' '+str(m))
a = ['1 ', '2 ']
for i in range(n):
	print(a[i%2]*m)
