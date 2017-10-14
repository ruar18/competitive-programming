n = int(input())
string = ''
for i in range(n):
	string += input()
string = string.lower()
t = string.count('t')
s = string.count('s')

if t > s:
	print("English")
else:
	print("French")