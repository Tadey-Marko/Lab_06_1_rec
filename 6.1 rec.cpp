#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Generate integer elements in inclusive interval [low, high].
void fillArray(int a[], int n, int low, int high, int i = 0) {
    if (i == n) return;
    a[i] = low + rand() % (high - low + 1);
    fillArray(a, n, low, high, i + 1);
}
// Print all elements in a single formatted row.
void printArray(const int a[], int n, int i = 0) {
    if (i == n) { cout << '\n'; return; }
    cout << setw(5) << a[i];
    printArray(a, n, i + 1);
}
bool selected(int value) { return value < 0 || value % 2 != 0; }
int countSelected(const int a[], int n, int i = 0) {
    if (i == n) return 0;
    return (selected(a[i]) ? 1 : 0) + countSelected(a, n, i + 1);
}
long long sumSelected(const int a[], int n, int i = 0) {
    if (i == n) return 0;
    return (selected(a[i]) ? a[i] : 0) + sumSelected(a, n, i + 1);
}
void replaceSelected(int a[], int n, int i = 0) {
    if (i == n) return;
    if (selected(a[i])) a[i] = 0;
    replaceSelected(a, n, i + 1);
}
#ifndef UNIT_TEST
int main() {
    const int n = 24;
    int a[n];
    srand(3); // Repeatable random example.
    fillArray(a, n, -50, 15);
    cout << "Initial array:   ";
    printArray(a, n);
    cout << "Count: " << countSelected(a, n) << '\n';
    cout << "Sum:   " << sumSelected(a, n) << '\n';
    replaceSelected(a, n);
    cout << "Modified array:  ";
    printArray(a, n);
    return 0;
}
#endif
