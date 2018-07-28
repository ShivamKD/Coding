'''input
1
1111
'''
def ii():
	return int(input())

def ai():
	return map(int,input().split())
n = ii()
s = input()
one  = zero = 0
for ch in s:
	if ch == '1':
		one = 1
	else:
		zero += 1
output = "1" * one
if one is not 0:
	output = output + zero * "0"
else:
	output = "0"
print(output)