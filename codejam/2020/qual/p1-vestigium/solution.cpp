#include <iostream>
#include <unordered_set>

using namespace std;

int trace(int* arr[], int len) {
    int total = 0;
    for (int i = 0; i < len; ++i) {
        total += arr[i][i];
    }
    return total;
}

int count_repeats(int* arr[], int len, int index, int rowbool) {
    unordered_set<int> el_set;

    for (int i = 0; i < len; ++i) {
        if (rowbool){
            el_set.insert(arr[index][i]);
        } else {
            el_set.insert(arr[i][index]);
        }
    }

    return (len != el_set.size());

}

int main() {
    int t, len;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> len;
        auto mat = new int*[len];
        for (int j = 0; j < len; ++j) {
            mat[j] = new int[len];

            for (int k = 0; k < len; ++k) {
                cin >> mat[j][k];
            }
        }
        int tr = trace(mat, len);
        int total_rows = 0, total_cols = 0;
        for (int j = 0; j < len; ++j) {
            total_rows += count_repeats(mat, len, j, 1); 
            total_cols += count_repeats(mat, len, j, 0);
        }   
        cout << "Case #" << i << ": " << tr << " " << total_rows << " " << total_cols << "\n"; 
    }
    return 0;
}
