#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int n;
    cin >> n ;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        v.push_back(x);
    }


    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(v[j] > v[j+1])
                swap(v[j], v[j+1]);
        }
    }

    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
}