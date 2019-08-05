n = 100000
print(100000)
a = [40000000, 20000000, 60000000]
b = [20000000, 30000000, 100000000]
for i in range(n):
	ind = i%3
	print(str(a[ind])+' '+str(b[ind]))
