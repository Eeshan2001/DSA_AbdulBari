# n = 10 k=15
# arr [5 3 7 14 18 1 18 4 8 3]
def fun(arr, n,k):
    for i in range(n):
        sum = arr[i]
        if i+1 < n:
            for j in range(i+1,n):
                sum += arr[j]
                if sum == k:
                    return i+1,j+1
                    break
                if sum > k:
                    break

n,k = map(int,input().split())
ar = list(map(int, input().split()))
print(*fun(ar, n,k))