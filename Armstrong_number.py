n = int(input("Input a checking number: "))

s = 0

t = n
while t > 0:
   digit = t % 10
   s += digit ** 3
   t //= 10

if n == s:
   print(n,"is an Armstrong number")
else:
   print(n,"is not an Armstrong number")
