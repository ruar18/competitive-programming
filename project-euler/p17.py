from num2words import num2words
ans = 0
for i in range(1, 1001):
    word=num2words(i)
    for c in word:
        if c != ' ' and c != '-': ans += 1
print(ans)
