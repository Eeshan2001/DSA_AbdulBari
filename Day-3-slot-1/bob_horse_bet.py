#  N= 10 K=100
# n[] = [30,40,50,20,20,10,90,10,10,10]
# output : 3 [50,20,20]

def fun(n,k,arr):
    ans = 0
    if min(arr) < k:
        ans = 1
    for i in range(n-1):
        for j in range(i+1,n):
            if sum(arr[i:j]) < k:
                ans = max(ans,j-i)
            else:
                break
    return ans

n,k  = map(int,input().split())
arr = list(map(int, input().split()))
print(fun(n,k,arr))