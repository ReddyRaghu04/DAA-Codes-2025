#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> arr[i].start >> arr[i].finish;
    }

    sort(arr, arr + n, compare);

    cout << "\nSelected activities:\n";

    int count = 1;
    cout << arr[0].start << " " << arr[0].finish << endl;
    int lastFinish = arr[0].finish;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            cout << arr[i].start << " " << arr[i].finish << endl;
            lastFinish = arr[i].finish;
            count++;
        }
    }

    cout << "\nMaximum non-overlapping activities = " << count;

    return 0;
}
