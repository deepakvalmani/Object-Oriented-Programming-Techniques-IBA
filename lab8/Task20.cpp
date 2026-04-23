#include <iostream>
#include <chrono>
using namespace std;


class memory_pool
{
private:
    struct free_block
    {
        free_block *next;
    };

    char *pool;
    free_block *free_list;
    size_t block_size;
    size_t pool_size;

public:
    memory_pool(size_t block_size, size_t numBlocks)
        : block_size(block_size), pool_size(block_size * numBlocks)
    {

        pool = new char[pool_size];
        free_list = nullptr;

       
        for (size_t i = 0; i < numBlocks; i++)
        {
            free_block *block = (free_block *)(pool + i * block_size);
            block->next = free_list;
            free_list = block;
        }
    }

    void *allocate()
    {
        if (!free_list)
        {
            throw bad_alloc();
        }

        free_block *block = free_list;
        free_list = free_list->next;
        return block;
    }

    void deallocate(void *ptr)
    {
        if (!ptr)
            return;

        free_block *block = (free_block *)ptr;
        block->next = free_list;
        free_list = block;
    }

    ~memory_pool()
    {
        delete[] pool;
    }
};


class Test
{
public:
    int x, y, z;

    Test() : x(0), y(0), z(0) {}
};

int main()
{
    const int N = 1000000;


    auto start1 = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        Test *t = new Test();
        delete t;
    }

    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1);

    cout << "new/delete time: " << duration1.count() << " ms" << endl;

    memory_pool pool(sizeof(Test), N);

    auto start2 = chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        void *mem = pool.allocate();
        Test *t = new (mem) Test();
        t->~Test();               
        pool.deallocate(mem);
    }

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    cout << "Memory Pool time: " << duration2.count() << " ms" << endl;

    return 0;
}