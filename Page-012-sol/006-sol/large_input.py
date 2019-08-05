MAX = 100000
#MAX = 35

"""
n = MAX-1
k = MAX
"""

"""
n = MAX
k = MAX-1
"""

n = MAX
k = MAX

print(n, k)

s = ''.join([chr(ord('a')+1+(i%25)) for i in range(n)])

print(s)
