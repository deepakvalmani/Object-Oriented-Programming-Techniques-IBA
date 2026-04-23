#include <iostream>
#include <stdexcept>

template <typename T, typename PriorityFunc = std::less<T>>
class priority_queue
{
private:
    T *heap;
    int capacity;
    int size;
    PriorityFunc comp;

    void resize()
    {
        int newCap = capacity * 2;
        T *newHeap = new T[newCap];
        for (int i = 0; i < size; ++i)
        {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
        capacity = newCap;
    }

    void heapifyUp(int idx)
    {
        while (idx > 0)
        {
            int parent = (idx - 1) / 2;
            if (comp(heap[parent], heap[idx]))
                break;
            std::swap(heap[parent], heap[idx]);
            idx = parent;
        }
    }

    void heapifyDown(int idx)
    {
        while (2 * idx + 1 < size)
        {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int target = left;

            if (right < size && !comp(heap[left], heap[right]))
                target = right;

            if (comp(heap[idx], heap[target]))
                break;

            std::swap(heap[idx], heap[target]);
            idx = target;
        }
    }

public:
    priority_queue(int cap = 10) : capacity(cap), size(0)
    {
        heap = new T[capacity];
    }

    ~priority_queue()
    {
        delete[] heap;
    }

    void insert(const T &element)
    {
        if (size == capacity)
        {
            resize();
        }
        heap[size] = element;
        heapifyUp(size);
        ++size;
    }

    T get_highest_priority()
    {
        if (size == 0)
        {
            throw std::runtime_error("priority_queue is empty");
        }
        T top = heap[0];
        heap[0] = heap[size - 1];
        --size;
        heapifyDown(0);
        return top;
    }

    bool empty() const
    {
        return size == 0;
    }
};

struct custom_priority
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

int main()
{

    priority_queue<int> pq1;
    pq1.insert(10);
    pq1.insert(5);
    pq1.insert(20);

    std::cout << "Max heap priority queue:\n";
    while (!pq1.empty())
    {
        std::cout << pq1.get_highest_priority() << " ";
    }
    std::cout << "\n";

    priority_queue<int, custom_priority> pq2;
    pq2.insert(10);
    pq2.insert(5);
    pq2.insert(20);

    std::cout << "Min heap priority queue:\n";
    while (!pq2.empty())
    {
        std::cout << pq2.get_highest_priority() << " ";
    }
    std::cout << "\n";

    return 0;
}