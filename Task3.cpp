#include <iostream>
#include <vector>
#include <utility>  
using namespace std;

template <typename T>
class Heap {
    vector<T> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < (int)heap.size() && heap[left] > heap[largest]) largest = left;
        if (right < (int)heap.size() && heap[right] > heap[largest]) largest = right;
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp((int)heap.size() - 1);
    }
    T extractMax() {
        if (heap.empty()) return T();
        T max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return max;
    }
    T extractMin() {
        if (heap.empty()) return T();
        int n = (int)heap.size();
        int minIdx = 0;
        for (int i = 1; i < n; ++i) {
            if (heap[i] < heap[minIdx]) minIdx = i;
        }
        T minValue = heap[minIdx];
        heap[minIdx] = heap.back();
        heap.pop_back();
        if (minIdx < (int)heap.size()) {
            heapifyDown(minIdx);
            heapifyUp(minIdx);
        }
        return minValue;
    }
    T getMax() {
        if (heap.empty()) return T();
        T maxValue = heap[0];
        for (int i = 1; i < (int)heap.size(); ++i) {
            if (heap[i] > maxValue) {
                maxValue = heap[i];
            }
        }
        return maxValue;
    }

    void heapSort(vector<T>& arr) {
        Heap<T> maxHeap;
        for (const T& value : arr) maxHeap.insert(value);
        for (int i = (int)arr.size() - 1; i >= 0; --i) {
            arr[i] = maxHeap.extractMax();
        }
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return (int)heap.size();
    }

    T top() const {
        if (heap.empty()) return T();
        return heap[0];
    }
};

template <class T>
class PriorityQueue {
    Heap<pair<int, T>> pq;
public:
    void Insert(int idx, T value) {
        pair<int, T> p = { idx,value };
        pq.insert(p);
    }
    T maxPriority() {
        if (pq.isEmpty()) return T();
        return pq.top().second;
    }
    T extractHighestPriority() {
        if (pq.isEmpty()) return T();
        return pq.extractMax().second;
    }

    bool isEmpty() const {
        return pq.isEmpty();
    }

    int size() const {
        return pq.size();
    }
};
int main() {

    vector<int> examples = { 8,32,6,12,1,4,60,10 };
    Heap<int> h;
    for (int v : examples) h.insert(v);

    cout << "heap -> top (max) = " << h.top() << "\n";            
    cout << "heap -> extractMax() = " << h.extractMax() << "\n"; 
    cout << "heap -> new top = " << h.top() << "\n";
    cout << "heap -> extractMin() = " << h.extractMin() << "\n"; 
    cout << "heap -> top after extractMin = " << h.top() << "\n";

    PriorityQueue<string> pq;
    pq.Insert(3, "low");
    pq.Insert(10, "high");
    pq.Insert(5, "medium");

    cout << "\nPriorityQueue maxPriority() (peek) = " << pq.maxPriority() << "\n";
    cout << "PriorityQueue extractHighestPriority() = " << pq.extractHighestPriority() << "\n";
    cout << "PriorityQueue next maxPriority() = " << pq.maxPriority() << "\n";

    vector<int> arr = { 8,32,6,12,1,4,60,10 };
    cout << "\nbefore heapSort: ";
    for (int v : arr) cout << v << " ";
    cout << "\n";
    h.heapSort(arr);

    cout << "after heapSort (ascending): ";
    for (int v : arr) cout << v << " ";
    cout << "\n";

    return 0;
}
