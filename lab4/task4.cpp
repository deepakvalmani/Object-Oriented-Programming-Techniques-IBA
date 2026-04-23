#include <iostream>
using namespace std;

class StockPrice
{

    int timestampArr[100000];
    double priceArr[100000];
    int latest_timestamp;
    int latestprice;
    int size;

public:
    StockPrice()
    {
        size = 0;
        latest_timestamp = -1;
        latestprice = -1;
    }

    void update(int timestamp, int price)
    {

        int index = find_time_stamp(timestamp);
        if (index != -1)
        {
            priceArr[index] = price;
        }
        else
        {
            timestampArr[size] = timestamp;
            priceArr[size] = price;
            size++;
        }

        if (timestamp > latest_timestamp)
        {
            latest_timestamp = timestamp;
            latestprice = price;
        }
        else if (timestamp == latest_timestamp)
        {
            latestprice = price;
        }
    }
    int find_time_stamp(int time_stamp)
    {
        for (int i = 0; i < size + 1; i++)
        {
            if (time_stamp == timestampArr[i])
            {
                return i;
            }
        }
        return -1;
    }

    double current()
    {
        if (size == 0)
        {
            cout << "Can not display current. no Data" << endl;
            return -1;
        }

        return latestprice;
    }

    double maximum()
    {
        double maxx = priceArr[0];
        if (size == 0)
        {
            cout << "No Data" << endl;
            return -1;
        }
        for (int i = 0; i < size; i++)
        {
            if (priceArr[i] > maxx)
            {
                maxx = priceArr[i];
            }
        }

        return maxx;
    }

    double minimum()
    {
        double minn = priceArr[0];
        if (size == 0)
        {
            cout << "No Data" << endl;
            return -1;
        }
        for (int i = 0; i < size; i++)
        {
            if (priceArr[i] < minn)
            {
                minn = priceArr[i];
            }
        }

        return minn;
    }

    bool Isempty()
    {
        return size == 0;
    }
};

int main()
{
    StockPrice stockPrice;

    stockPrice.update(1, 10);
    stockPrice.update(2, 5);

    cout << stockPrice.current() << endl;
    cout << stockPrice.maximum() << endl;

    stockPrice.update(1, 3);

    cout << stockPrice.maximum() << endl;

    stockPrice.update(4, 2);

    cout << stockPrice.minimum() << endl;

    return 0;
}
