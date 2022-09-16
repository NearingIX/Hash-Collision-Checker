//Hash Collision Checker

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class hashInput {
public:
    string firstHash;
    string secondHash;
    vector<char> messageVector;

public:
    hashInput() {
    string firstHash = "";
    string secondHash = "";
    vector<char> messageVector;
    };

void gatherHashes() {
    cout << "Input your first hash to compare: " << endl;  
    getline (cin, firstHash);
    cout << "Input your second hash to compare: " << endl;
    getline (cin, secondHash);
};

void checkIfIdentical() {
    if (firstHash == secondHash) {
        cout << "A collision was found. These hashes are identical." << endl;
    }
    else {
        cout << "No mirror collision found. These hashes are not identical." << endl;
    };
};

void compareMessageLengths() {
int lengthDifference = firstHash.length() - secondHash.length();
cout << "firstHash Length: " << firstHash.length() << endl;
cout << "secondHash Length: " << secondHash.length() << endl;

if (firstHash.length() == secondHash.length()) {
    cout << "The provided hashes have the same length.";
}
else if (lengthDifference > 0){
        cout << "The firstHash is " << lengthDifference << " character(s) longer.";
    } else if (lengthDifference < 0){
        lengthDifference = abs(lengthDifference);
        cout << "The secondHash is " << lengthDifference << " character(s) longer.";
    };
    };

void compareMessageSegmants() {
int hashCount = 0;
if (firstHash.length() >= secondHash.length()) { 
for (size_t i = 0; i < firstHash.length(); i++)
{
    if (firstHash[i] == secondHash[i]){
        hashCount += 1;
        char sameChar = firstHash[i];
        messageVector.push_back(sameChar);
    };
};
} else {
for (size_t i = 0; i < secondHash.length(); i++)
{
    if (secondHash[i] == firstHash[i]){
        hashCount += 1;
        char sameChar = secondHash[i];
        messageVector.push_back(sameChar);
    };
};
};
cout << endl << "The two hashes have " << hashCount << " identical character(s) at the same index: ";
};
void printMessageVector() {
for (auto i: messageVector) {
            cout << i << ' ';
    };
};
};

int main() {
    hashInput newInput;
    newInput.gatherHashes();
    newInput.checkIfIdentical();
    newInput.compareMessageLengths();
    newInput.compareMessageSegmants();
    newInput.printMessageVector();
    cout << endl;
    system("pause");
    return 0;
};
