def timeConversion(s):
    h, t = int(s[0:2]), s[2:-2]
    
    if "PM" in s:
        r = h + 12
        if r == 24:
            return str(1) + str(2) + t
        else:
            return str(r) + t

    elif "AM" in s:
        if h == 12:
            return str(0) + str(0) + t
        else:
            return s[0:-2]
        

if __name__ == '__main__':

    # Input format: 10:21 AM
    print("Enter time: ")
    s = input()

    result = timeConversion(s)

    print(result)


