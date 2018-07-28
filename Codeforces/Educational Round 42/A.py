'''input
15
'''
def ii():
	return int(input())
def i():
	return input()

x = ii()
s = str(x)
for i in range(len(s)):
	n = str[0:i] + str[i+1:]
	if n[0]!='0':
		k = int(n)
		p = int(sqrt(k))
		if 