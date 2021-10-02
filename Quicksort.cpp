#include <iostream>
#include <vector>
using namespace std;


int partition(std::vector<int> &v, int l, int r)
{
    // pivot is chosen randomly
    int pivot_ind = l+1 + rand() % (r - l);
    int pivot = v[pivot_ind];

    // if we want this aproach we need to change pivot_ind -> r
    // int pivot = v[r];

    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }  
    }
    swap(v[i + 1], v[pivot_ind]);
    
    return i + 1;
}

void quicksort(std::vector<int> &v, int l, int r)
{
    if (l < r)
    {
        // split 
        int q = partition(v, l, r);
        
        // now we want recursively sort 2 parts of the array
        quicksort(v, l, q - 1);
        quicksort(v, q + 1, r);
    }


}

int main()
{
    // Some sample tests

    // vector<int> a = {2, 8, 7, 1, 3, 5, 6, 4};
    // vector<int> a = {3, 2, 0};
    vector<int> a = {1, -31231313, 0, 31, 56797982, 33, 34};

    quicksort(a, 0, a.size() - 1);
    for (auto el : a)
        cout << el << ' ';

}