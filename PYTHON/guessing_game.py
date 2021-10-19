name = input("Enter Your Name: ")
print("\n---Hello", name + '!' " Welcome to the Guessing Game---")
print("---You have to Guess a Name of any Animal! You have 3 chances only.---" )

secret_word = "cat"
chances = 3
animal = ""

while chances >= 1:
    animal = input("\nEnter any animal name here: ")
    if secret_word != animal.lower() and chances >= 2:
        chances -= 1
        print("\nOops. Wrong!\n", chances, "chances left")
    elif secret_word == animal.lower():
        print("\nYippee! You got the correct answer. \nYou Win!")
        break;
    else:
        print("\nYou lost all the chances. Try Again Later!")
        break;

print("---Thank you for playing the game!---")

