import nltk
nltk.download('words')
from nltk.corpus import words

# Creating a set of english words for validation
english_words=set(words.words())

# decryption without using shift key value and using nltk english library set

def decrypt(text):

    
    for j in range (1,25):
        newtext=""
        key=j
        for i in range(len(text)):
            if text[i].isupper():
                newtext+= chr((ord(text[i])-65-i)%26+65)
            elif text[i].islower():
                newtext+=chr( (ord(text[i])-97-i)%26+97)
            else:
                newtext+=text[i]


        # Split the decrypted text into words and check if all words are in the English word set
        newTextWordList=newtext.split()
        print(newTextWordList)
        is_valid=all(word.lower() in english_words for word in newTextWordList)
        if(is_valid):
            print("Valid decryption with key", s)
            print("Decrypted Text:", newTextWordList)
            break





#  encryption function 
def encrypt(text,key):
    ans=""
    for i in range(len(text)):
        if text[i].isupper():
            ans+= chr((ord(text[i])-65+key)%26+65)
        elif text[i].islower():
            ans+=chr( (ord(text[i])-97+key)%26 +97)
        else:
            ans+=text[i]
    return ans


# main function

s=input("enter the text here: ")
key=int(input("enter the key value: "))
text_encr=encrypt(s,key)
print("encrpyted text: ", text_encr)

decrypt(text_encr)