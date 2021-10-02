#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class MinHeap
{
public:
    MinHeap(vector<T> v)
    {
        for (auto el : v)
            arr.push_back(el);

        size = v.size();
        buildMinHeap();
    }

    void heapify(int i)
    {
        int lnode = leftChild(i);
        int rnode = rightChild(i);

        int min = i;

        if (lnode < size && arr[lnode] < arr[min])
            min = lnode;
 
        if (rnode < size && arr[rnode] < arr[min])
            min = rnode;
 
        if (min != i)
        {
            std::swap(arr[i], arr[min]);
            heapify(min);
        }
    }

    T pop()
    {
        T tmp = arr[0]; 
        arr.erase(arr.begin());

        if (arr.size() > 0)
        {
            arr.insert(arr.begin(), arr.back());
            arr.erase(arr.end() - 1); 
            heapify(0);     
        }  

        return tmp;
    }

    void print()
    {

        for (auto el : arr)
            cout << el << ' ';
    }


    static void heapsort(vector<T> &v)
    {
        MinHeap heap(v);
        
        for(int i = 0; i < v.size(); i++)
            v[i] = heap.pop();
        

    }

private:
    std::vector<T> arr;
    size_t size;

    int leftChild(int i)
    {
        return 2*i + 1;
    }

    int rightChild(int i)
    {
        return 2*i + 2;
    }

    void buildMinHeap()
    {
        for (int i = (arr.size()/2) - 1; i >= 0; i--)
            heapify(i);
    }
};  



int main()
{
    // Uncommend this code for tests 
    
    // vector<int> a = {9, 3, 5, 7, 4, -1, 0, -22};
    // MinHeap<int>::heapsort(a);
    // for (auto el : a)
    //     cout << el << ' ';
}