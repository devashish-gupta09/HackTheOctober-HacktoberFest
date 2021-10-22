def compute_lcm(a, b):

   if a > b:
       g = a
   else:
       g = b

   while(True):
       if((g % a == 0) and (g % b == 0)):
           lcm = g
           break
       g += 1

   return lcm

n1 = 54
n2 = 24

print("L.C.M : ", compute_lcm(n1, n2))
