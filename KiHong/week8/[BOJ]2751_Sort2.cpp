#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;



// 	5812KH	676ms
void UsingSortOnArray(){
    int loop = 0;
    cin >> loop;

    int storage[loop];

    for (int k = 0; k < loop; k++) {
        cin >> storage[k];
    }

    sort(storage, storage + loop);

    for (int k = 0; k < loop; k++) {
        cout << storage[k] << '\n';
    }
}

// 8184KB	680ms
void UsingSortWithoutUnique(){
    int loop = 0;
    cin >> loop;

    vector<int> storage;

    for (int k = 0; k < loop; k++) {
        int num = 0;
        cin >> num;
        storage.push_back(num);
    }

    sort(storage.begin(), storage.end());

    for (vector<int>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
        cout << *iter << '\n';
    }
}

// 	8180KB	672ms
void UsingSort(){
    int n = 0;
    cin >> n;

    vector<int> storage;

    int loop = n;
    while (loop--) {
        int num = 0;
        cin >> num;
        storage.push_back(num);
    }

    sort(storage.begin(), storage.end());
    
    vector<int>::iterator endPoint = unique(storage.begin(), storage.end());

    for (vector<int>::iterator iter = storage.begin(); iter != endPoint; iter++) {
        cout << *iter << '\n';
    }
}

//	48884KB	1428ms
void UsingSet() {
    set<int> sets;
    
    int loop = 0;
    cin >> loop;
    while (loop--) {
        int num = 0;
        cin >> num;
        sets.insert(num);
    }
    
    for (set<int>::iterator iter = sets.begin(); iter != sets.end(); iter++) {
        cout << *iter << '\n';
    }
}

int main(void) {
    UsingSortOnArray();
    return 0;
}