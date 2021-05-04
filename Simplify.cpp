#include "script.cpp"

int main()
{
    // FAST
    cout << "\n\n\n\t\t\t\tSIMPLIFY TRANSCATIONS :\n\n\n\n";
    int stop = 0, id = 0, Amount;
    string sender, receiver;
    unordered_map<string, int> nameToId;
    vector<string> idToName;

    cout << "\n\t\tENTER TRANSCATIONS : PAYER_NAME RECIEVER_NAME MONEY\n \n";
    vector<Transaction> transactions, simplifiedTransactions;
    Transaction t;
    do
    {
        cin >> sender >> receiver >> Amount;
        if (nameToId.count(sender) == 0)
        {
            nameToId[sender] = id++;
            idToName.push_back(sender);
        }
        if (nameToId.count(receiver) == 0)
        {
            nameToId[receiver] = id++;
            idToName.push_back(receiver);
        }
        t.payer = nameToId[sender];
        t.receiver = nameToId[receiver];
        t.money = Amount;
        transactions.push_back(t);
        cout << "ENTER 1 TO ADD MORE TRANSCATIONS\t";
        cin >> stop;
        cout << endl;
    } while (stop == 1);

    cout << "\n\n\t\tBEFORE\n\n";
    for (Transaction x : transactions)
    {
        cout << idToName[x.payer] << "->" << idToName[x.receiver] << " Rs " << x.money << endl;
    }
    simplifiedTransactions = solve(transactions, id);

    cout << "\n\n\t\tSIMPLEST TRANSCATIONS TO SETTLE UP:\n\n";
    for (Transaction x : simplifiedTransactions)
    {
        cout << idToName[x.payer] << "->" << idToName[x.receiver] << " Rs " << x.money << "\n\n\n\n";
    }

    return 0;
}
