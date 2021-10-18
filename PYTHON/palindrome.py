def isPalindrome(s):
    return s == s[::-1]
 
 
# Driver code
val = input("Enter your value of the string: ")
ans = isPalindrome(val)
 
if ans:
    print("Yes")
else:
    print("No")
