#include <iostream>
using namespace std;

#include "SequenceSet.h"
int main() {

    SequenceSet<int ,int> set("data.txt",4,5);
    int key,value,blockNumber,recordNumber,result;
    bool isRunning=true;

    /*
    set.InsertVal(1,1);
    set.InsertVal(2,2);
    set.InsertVal(3,3);
    set.InsertVal(4,4);


    set.InsertVal(5,5);
    set.InsertVal(6,6);
    set.InsertVal(8,8);
     set.InsertVal(9,9);

     */
    while(isRunning) {
        cout<<"//**********************//\n";
        cout<< "Main Menu:\n1)insert record\n2)delete record\n3)get specific record key value\n4)get specific record value\n5)First Empty Block\n6)Display Specific Block Records\n7)Display All Records\n8)get Block index containing key\n9)get Record index containing key \n10)Exit\n";
        cout<<"//**********************//\n";
        int input;
        cout<<"Enter choice : ";
        cin >> input;
        switch (input) {
            case (1):

                cout << "Enter Key : ";
                cin >> key;
                cout << "Enter Value : ";
                cin >> value;
                set.InsertVal(value, key);
                set.writeSetToFile();
                break;
            case (2):
                cout << "Enter Key : ";
                cin >> key;
                set.DeleteKey(key);
                break;
            case (3):
                cout << "Enter Block Number : ";
                cin >> blockNumber;
                cout << "Enter Value : ";
                cin >> recordNumber;
                result = set.getKey(blockNumber, recordNumber);
                if (result != -1) {
                    cout << "Key Found :" + to_string(result)<<endl;
                } else {
                    cout << "Key not Found :(\n";
                }

                break;
            case (4):
                cout << "Enter Block Number : ";
                cin >> blockNumber;
                cout << "Enter Value : ";
                cin >> recordNumber;
                result = set.getVal(blockNumber, recordNumber);
                if (result != -1) {
                    cout << "Key Found :" + to_string(result)<<endl;
                } else {
                    cout << "Key not Found :(\n";
                }

                break;
            case (5):
                result = set.FirstEmptyBlock();
                if (result != -1) {
                    cout << "Block Found :" + to_string(result)<<endl;
                } else {
                    cout << "There is no empty Block\n";
                }
                break;
            case (6):
                cout << "Enter Block Number : ";
                cin >> blockNumber;
                set.DisplayBlockRecords(blockNumber);
                break;
            case (7):
                set.DisplayAllBlockRecords();
                break;
            case (8):
                cout <<"Enter Key : ";
                cin >> key;
                result = set.GetBlockIndex(key);
                if (result != -1) {
                    cout << "Block Index :" + to_string(result)<<endl;
                } else {
                    cout << "Key not found\n";
                }
                break;
            case (9):
                cout << "Enter Key : ";
                cin >> key;
                result = set.GetRecordIndex(key);
                if (result != -1) {
                    cout << "Record Index :" + to_string(result)<<endl;
                } else {
                    cout << "Key not found\n";
                }
                break;
            case (10):
                isRunning=false;
                break;
        }

        return 0;

}

    /*
    LinkedList<int,int> link;
    //L.ReadListInt();
    //LinkedList<int> link(5, 2);

    link.insertFirst(5,10);
    link.insertLast(7,7);
    link.insertLast(8,8);
    cout << link.size() << endl;
    link.printList();
    //link.insert(2,2, 2);
    link.printList();
    link.remove(2);
    link.insertFirst(4,4);
    link.printList();
    link.removeFirst();
    link.printList();
    link.removeLast();
    link.printList();
    link.remove(7);
    link.printList();
    cout << link.search(5) << endl;
    cout << link.search(7);
    cout << "\n\n\n\n";
    link.reversePrintList();
     */


    return 0;
}
