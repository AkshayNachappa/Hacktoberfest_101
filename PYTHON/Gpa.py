# Template for P21

def main():
    # Write your code below
    Quiz_ob = int(input())
    Exam_ob = int(input())
    Assign_ob = int(input())
    Project_ob = int(input())
    # Take inputs for the four assessments. Keep in mind that the input will be in order as given in the question.
    GPA = float((15*(Quiz_ob/20) + 40*(Exam_ob/100) + 20*(Assign_ob/100) + 25*(Project_ob/50))/10)

    # Calculate the GPA.


    # Round the GPA to two decimal places
    GPA = round(GPA,2)

    # Print the GPA
    print(GPA)

# This is required to ensure that we can import your solve function without activating other parts of code
if __name__ == "__main__":
    main()