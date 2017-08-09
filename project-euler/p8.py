num = input()
arr = []
for substring in num:
    arr.append(substring)


largest = 1
for i in range(0, 13):
    largest *= int(arr[i])


# Use a crawling technique to traverse the array
def find_largest(list, init, max, max_so_far):
    max_prod = max
    # Divide if it's fine to do so
    if int(list[init - 1]) != 0:
        max_prod /= int(list[init - 1])
    else:
        max_prod = 1
        for i in range(init, init + 13):
            max_prod *= int(arr[i])
        return find_largest(list, init+1, max_prod, max_so_far)
    max_prod *= int(list[init + 12])
    if max_prod > max_so_far:
        max_so_far = max_prod
    if init < (len(list) - 14):
        return find_largest(list, init+1, max_prod, max_so_far)
    else:
        return max_so_far


print(find_largest(arr, 1, largest, largest))