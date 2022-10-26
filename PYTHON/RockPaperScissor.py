#Rock Paper Scissor
import random
from typing import ValuesView





print("1.rock"+"\n"+"2.paper"+"\n"+"3.scissor")
#Taking user input
user=int(input("Please enter your command: "))
#Taking computer input
computer=random.randint(1,3)
rock=int(1)
paper=int(2)
scissor=int(3)

#Conditions of Game
if user==computer:
    print("It's a tie!")
    
elif user==1:  #user==rock
    if computer==2:
        print("Paper catches rock; You Loose!")    
    else:
        print("Rock smashes scissor; You Won!")
        
elif user==2:   #user==paper
    if computer==1:
        print("Paper catches rock; You Won!")
    else:
        print("Scissor cuts paper; You Loose!")

elif user==3:   #user==scissor
    if computer==1:
        print("Rock smashes scissor; You Loose!")
    else:
        print("Scissor cuts paper; You Won!")
        
else:
    print("Error!")
