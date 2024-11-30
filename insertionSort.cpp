#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {5, 43, 10, 41, 13, 0, 39};
    int n = sizeof(a) / sizeof(a[0]);
    int key, x = 0;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        cout << endl
             << "Key: " << key << endl;

        for (int j = i; j >= 0; j--)
        {
            x++;
            cout << "step: " << x << endl;

            if (j == 0 || a[j - 1] <= key) // Prevent out-of-bounds access
            {

                a[j] = key;
                for (auto &b : a)
                {
                    cout << b << " ";
                }
                cout << endl;
                break;
            }
            else
            {
                a[j] = a[j - 1];
            }
            for (auto &b : a)
            {
                cout << b << " ";
            }
            cout << endl;
        }
    }
}