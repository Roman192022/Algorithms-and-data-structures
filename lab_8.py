import logging
import time
import matplotlib.pyplot as plt
import numpy as np

logging.basicConfig(level=logging.INFO)
logging.info('Admin logged in')

def cocktail_sort(n):
    A = np.random.randint(0, 100, n)
    height = np.arange(0, len(A), 1)
    time_start = time.time()
    for k in range(len(A) - 1, 0, -1):
        swapped = False
        for i in range(k, 0, -1):
            plt.bar(height, A)
            plt.pause(0.01)
            plt.clf()
            if A[i] < A[i-1]: 
                a = A[i]
                b = A[i-1]
                A[i] = b
                A[i-1] = a
                swapped = True

        for i in range(k):
            plt.bar(height, A)
            plt.pause(0.01)
            plt.clf()
            if A[i] > A[i+1]:
                a = A[i]
                b = A[i+1]
                A[i] = b
                A[i+1] = a
                swapped = True
                
      
        if not swapped:
            time_exe = float('{:.5f}'.format(time.time() - time_start))
            logging.info(f'The "cocktail_sort" function has finished with {time_exe} s!')
            return A
        

n = int(input("Enter n: "))
    
arr_sort = cocktail_sort(n)

print("Sorted array: ")
for i in range (n):
    print(arr_sort[i], end = " ")


logging.info('Admin logged out')
