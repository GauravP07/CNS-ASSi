


def encrypt(message, key):
    key_order = sorted(range(len(key)), key=lambda k: key[k])
    num_columns = len(key)
    num_rows = -(-len(message) // num_columns)
    matrix = [[' ' for _ in range(num_columns)] for _ in range(num_rows)]

    index = 0
    for i in range(num_rows):
        for j in key_order:
            if index < len(message):
                matrix[i][j] = message[index]
                index += 1 

    print("Matrix:")
    for row in matrix:
        print(' '.join(row))

    cipher_text = ''
    for j in range(num_columns):
        for i in range(num_rows):
            cipher_text += matrix[i][j]

    return cipher_text

def decrypt(cipher_text, key):
    key_order = sorted(range(len(key)), key=lambda k: key[k])
    num_columns = len(key)
    num_rows = -(-len(cipher_text) // num_columns)
    matrix = [[' ' for _ in range(num_columns)] for _ in range(num_rows)]

    index = 0
    for j in range(num_columns):
        for i in range(num_rows):
            matrix[i][j] = cipher_text[index]
            index += 1

    print("Matrix:")
    for row in matrix:
        print(' '.join(row))

    plain_text = ''
    for i in range(num_rows):
        for j in key_order:
            plain_text += matrix[i][j]

    return plain_text

# Example
text = "Hello world Gaurav"
key = "HACK"

# Encryption
encrypted_text = encrypt(text, key)
print("\nEncrypted Text:", encrypted_text)

# Decryption
decrypted_text = decrypt(encrypted_text, key)
print("\nDecrypted Text:", decrypted_text)
