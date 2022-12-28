import threading 
import time 
def merge_sort(arr):
  if len(arr)==1:
    return(arr)
  else:
     mid=len(arr)//2

     L= arr[:mid]
     R= arr[mid:]

     merge_sort(L)
     merge_sort(R)

     i = j = k = 0
     while i < len(L) and j < len(R):
       if L[i] < R[j]:
         arr[k] = L[i]
         i += 1
       else:
         arr[k]=R[j]
         j+=1
       k+=1
     while i < len(L):
       arr[k] = L[i]
       i += 1
       k += 1
     while j < len(R):
       arr[k] = R[j]
       j += 1
       k += 1
arr=[]
n=int(input("Number of elements in array:"))
for i in range(0,n):
   l=int(input())
   arr.append(l)
print("Unsorted array:", arr)
merge_sort(arr)
print("Sorted array:",arr)
t1 = threading.Thread(target=merge_sort, args=(arr,))  #Thread 1
t2 = threading.Thread(target=merge_sort, args=(arr,))  #Thread 2

t1.start()
time.sleep(1.0)
t2.start()

t1.join()
t2.join()
print("done")
