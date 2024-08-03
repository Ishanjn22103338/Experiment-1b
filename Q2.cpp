#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    
    int a[n][n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "Enter the element: ";
            cin >> a[i][j];
        }
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            a[i][j] += a[j][i];
            a[j][i] = a[i][j] - a[j][i];
            a[i][j] -= a[j][i];
        }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
