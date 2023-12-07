#include <bits/stdc++.h>
using namespace std;

set<int> prime;

int public_key;
int private_key;
int n;

void primefiller() {
    vector<bool> sieve(250, true);

    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; i < 250; i++) {
        for (int j = i * 2; j < 250; j += i) {
            sieve[j] = false;
        }
    }

    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i]) {
            cout << i << " ";
            prime.insert(i);
        }
    }
    cout << endl;
}

int pickrandomprime() {
    int k = rand() % prime.size();
    auto it = prime.begin();

    while (k--)
        it++;
    
    int ret = *it;
    prime.erase(it);
    return ret;
}

void setkeys() {
    int prime1 = pickrandomprime();
    cout << "prime no. p = " << prime1 << endl;
    int prime2 = pickrandomprime();
    cout << "prime no. q = " << prime2 << endl;

    n = prime1 * prime2;
    cout << "n = " << n << endl;
    int fi = (prime1 - 1) * (prime2 - 1);
    cout << "Phi of n = " << fi << endl;

    int e = 2;
    while (1) {
        if (__gcd(e, fi) == 1)
            break;
        e++;
    } 

    public_key = e;
    cout << "Public key = " << public_key << endl;

    int d = 2;
    while (1) {
        if ((d * e) % fi == 1)
            break;
        d++;
    }

    private_key = d;
    cout << "Private key = " << private_key << endl;
}

long long int encrypt(double message) {
    int e = public_key;
    long long int encrypted_text = 1;
    while (e--) {
        encrypted_text *= message;
        encrypted_text %= n;
    }
    return encrypted_text;
}

long long int decrypt(int encrypted_text) {
    int d = private_key;
    long long int decrypted = 1;
    while (d--) {
        decrypted *= encrypted_text;
        decrypted %= n;
    }
    return decrypted;
}

vector<int> encoder(string message) {
    vector<int> form;
    for (auto& letter : message)
        form.push_back(encrypt((int)letter));
    return form;
}

string decoder(vector<int> encoded) {
    string s;
    for (auto& num : encoded)
        s += decrypt(num);
    return s;
}

int main() {
    cout << "Prime Set : " << endl;
    primefiller();
    cout << endl;

    setkeys();

    string message;
    cout << "\n\nEnter the message : ";
    getline(cin, message);

    vector<int> coded = encoder(message);

    cout << "\n\nThe encoded message (encrypted by public key) : \n";

    for (auto& p : coded) {
        cout << p;
    }

    cout << "\n\nThe decoded message (decrypted by private key) : \n";
    cout << decoder(coded) << endl;

    return 0;
}
