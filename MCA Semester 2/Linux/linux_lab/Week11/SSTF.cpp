#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

void calculatedifference(const vector<int>& request, int head, vector<pair<int, bool>>& diff) {
    for (size_t i = 0; i < request.size(); i++) {
        diff[i] = make_pair(abs(head - request[i]), false);
    }
}

int findMIN(const vector<pair<int, bool>>& diff) {
    int index = -1;
    int minimum = INT_MAX;

    for (size_t i = 0; i < diff.size(); i++) {
        if (!diff[i].second && minimum > diff[i].first) {
            minimum = diff[i].first;
            index = i;
        }
    }
    return index;
}

void shortestSeekTimeFirst(const vector<int>& request, int head) {
    size_t n = request.size();
    if (n == 0) {
        return;
    }

    vector<pair<int, bool>> diff(n);
    int seekcount = 0;
    vector<int> seeksequence(n + 1, 0);

    for (size_t i = 0; i < n; i++) {
        seeksequence[i] = head;
        calculatedifference(request, head, diff);
        int index = findMIN(diff);
        diff[index].second = true;
        seekcount += diff[index].first;
        head = request[index];
    }
    seeksequence[n] = head;

    cout << "Total number of seek operations = " << seekcount << endl;
    cout << "Seek sequence is:" << endl;
    for (size_t i = 0; i <= n; i++) {
        cout << seeksequence[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of requests: ";
    cin >> n;

    vector<int> request(n);
    cout << "Enter the request array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> request[i];
    }

    int head;
    cout << "Enter the initial position of the head: ";
    cin >> head;

    shortestSeekTimeFirst(request, head);

    return 0;
}
