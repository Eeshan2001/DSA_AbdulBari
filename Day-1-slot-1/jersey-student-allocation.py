# N = 5
# B = [2,3,1,5,4]
# Output : 6 
n = int(input())
B = []
arr = []
for i in range(n):
   B.append(int(input()))
   arr.append(i+1)

ans = 0
while 1:
   ans += 1
   ar = [None]*n
   for i in range(n):
       ar[i] = arr[B[i]-1]
   if ar == sorted(ar):
       break
   arr = ar
print(ans)