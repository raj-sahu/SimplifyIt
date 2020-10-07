#include <bits/stdc++.h>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
using namespace std;
struct Transaction
{
    int payer, receiver, money;
    Transcation(int p, int r, int m) : payer(p), receiver(r), money(m){};
};

void solve(vector<Transaction> &transcations)
{
    for (Transaction x : transcations)
    {
        cout << x.payer << "->" << x.receiver << " Rs " < < < x.money << endl;
    }
}
