#include<bits/stdc++.h>
using namespace std;

class MAX_Heap
{
public:
    vector<int> nodes;

    Heap()
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

    void build_from_array(vector <int> &a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n/2 - 1;

        for(int i = last_non_leaf; i >= 0; i--){
            down_heapify(i);
        }
     }
};

vector <int> heap_sort(vector<int>a)
{
    MAX_Heap h;
    h.build_from_array(a);

    vector<int> ans;

    for(int i = 0; i < a.size(); i++){
        ans.push_back(h.extract_max());
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector <int> a = {1, 2, 3, 4, 10, 9, 5, 7};

    vector<int> sorted_a = heap_sort(a);

    for(int i = 0; i < sorted_a.size(); i++){
        cout << sorted_a[i] << " ";
    }
    cout << "\n";

    return 0;
}


