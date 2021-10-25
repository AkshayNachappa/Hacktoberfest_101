# The one time pad can be cryptographically secure, but not when you know the key. 
# Can you solve this? We've given you the encrypted flag, key, and a table 
# to help UFJKXQZQUNB with the key of SOLVECRYPTO. 
# Can you use this table to solve it?.

#SOLVECRYPTO -- key
#UFJKXQZQUNB -- enc_text


#RONI -- plain_text | RPPL enc_text
#ABCD -- key        | key'in alfabe değerine göre kaydırma
#0123
#index(R) + index(A) = R
#17 + 0 = 17

import sys
alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]

def alpPadEncode(plain_text: str, key: str)->str:
    out = ''
    for i in range(len(key)):
        out += alphabet[(alphabet.index(plain_text[i]) + alphabet.index(key[i])) % len(alphabet)]

    return out

def alpPadDecode(enc_text:str, key: str)->str:
    out = ''
    for i in range(len(key)):
        out += alphabet[(alphabet.index(enc_text[i]) - alphabet.index(key[i])) % len(alphabet)]
    
    return out


if __name__ == "__main__":
    method = sys.argv[1]
    text = sys.argv[2].upper()
    key = sys.argv[3]
    assert len(text) == len(key), "Text and Key length needs to be equal!"

    if method == "encode":
        print(alpPadEncode(text, key))
    elif method == "decode":
        print(alpPadDecode(text, key))
    else:
        print("python padTable.py [encode|decode] [text] [key]")

        

