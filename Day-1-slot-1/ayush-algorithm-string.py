# N = 4
# string A = abab
# string B = abaa
# OUTPUT : 1


n = int(input())
a = input()
b = input()
if a == b:
    print(1)
res,res2 = "",""
for x in range(n):
    if a[x] != b[x]:
        res += a[x]
        res2 += b[x]
ans = 0
for i in a:
    if ans != 0:
        break
    if i not in b:
        print(-1)
        break
    else:
        for x in set(res2):
            if x not in a:
                print(-1)
                ans += 1
                break
            else:
                print(len(set(res2)))
                ans += 1
                break
    if ans == 1:
        break