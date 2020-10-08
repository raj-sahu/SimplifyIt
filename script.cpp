#include <bits/stdc++.h>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
using namespace std;
struct Transaction
{
    int payer, receiver, money;
};

vector<Transaction> solve(vector<Transaction> &transactions, int n)
{
    vector<int> Balances(n, 0);
    for (auto x : transactions)
    {
        Balances[x.payer] -= x.money;
        Balances[x.receiver] += x.money;
    }
    priority_queue<int> Credit;
    priority_queue<int, vector<int>, greater<int>> Debit;

    int amount = 0;

    for (int i = 0; i < n; ++i)
    {
        if (Balances[i] < 0)
            Debit.push(-Balances[i]);
        else if (Balances[i] > 0)
        {
            Credit.push(Balances[i]);
            amount += Balances[i];
        }
    }
    if (amount == 0)
    {
        cout << "\t\tTranscations are Already Settled Up";
        return vector<Transaction>{};
    }
    else
    {
        int res;
        vector<Transaction> simplified;

        cout << "\n\t" << transactions.size() << " Transcations Simpified to " << res << " Transcations";
        return simplified;
    }
}
