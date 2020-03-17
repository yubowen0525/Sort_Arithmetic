#include <iostream>
#include "Sort.h"
using namespace std;

int main() {
    vector<int> array{5,4,3,2,1,8,2,4,6,9,7};
    vector<int> ans = bubbleSort<int>(array);
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    vector<int> ans1 = selectionSort<int>(array);
    for (int i = 0; i < ans1.size(); ++i) {
        cout<<ans1[i]<<" ";
    }
    cout<<endl;

    vector<int> ans2 = insertionSort<int>(array);
    for (int i = 0; i < ans2.size(); ++i) {
        cout<<ans2[i]<<" ";
    }
    cout<<endl;

    vector<int> ans3 = MergeSort<int>(array);
    for (int i = 0; i < ans3.size(); ++i) {
        cout<<ans3[i]<<" ";
    }
    cout<<endl;

    vector<int> ans4 = QuickSort<int>(array,0,array.size() - 1);
    for (int i = 0; i < ans4.size(); ++i) {
        cout<<ans4[i]<<" ";
    }
    cout<<endl;
    return 0;
}
