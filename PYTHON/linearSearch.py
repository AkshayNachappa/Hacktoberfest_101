print('Program for Linear Search')
numbers=[10,23,15,40,43,35,22,60,55,45,70,80,75]#the array of numbers to be searched
print('Enter the number to be searched: ')
num = int(input())#user inputs the number to be searched
loc=-1#location is initally set to -1 to indicate number is not present
flag='is not'#flag is initially set to number not present
for i in range(len(numbers)):#loop over the entire array to see a match
    if numbers[i]==num:#if a match is found
        loc=i+1#add 1 to index as index of array starts at 0
        flag='is'#set flag to number 'is' present
        break#once match found, exit loop
print('The number '+str(num)+' '+flag+' present in the array "numbers"')
print('It is present at location: '+str(i+1))
        