#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> nodes;

    MaxHeap()
    {

    }

    // O log(n)
    void up_heapify(int idx)
    {
        while(idx > 0 && nodes[idx] > nodes[(idx - 1) / 2]){
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    // O log(n)
    void insert_heap (int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }

    void pirnt_heap()
    {
        for(int i = 0; i < nodes.size(); i++){
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }

    // O log(n)
    void down_heapify(int idx)
    {
        if(idx >= nodes.size())
            return;

        while(1){
            int largest = idx;
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;

            if(l < nodes.size() && nodes[largest] < nodes[l]){
                largest = l;
            }

            if(r < nodes.size() && nodes[largest] < nodes[r]){
                largest = r;
            }

            if(largest == idx) break;

            swap(nodes[idx] , nodes[largest]);

            idx = largest;
        }
    }

    // O log(n)
    void delete_from_heap(int idx)
    {
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();

        down_heapify(idx);
    }

    // O(1)
    int get_max()
    {
        if(nodes.empty()){
            cout << "Heap Empty\n";
            return -1;
        }
        return nodes[0];
    }

    // Returns max element and delete max O(log n)
    int extract_max()
    {
        if(nodes.empty()){
            cout << "Heap Empty\n";
            return -1;
        }

        int ret = nodes[0];
        delete_from_heap(0);
        return ret;
    }
};


class MinHeap{
public:
    MaxHeap mx;
    void insert(int x)
    {
        mx.insert_heap((-1)*x);
    }
    void Delete(int idx)
    {
        mx.delete_from_heap(idx);
    }
    int getMin()
    {
        return mx.get_max() * (-1);
    }
};



int main()
{

    MinHeap mh;

    mh.insert(5);
    mh.insert(2);
    mh.insert(15);
    mh.insert(25);
    mh.insert(35);
    mh.insert(45);

    cout << "Minimum Number: "<< mh.getMin()<<"\n";

    mh.Delete(0);

    cout << "Minimum Number after delete: "<< mh.getMin()<<"\n";

    return 0;
}

