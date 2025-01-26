#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 =  r - mid;

    vector<int> left(n1), right(n2);
    for(int i=0; i<n1; i++){
        left[i] = v[l + i];
    }

    for(int i=0; i<n2; i++)
        right[i] = v[i+mid+1];
    
    int i=0, j=0, k=l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            v[k++] = left[i++];
        }else{
            v[k++] = right[j++];
        }
    }

    while(i < n1){
        v[k++] = left[i++];
    }

    while(j<n2){
        v[k++] = right[j++];
    }
}
void mergeSort(vector<int> &v, int l, int r){
    if (l >= r) return;
    int mid = (l+r)/2;
    mergeSort(v, l, mid);
    mergeSort(v, mid+1, r);

    merge(v, l, mid, r);

}
void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}   
int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    print(v);
    mergeSort(v, 0, n-1);
    print(v);
}