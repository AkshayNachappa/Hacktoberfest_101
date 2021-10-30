#this is a python program.
def hcf(a,b):
  if a>b:
    smaller =b
  else: 
    smaller=a
  for i in range(1,smaller+1):
    if((a%i==0) and(b%i==0)):
        hcf=i
  return hcf
a=50
b=30
print("The HCF of above two numbers is ",hcf(a,b))
