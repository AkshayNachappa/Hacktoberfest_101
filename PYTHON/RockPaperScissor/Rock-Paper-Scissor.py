''' IMPLEMENTATION OF ROCK PAPER AND SCISSOR GAME USING PYTHON

 WINNING RULES :
    1. ROCK VS PAPER ----> PAPER WINS
    2. ROCK VS SCISSOR ----> ROCK WINS
    3. SCISSOR VS PAPER ----> PAPER WINS'''

#importing random module
import random

print('''Winning rules of Rock-Paper-Scissor Game :\n
       1. Rock Vs Paper ----> Paper Wins\n
       2. Rock Vs Scissor ----> Rock Wins\n
       3. Scissor vs Paper ----> Paper Wins''')
userpoints = 0
comppoints = 0
print("\n")
print("Number of Games :")
n = int(input()) # No.of games
for i in range(n):
  print('''Enter Your Choice :\n
              1. Rock\n
              2. Paper\n
              3. Scissor''')
  # User input
  User_Choice = int(input("User Turn :"))

  #Looping until the user enters an invalid input
  while User_Choice>3 & User_Choice<1:
    User_Choice = int(input("enter valid input: "))

  if User_Choice == 1:
    Choice_Name = 'Rock'
  elif User_Choice == 2:
    Choice_Name = 'Paper'
  else:
    Choice_Name = 'Scissor'
  print("User choice is "+Choice_Name)
  print("Computer's Turn")
  Comp_Choice = random.randint(1, 3)
  # looping until comp_choice value is equal to the choice value
  while Comp_Choice == User_Choice:
    Comp_Choice = random.randint(1, 3)
  
  if Comp_Choice==1:
    Comp_Choice_Name = 'Rock'
  elif Comp_Choice==2:
    Comp_Choice_Name = 'Paper'
  else:
    Comp_Choice_Name = 'Scissor'
  print("Computer choice is: " + Comp_Choice_Name)
  print(Choice_Name + " V/s " + Comp_Choice_Name)
  
  #Winning Conditions
  if((User_Choice == 1 and Comp_Choice == 2) or
      (User_Choice == 2 and Comp_Choice ==1 )):
        result = "paper"
        print("Result :"+result)
        if User_Choice == 2:
          userpoints+=1
        else:
          comppoints+=1
        print("\n")
          
  elif((User_Choice == 1 and Comp_Choice == 3) or
        (User_Choice == 3 and Comp_Choice == 1)):
        result = "Rock"
        print("Result :"+result)
        if User_Choice == 1:
          userpoints+=1
        else:
          comppoints+=1
        print("\n")
  else:
        result = "scissor"
        print("Result :"+result)
        if User_Choice == 3:
          userpoints+=1
        else:
          comppoints+=1
        print("\n")
print("User's Points :",userpoints)
print("Computer's Points :",comppoints)
if userpoints>comppoints:
      print("User won with ",userpoints," points")
elif userpoints==comppoints:
      print("Tie Game")
else:
      print("Computer won with ",comppoints," points")
