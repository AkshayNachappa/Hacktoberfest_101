import random

def math_game():

  print("Hello there, this math game will have questions with increasing difficulty levels.", 

        "You will have total 3 attempts. You will lose an attempt with each incorrect answer.")

  print("Are you ready to play.[y/n]")

  ready=input()

  attempt=3

  score=0

  n=10

  count=0

  if(ready=='y' or ready=='Y'):

    while(attempt>0):

      count+=1

      a=random.randint(1,n)

      b=random.randint(1,n)

      correct_ans=a+b

      print("What is ",a,"+",b,"?")

      ans=int(input())




      if (ans!=correct_ans):

        attempt-=1

        print("Incorrect!!, attempts left =",attempt)

      else:

        score+=1

        print("Correct!!")

      n*=2

    print("Thank you, your accuracy= ",score*100//count,"%")

  else:

      print("Thanks for being here.")

math_game()
