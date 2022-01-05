#include <iostream>
using namespace std;

#include "SequenceSet.h"
int main() {

    SequenceSet<int ,int> set("data.txt",4,5);

    set.InsertVal(1,1);
    set.InsertVal(2,2);
    set.InsertVal(3,3);
    set.InsertVal(4,4);
    set.InsertVal(5,5);
    set.InsertVal(6,6);
    set.InsertVal(8,8);
    set.InsertVal(8,7);

    set.DisplayAllBlockRecords();
    set.writeSetToFile();
    set.DeleteKey(6);
    set.DeleteKey(4);
    set.DisplayAllBlockRecords();

    cout<<"Done";





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
