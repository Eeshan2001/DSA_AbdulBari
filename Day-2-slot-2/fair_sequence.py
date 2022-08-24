n = int(input())
l = list(map(int,input().split()))
p=[]
ne = []
for i in l:
    if i>0:
        p.append(i)
    else:
        ne.append(i)
if len(p) > 0:
    pmax = max(p)
else:
    pmax=0
if len(ne) > 0:
    nmax = max(ne)
else:
    nmax= 0
print(pmax+nmax)


# def fun(arr, n):
#    ans = []
#    t = 1
#    if arr[0] > 0:
#        t = 0
#    i = 0
#    while i < n:
#        if t == 0:
#            j = i
#            while j < n:
#                if arr[j] > 0:
#                    j += 1
#                else:
#                    break
#            ans.append(max(arr[i:j]))
#            i = j
#            t = 1
#        else:
#            j = i
#            while j < n:
#                if arr[j] < 0:
#                    j += 1
#                else:
#                    break
#            ans.append(max(arr[i:j]))
#            i = j
#            t = 0
#    return sum(ans)


# n = int(input())
# ar = list(map(int, input().split()))
# print(fun(ar, n))
