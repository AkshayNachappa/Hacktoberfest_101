import sys
mors_code ={'.-':'A','-...':'B','-.-.':'C','-..':'D','.':'E','..-.':'F','--.':'G','....':'H','..':'I','.---':'J','-.-':'K','.-..':'L','--':'M','-.':'N','---':'O','.--.':'P','--.-':'Q','.-.':'R','...':'S','-':'T','..-':'U','...-':'V','.--':'W','-..-':'X','-.--':'Y','--..':'Z','.----':'1','..---':'2','...--':'3','....-':'4','.....':'5','-....':'6','--...':'7','---..':'8','----.':'9','-----':'0'}

def morseDecode(input: list or str)-> str:
    '''
    :Decode morse codes
    '''
    out = ''
    if isinstance(input, str):
        input = input.split(" ")
    for char in input:
        temp = ""
        for letter in char:
            if letter in [".", "-"]:
                temp += letter
        try:
            assert temp in mors_code, "Invalid Morse Code"
            decoded = mors_code[temp]
            char = char.replace(temp, decoded)
            out += char
        except Exception as e:
            print("{0} is an invalid morse code!".format(temp))
            print(e)
    return out

def morseEncode(input: list or str)-> str:
    '''
    :Encode string to morse code
    '''
    out = ''
    for char in input:
        found = False
        for mors, value in mors_code.items():
            if char.upper() == value:
                out+=mors+" "
                found = True
        if not found:
            raise Exception("{0} is an invalid character!\nYour character needs to be alphanumeric".format(char))
                    
    return out


if __name__ == "__main__":
    method = sys.argv[1]
    if method == "decode":
        print(morseDecode(sys.argv[2:]))
    elif method == "encode":
        print(morseEncode(sys.argv[2:]))
    else:
        print("morse.py [encode|decode] text")
    print(morseDecode(".--. .. -.-. --- -.-. - ..-. {-- ----- .-. ... ...-- -.-. ----- -.. ...-- .---- ... ..-. ..- -. ...-- ....- ---.. ---.. ---.. --... .---- ----- .....}"))