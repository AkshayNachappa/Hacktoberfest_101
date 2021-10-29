# @author : Harsh Gupta 
# Space Complexiety : O(n)
# Time Complexiety : O(n*n)

def lcs(s1 , s2):
   m, n = len(s1), len(s2) 
   previous_list, current_list = [0]*(n+1), [0]*(n+1)
   #taking the index from 1 
   for i in range(1, m+1):
       for j in range(1, n+1):
           if s1[i-1] == s2[j-1]:
               current_list[j] = 1 + previous_list[j-1]
           else:
               current_list[j] = max(current_list[j-1],previous_list[j])

       current_list, previous_list = previous_list, current_list
   return previous_list[n]

#taking the strings input
s1 = input()
s2 = input()
print(lcs(s1, s2))
