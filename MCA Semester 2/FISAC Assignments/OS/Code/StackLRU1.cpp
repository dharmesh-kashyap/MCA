#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

void lruPageReplacement(const vector<int>& pages, int capacity) {
    stack<int> s;
    unordered_set<int> present;
    int pageFaults = 0;

    for (int page : pages) {
        if (present.find(page) == present.end()) {
            if (s.size() == capacity) {
                int lruPage = s.top();
                s.pop();
                present.erase(lruPage);
            }
            s.push(page);
            present.insert(page);
            pageFaults++;
        } else {
            stack<int> temp;
            while (s.top() != page) {
                temp.push(s.top());
                s.pop();
            }
            s.pop();
            while (!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
            s.push(page);
        }

        cout << "Reference: " << page << ", Page Frames: ";
        stack<int> printStack = s;
        while (!printStack.empty()) {
            cout << printStack.top() << " ";
            printStack.pop();
        }
        cout << ", Page Faults: " << pageFaults << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
}

int main() {
    vector<int> pages = {1, 3, 3, 2, 3, 0, 9, 7, 0, 1, 3, 3};
    int capacity = 3;

    lruPageReplacement(pages, capacity);

    return 0;
}
