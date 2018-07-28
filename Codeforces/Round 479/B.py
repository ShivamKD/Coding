'''input
4
AAAA
'''
import re
n = int(input())
s = input()
ans = ""
m = 0
for i in range(1,n):
	p = s[int(i-1):int(i+1)]
	c = 0

	for j in range(1,n):
		if s[j-1:j+1] == p:
			c += 1
	
	if c>m:
		ans = p
		m = c
	
print(ans)