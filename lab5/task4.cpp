#include <iostream>
using namespace std;

class payment
{
    public:
    virtual void processPayment ()
    {
        cout << "Processing a generic payment." << endl;
    }
};

class credit_card_payment : public payment
{
    public:
    void processPayment ()
    {
        cout << "Processing payment via Credit Card." << endl;
    }
};
class pay_pal_payment : public payment
{
    public:
    void processPayment()
    {
        cout << "Processing payment via PayPal." << endl;
    }
};

class crypto_payment : public payment
{
    public:
    void processPayment()
    {
        cout << "Processing payment via Cryptocurrency." << endl;
    }
};



int main(){

    payment n_p;
    credit_card_payment cr_p;
    pay_pal_payment pp_p;
    crypto_payment c_p;
    n_p.processPayment();
    cr_p.processPayment();
    pp_p.processPayment();
    c_p.processPayment();
    

}
