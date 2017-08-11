N = int(input())


for i in range(N):
	num = int(input())
	if num == 0:
		print("0000")
		continue
	s = ''
	count = 0
	while num > 0:
		s = str(num % 2) + s
		num //= 2
		count += 1
		if count % 4 == 0 and num != 0:
			s = ' ' + s
	if count % 4 != 0:
		s = '0' * (4-count%4) + s
	print(s)