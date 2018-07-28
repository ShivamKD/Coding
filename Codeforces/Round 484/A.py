'''input
4
0100
'''

def ii():
	return int(input())
def ai():
	return map(int,input().split())

n = ii()
s = input()
if n== 1 :
	if s == "1":
		print("Yes")
	else:
		print("No")
	exit(0)
#print(s[n-2:n])
#print(c)
#print(n // 2 + n % 2)
if "11" in s or "000" in s:
	print("No")
else :
	if s[0 : 2] =="00" or s[n-2:n] == "00":
		print("No")
	else:
		print("Yes")

