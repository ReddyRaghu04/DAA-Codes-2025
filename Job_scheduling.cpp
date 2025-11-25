#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int deadline;
    int profit;
};

int main() {
    int size;
    cout << "Enter jobs count: ";
    cin >> size;

    Job jobs[size];
    int maxDeadline = 0;

    // Taking input
    for (int i = 0; i < size; i++) {
        cout << "Enter job " << i + 1 << " deadline: ";
        cin >> jobs[i].deadline;

        cout << "Enter job " << i + 1 << " profit: ";
        cin >> jobs[i].profit;

        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Sort jobs by profit descending
    sort(jobs, jobs + size, [](Job &a, Job &b) {
        return a.profit > b.profit;
    });

    cout << "\nSorted Jobs (profit(deadline)):\n";
    for (int i = 0; i < size; i++) {
        cout << jobs[i].profit << "(" << jobs[i].deadline << ")\n";
    }

    // Create slot array and job assignment
    int slots[maxDeadline];
    Job selectedJobs[maxDeadline];

    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = 0;   // free slot
        selectedJobs[i] = {0, 0}; // initialize to avoid garbage
    }

    int totalProfit = 0;

    // Job scheduling
    for (int i = 0; i < size; i++) {
        int d = jobs[i].deadline;

        for (int j = d - 1; j >= 0; j--) {
            if (slots[j] == 0) { // empty slot
                slots[j] = 1;
                selectedJobs[j] = jobs[i];
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output
    cout << "\n\nSelected Jobs:\n";
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] == 1) {
            cout << selectedJobs[i].profit << "(" 
                 << selectedJobs[i].deadline << ")\n";
        }
    }

    cout << "Total Profit: " << totalProfit << endl;

    return 0;
}
