

def encypt_railfence(text,key):

    rail=[['0' for i in range(len(text))] for j in range(key)]

    dir_down=False
    row,col=0,0

    for i in range(len(text)):

        if(row==0) or (row== key-1):
            dir_down= not dir_down
        
        rail[row][col]=text[i]
        col+=1

        if dir_down:
            row+=1
        else:
            row-=1
    result=[]
    for i in range(key):
        for j in range(len(text)):
            print(rail[i][j],end=" ")
            if rail[i][j]!='0':
                result.append(rail[i][j])
        print("\n")
    return("".join(result))


def decryptRailFence(cipher, key):

    rail = [['\n' for i in range(len(cipher))]
                for j in range(key)]
     
    # to find the direction
    dir_down = None
    row, col = 0, 0
     
    # mark the places with '*'
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False
         
        # place the marker
        rail[row][col] = '*'
        col += 1
         
        # find the next row
        # using direction flag
        if dir_down:
            row += 1
        else:
            row -= 1
             

    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if ((rail[i][j] == '*') and
            (index < len(cipher))):
                rail[i][j] = cipher[index]
                index += 1

    result = []
    row, col = 0, 0
    for i in range(len(cipher)):
         
        # check the direction of flow
        if row == 0:
            dir_down = True
        if row == key-1:
            dir_down = False
             
        # place the marker
        if (rail[row][col] != '*'):
            result.append(rail[row][col])
            col += 1
             
        # find the next row using
        # direction flag
        if dir_down:
            row += 1
        else:
            row -= 1
    return("".join(result))

# Main
s=input("enter the text to encypt: ")
key=int(input("enter the value of rail fence: "))
text_enc=encypt_railfence(s,key)
print("enrypted text", text_enc)
text_dec=decryptRailFence(text_enc,key)
print("decypted Text: ",text_dec)