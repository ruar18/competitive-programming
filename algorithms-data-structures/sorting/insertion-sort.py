# Implementation of the insertion-sort sorting algorithm
# O(N^2)

# Insertion sort
def insertionSort(a):
    final = a
    # Loop through every integer to be sorted
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        # Find ideal location
        while j >= 0 and final[j] > key:
            final[j+1] = final[j]
            j -= 1
        final[j+1] = key
    return final

# Get array from input
array = list(map(int, input().split()))

print(insertionSort(array))
