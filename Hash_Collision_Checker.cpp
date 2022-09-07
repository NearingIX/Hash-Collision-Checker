//Hash Collision Checker

#include <iostream>
#include <string>

using namespace std;

class hashInput {
public:
    string firstHash;
    string secondHash;

public:
    hashInput() {
    string firstHash = "";
    string secondHash = "";
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
};

int main() {
    hashInput newInput;
    newInput.gatherHashes();
    newInput.checkIfIdentical();
    newInput.compareMessageLengths();
    return 0;
};
