#include<iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Encryptable{
    virtual void encrypt(string plaintext) = 0;
    virtual void decrypt(string cipherText) = 0;
};

class ROT13 : public Encryptable{
    public : 
    void encrypt(string plaintext) override {
        for (int i = 0; i < plaintext.length(); i++) //a h s a n
        {
            if (plaintext[i] >= 'a' && plaintext[i] <= 'm')
            {
                plaintext[i] += 13;
            }
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'M')
            {
                plaintext[i] += 13;
            }
            else if (plaintext[i] >= 'n' && plaintext[i] <= 'z')
            {
                plaintext[i] -= 13;
            }
            else if (plaintext[i] >= 'N' && plaintext[i] <= 'Z')
            {
                plaintext[i] -= 13;
            }
            else if (plaintext[i] >= '0' && plaintext[i] <= '4')
            {
                plaintext[i] += 5;
            }
            else if (plaintext[i] >= '5' && plaintext[i] <= '9')
            {
                plaintext[i] -= 5;
            }
        }
        cout << plaintext << endl;

    };
    void decrypt(string cipherText) override {
        encrypt(cipherText);
    };
};

class RandomCipher : public Encryptable {
private:
    char original[62];
    char shuffled[62];
    char reverseMap[128];
    string encryptedText;
    string decryptedText;

public:
    RandomCipher() {
        srand(time(0));
        int idx = 0;

        // Fill original array with 0-9, A-Z, a-z
        for (char c = '0'; c <= '9'; c++) original[idx++] = c;
        for (char c = 'A'; c <= 'Z'; c++) original[idx++] = c;
        for (char c = 'a'; c <= 'z'; c++) original[idx++] = c;

        // Copy and shuffle shuffled array
        for (int i = 0; i < 62; i++) shuffled[i] = original[i];
        for (int i = 0; i < 62; i++) {
            int j = rand() % 62;
            char temp = shuffled[i];
            shuffled[i] = shuffled[j];
            shuffled[j] = temp;
        }

        // Build reverse map
        for (int i = 0; i < 128; i++) reverseMap[i] = 0;
        for (int i = 0; i < 62; i++) {
            reverseMap[(int)shuffled[i]] = original[i];
        }
    }

    void encrypt(string plaintext) override {
        string result = "";
        for (int i = 0; i < plaintext.length(); i++) {
            char c = plaintext[i];
            bool found = false;
            for (int j = 0; j < 62; j++) {
                if (c == original[j]) {
                    result += shuffled[j];
                    found = true;
                    break;
                }
            }
            if (!found) result += c;
        }
        encryptedText = result;
        cout << "Encrypted: " << encryptedText << endl;
    }

    void decrypt(string cipherText) override {
        string result = "";
        for (int i = 0; i < cipherText.length(); i++) {
            char c = cipherText[i];
            if (c >= 0 && c < 128 && reverseMap[(int)c] != 0) {
                result += reverseMap[(int)c];
            } else {
                result += c;
            }
        }
        decryptedText = result;
        cout << "Decrypted: " << decryptedText << endl;
    }

    string getEncrypted() {
        return encryptedText;
    }

    string getDecrypted() {
        return decryptedText;
    }
};

int main()
{
    ROT13 r3;
    r3.encrypt("A2hsanz");
    r3.decrypt("N7ufnam");

    
    RandomCipher rc;
    rc.encrypt("Hello123");
    string encrypted = rc.getEncrypted();
    rc.decrypt(encrypted);
    string decrypted = rc.getDecrypted();
    cout << "\nOriginal: Hello123" << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}
