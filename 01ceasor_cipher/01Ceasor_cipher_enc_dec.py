


def encrypt(text, key):
    ans = ""
    for i in range(len(text)):
        if text[i].isupper():
            ans += chr(((ord(text[i]) - 65 + key) % 26) + 65)
        elif text[i].islower():
            ans += chr(((ord(text[i]) - 97 + key) % 26) + 97)
        else:
            ans += text[i]

    return ans

def decrypt(text,key):
    ans=""

    for i in range(len(text)):
        if text[i].isupper():
            ans+=  chr((ord(text[i])-65-key)%26+65)
        elif text[i].islower():
            ans+= chr((ord(text[i]) - 97 -key)%26+97)
        else:
            ans+=text[i]
    return ans


s=input("enter string value:- ")
key=int(input("enter key value: "))

text_inc=encrypt(s,key)
print("cipher text:- ",text_inc)
text_dec=decrypt(text_inc,key)
print("decytpted text",text_dec)