#include "script.cpp"
int main()
{
    // FAST
    cout << "\t\t\tSimplifyTranscations\n\n\n\n";
    int stop = 0, id = 0, money;
    string sender, receiver;
    unordered_map<string, int> nameToId;
    cout << "\n\t\tENTER TRANSCATIONS : PAYER_NAME RECIVER_NAME MONEY\n \n";
    vector<Transaction> transcations;
    do
    {
        cin >> sender >> receiver >> money;
        if (nameToId.count(sender) == 0)
            nameToId[sender] = id++;
        if (nameToId.count(receiver) == 0)
            nameToId[receiver] = id++;
        transcations.emplace_back(nodeToId[sender], nodeToId[receiver], money);
        cout << "ENTER 1 TO ADD MORE TRANSCATIONS";
    } while (stop != 1);

    solve(transcations);
    for (Transaction x : transcations)
    {
        cout << nameToId[x.payer] << "->" << nameToId[x.receiver] << " Rs " < < < x.money << endl;
    }
    return 0;
}