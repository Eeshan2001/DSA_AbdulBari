def getMaxVol(money, price, volume, n):
    K = []
    for i in range(n + 1):
       temp = []
       for j in range(money + 1):
           temp.append(0)
       K.append(temp)
    for i in range(n + 1):
       for m in range(money + 1):
           if i == 0 or m == 0:
               K[i][m] = 0
           elif price[i - 1] <= m:
               K[i][m] = max(volume[i - 1] + K[i - 1][m - price[i - 1]], K[i - 1][m])
           else:
               K[i][m] = K[i - 1][m]
    return K[n][money]


N, money = map(int, input().split())
price = list(map(int, input().split()))
volume = list(map(int, input().split()))
print(getMaxVol(money, price, volume, len(volume)))