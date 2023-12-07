#include <iostream>
#include <string>
using namespace std;

void generatePlayfairMatrix(string key, char matrix[5][5]) {
    string alphabet = "abcdefghiklmnopqrstuvwxyz";
    string uniqueKey = key;

    for (char c : alphabet) {
        if (c != 'j' && uniqueKey.find(c) == string::npos) {
            uniqueKey += c;
        }
    }

    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = uniqueKey[index++];
        }
    }
}

string prepareMessage(string message) {
    string result = "";
    for (char c : message) {
        if (c != ' ') {
            if (c == 'j') {
                result += 'i';
            } else {
                result += c;
            }
        }
    }

    string preparedMessage = "";
    for (size_t i = 0; i < result.size(); i += 2) {
        if (i + 1 < result.size()) {
            if (result[i] == result[i + 1]) {
                preparedMessage += result[i];
                preparedMessage += 'x';
            } else {
                preparedMessage += result[i];
                preparedMessage += result[i + 1];
            }
        } else {
            preparedMessage += result[i];
            preparedMessage += 'x';
        }
    }

    return preparedMessage;
}

string playfairEncrypt(string message, char matrix[5][5]) {


    string encryptedMessage = "";
    for (int i = 0; i < message.size(); i += 2) {
        char firstChar = message[i];
        char secondChar = message[i + 1];
        int row1, col1, row2, col2;

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (matrix[row][col] == firstChar) {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == secondChar) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        if (row1 == row2) {
            encryptedMessage += matrix[row1][(col1 + 1) % 5];
            encryptedMessage += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            encryptedMessage += matrix[(row1 + 1) % 5][col1];
            encryptedMessage += matrix[(row2 + 1) % 5][col2];
        } else {
            encryptedMessage += matrix[row1][col2];
            encryptedMessage += matrix[row2][col1];
        }
    }
    return encryptedMessage;
}

int main() {
    string key = "monarchy";
    string message = "hellowwoorld";

    char matrix[5][5];
    generatePlayfairMatrix(key, matrix);

    cout<<"Playfair Matrix:" <<endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }

    string preparedMessage = prepareMessage(message);
    cout<<"Prepared Message: "<<preparedMessage<<endl;

    string encryptedMessage = playfairEncrypt(preparedMessage, matrix);
    cout<<"Encrypted Message: "<<encryptedMessage<<endl;

    return 0;
}
