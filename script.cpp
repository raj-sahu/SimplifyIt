#include <bits/stdc++.h>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define reach(x) cout << "\n\t\t" << x << "\n\n";
#define deb(x) cout << #x << " " << x << '\n';
#define deb2(x, y) cout << #x << " --> " << x << " || " << #y << " --> " << y << '\n';
#define deb4(a, b, c, d) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << '\n';

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
    priority_queue<pair<int, int>> Credit, Debit;

    int amount = 0;

    for (int i = 0; i < n; ++i)
    {
        deb2(Balances[i], i);
        if (Balances[i] < 0)
        {

            Debit.push({-1 * Balances[i], i});
        }
        else if (Balances[i] > 0)
        {
            Credit.push({Balances[i], i});
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
        int res = 0;
        vector<Transaction> simplified;
        while (amount > 0)
        {
            int debiter = Debit.top().first, crediter = Credit.top().first, cid = Credit.top().second, did = Debit.top().second;
            Debit.pop();
            Credit.pop();
            int exchangeAmt = min(debiter, crediter);
            crediter -= exchangeAmt;
            debiter -= exchangeAmt;
            amount -= exchangeAmt;
            if (exchangeAmt == 0)
            {
                break;
            }
            Transaction t;
            t.payer = cid;
            t.receiver = did;
            t.money = exchangeAmt;
            deb4(cid, did, t.money, res);
            simplified.push_back(t);
            res++;

            if (debiter != 0)
                Debit.push({debiter, did});
            if (crediter != 0)
                Credit.push({crediter, cid});
        }

        cout << "\n\t" << transactions.size() << " Transcations Simpified to " << res << " Transcations";
        return simplified;
    }
}
