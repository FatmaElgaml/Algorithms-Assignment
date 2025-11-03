#include <iostream>
#include <vector>

using namespace std;

int sequential_search(vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int recr_sequential_search(vector<int>& arr, int target, int n) {
    if (n < 0) {
        return -1;
    }
    if (arr[n] == target) {
        return n;
    }
    return recr_sequential_search(arr, target, n - 1);
}

int binary_search(vector<int>& arr, int target) {
    int l = 0;
    int r = (int)arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) {
            return m;
        }
        else if (arr[m] > target) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

int recr_binary_search(vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return -1;
    }
    int m = low + (high - low) / 2;
    if (arr[m] == target) {
        return m;
    }
    else if (arr[m] > target) {
        return recr_binary_search(arr, target, low, m - 1);
    }
    else {
        return recr_binary_search(arr, target, m + 1, high);
    }
}

int main()
{
    vector<int> rand = { 8, 32, 6, 12, 1, 4, 60, 10 };
    vector<int> sorted = { 1, 5, 9, 12, 20, 27, 32 };

    int seqres = sequential_search(rand, 12);
    int seqres_2 = sequential_search(rand, 2);

    int recrs_seqres = recr_sequential_search(rand, 12, rand.size() - 1);
    int recrs_seqres_2 = recr_sequential_search(rand, 2, rand.size() - 1);

    int binres = binary_search(sorted, 12);
    int binres_2 = binary_search(sorted, 2);

    int recr_binres = recr_binary_search(sorted, 12, 0, sorted.size() - 1);
    int recr_binres_2 = recr_binary_search(sorted, 2, 0, sorted.size() - 1);

    cout << "sequential search: 12 was found at pos " << seqres << "\n";
    cout << "sequential search: 2 was found at pos " << seqres_2 << "\n\n";

    cout << "recursive sequential (12): " << recrs_seqres << "\n";
    cout << "recursive sequential (2): " << recrs_seqres_2 << "\n\n";

    cout << "iterative binary (12): " << binres << "\n";
    cout << "iterative binary (2): " << binres_2 << "\n\n";

    cout << "recursive binary (12): " << recr_binres << "\n";
    cout << "recursive binary (2): " << recr_binres_2 << "\n";

    return 0;
}
