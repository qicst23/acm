s = input()
n = int(input())
month = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']

print(month[(month.index(s) + n) % 12])
