#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function to split a string based on a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void printTabularForm(const string& referenceString, int frames) {
    vector<string> references = split(referenceString, ' ');
    int pointer = 0;
    int pageFaults = 0;
    vector<int> arr(frames, -1);
    vector<bool> secondChance(frames, false);

    cout << "-----------------------------------------" << endl;
    cout << "| Reference | Page Frames | Page Faults? |" << endl;
    cout << "-----------------------------------------" << endl;

    for (const auto& ref : references) {
        int x = stoi(ref);
        bool found = false;

        for (int i = 0; i < frames; i++) {
            if (arr[i] == x) {
                secondChance[i] = true;
                found = true;
                break;
            }
        }

        if (!found) {
            pageFaults++;
            while (true) {
                if (!secondChance[pointer]) {
                    arr[pointer] = x;
                    pointer = (pointer + 1) % frames;
                    break;
                }
                secondChance[pointer] = false;
                pointer = (pointer + 1) % frames;
            }
        }

        cout << "|     " << x << "     |";
        for (int i = 0; i < frames; i++) {
            if (arr[i] != -1) {
                cout << "     " << arr[i] << "      |";
            } else {
                cout << "     -      |";
            }
        }
        cout << "     " << (found ? "No" : "Yes") << "      |" << endl;
        cout << "-----------------------------------------" << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    string referenceString;
    int frames;

    cout << "Enter the reference string separated by spaces: ";
    getline(cin, referenceString);

    cout << "Enter the number of frames: ";
    cin >> frames;

    printTabularForm(referenceString, frames);

    return 0;
}
