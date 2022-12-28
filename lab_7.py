import logging
import time

logging.basicConfig(level=logging.DEBUG)
logging.debug('This is a debug message!')

logging.info('Admin logged in')

N = 100
ans = [0] * N

#ф-ція, яка зливає масив і рахує к-сть менших е-тів на правій стороні

def merge(arr, left, mid, right):
    
    time_start = time.time()
    n = mid - left + 1
    m = right - mid
    
    ar_1 = [0] * (n)
    ar_2 = [0] * (m)

    for i in range(left, mid + 1):
        ar_1[i - left] = arr[i]

    for i in range (mid + 1, right + 1):
        ar_2[i - mid - 1] = arr[i]

    i = 0
    j = 0
    k = left
    count = 0

    # Цикл для збереж. к-сті менших е-тів на правій стороні, коли
    # обидва масиви мають елементи

    while (i < n and j < m):
        if (ar_1[i][1] <= ar_2[j][1]):
            ans[ar_1[i][0]] += count
            arr[k] = ar_1[i]
            k += 1
            i += 1
        else:
            count += 1
            arr[k] = ar_2[j]
            k += 1
            j += 1

    # Цикл для збереж. к-сті менших е-тів на правій стороні, коли
    # тільки лівий масив має елементи
    
    while (i < n):
        ans[ar_1[i][0]] += count
        arr[k] = ar_1[i]
        k += 1
        i += 1


    # Цикл для збереж. к-сті менших е-тів на правій стороні, коли
    # тільки правий масив має е-ти

    while (j < m):
        arr[k] = ar_2[j]
        k += 1
        j += 1

    time_exe = float('{:.5f}'.format(time.time() - time_start))
    logging.info(f'The "merge" function has finished with {time_exe} s!') 
    
   
    
# ф-ція для виклику сортування злиттям

def mergesort(arr, left, right):
    
    time_start = time.time()
    if (left >= right):
        return
    mid = (left + right) // 2
    mergesort(arr, left, mid)
    mergesort(arr, mid + 1, right)
    merge(arr, left, mid, right)
    time_exe = float('{:.5f}'.format(time.time() - time_start))
    logging.info(f'The "mergesort" function has finished with {time_exe} s!')

# ф-ція для друкування масиву

def print_(arr, n):

    time_start = time.time()
    for i in range(n):
        print(arr[i], end = " ")

    time_exe = float('{:.5f}'.format(time.time() - time_start))
    logging.info(f'The "print_" function has finished with {time_exe} s!')
        

# тестування

arr = []
n = int(input("Enter the amount of elements in your array: "))

print("Enter your array: ")
for i in range (n):
    a = int(input())
    arr.append(a)

print("Your array: ", arr)

array = [[0 for x in range(2)]
        for y in range(n)]

for i in range(n):
    array[i][1] = arr[i]
    array[i][0] = i

mergesort(array, 0, n - 1)
print("Answer: ", end = " ")
print_(ans, n)

logging.info('Admin logged out')

