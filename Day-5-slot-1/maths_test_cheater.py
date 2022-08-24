# N=5 K=2
# M = [1,1,2,5,2]
# X,Y = 1 3
#       4 2

def fun(x, y, n):
    arr[x - 1] = y
    ans = 1
    for i in range(1, n):
       if arr[i] != arr[i - 1]:
           ans += 1
    return ans


n,k = map(int,input().split())
arr = list(map(int,input().strip().split()))[:n]
for i in range(k):
   x,y = map(int,input().split())
   print(fun(x, y, n), end="")