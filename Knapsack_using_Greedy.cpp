#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int wt;
    int val;
    double ratio;
};

int main() {
    int size;
    cout << "Enter total items: ";
    cin >> size;

    item items[size];

    cout << "\nEnter item details:\n";
    for (int i = 0; i < size; i++) {
        cout << "Item[" << i << "] weight: ";
        cin >> items[i].wt;
        cout << "Item[" << i << "] value: ";
        cin >> items[i].val;

        items[i].ratio = (double)items[i].val / items[i].wt; // FIXED
    }

    // sort in descending order of value/weight ratio
    sort(items, items + size, [](const item &a, const item &b) {
        return a.ratio > b.ratio;
    });

    int capacity;
    cout << "\nEnter total capacity: ";
    cin >> capacity;

    int current_weight = 0;
    int total_value = 0;

    item selected_items[size];
    int sIndex = 0;

    cout << "\nSelected FULL items:\n";

    for (int i = 0; i < size; i++) {
        if (current_weight + items[i].wt <= capacity) {
            selected_items[sIndex++] = items[i];
            current_weight += items[i].wt;
            total_value += items[i].val;

            cout << "Picked item wt=" << items[i].wt 
                 << " val=" << items[i].val 
                 << " ratio=" << items[i].ratio << endl;
        }
    }

    cout << "\nTotal value = " << total_value << endl;
    cout << "Total weight used = " << current_weight << endl;

    return 0;
}
