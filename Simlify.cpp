#include "script.cpp"

int main()
{
    // FAST
    cout << "\t\t\tSimplifyTranscations\n\n\n\n";
    int stop = 0, id = 0, Amount;
    string sender, receiver;
    unordered_map<string, int> nameToId;
    vector<string> idToName;

    cout << "\n\t\tENTER TRANSCATIONS : PAYER_NAME RECIVER_NAME MONEY\n \n";
    vector<Transaction> transcations, simplifiedTranscations;
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
        transcations.push_back(t);
        cout << "ENTER 1 TO ADD MORE TRANSCATIONS\t";
        cin >> stop;
        cout << endl;
    } while (stop == 1);

    simplifiedTranscations = solve(transcations);
    for (Transaction x : transcations)
    {
        cout << idToName[x.payer] << "->" << idToName[x.receiver] << " Rs " << x.money << endl;
    }
    return 0;
}