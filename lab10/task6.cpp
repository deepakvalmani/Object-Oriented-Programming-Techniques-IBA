#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card
{
    int value;
    char suit;

    void print()
    {
        cout << "Value: " << value << " Suit: " << suit << endl;
    }
};

auto stable_selection_sort(vector<Card> &vec)
{
    for (int i = 0; i < (vec.size() - 1); i++)
    {
        int idx = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j].value < vec[idx].value)
            {
                idx = j;
            }
        }
        Card min_card = vec[idx];
        while (idx > i)
        {
            vec[idx] = vec[idx - 1];
            idx--;
        }
        vec[i] = min_card;
    }

    return vec;
}

auto selection_sort_by_val(vector<Card> &vec)
{
    for (int i = 0; i < (vec.size() - 1); i++)
    {
        int idx = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j].value < vec[idx].value)
            {
                idx = j;
            }
        }
        swap(vec[i],vec[idx]);

    }
    return vec;
}
void print_vec(vector<Card> &v)
{
    for (Card val : v)
    {
        val.print();
    }
    cout << endl;
}

int main()
{
    vector<Card> cards = {{5, 'H'}, {3, 'D'}, {5, 'D'}, {1, 'C'}};

    cout << "Normal Sorting:\n";
    auto n_sorted = selection_sort_by_val(cards);
    print_vec(n_sorted);
    cout << "Stable Sorting:\n";
    auto stable_sorted = stable_selection_sort(cards);
    print_vec(stable_sorted);
    

    return 0;
}