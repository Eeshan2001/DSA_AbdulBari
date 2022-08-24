
n1=int(input())
n2=int(input())
l=list(map(int,input().split()))
k=list(map(int,input().split()))
j=l+k
j=list(set(j))
j.sort()
n = len(j)
if n%2 == 0:
    ans = (j[n//2]+j[(n-1)//2])/2
    print('{:.2f}'.format(round(ans,2)))
else:
    ans = j[n//2]
    print('{:.2f}'.format(round(ans,2)))