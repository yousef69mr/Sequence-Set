#include <iostream>
//#include "LinkedList.h"
#include "SequenceSet.h"
int main() {

    SequenceSet<int ,int> set("data.txt",4,5);
    set.insertToFile(5,451);
    set.readFromFile(5);
    set.insertToFile(2,30);
    set.readFromFile(2);
    set.DeleteRecord(5);
    set.insertToFile(1,11);
    set.readFromFile(1);
    set.DisplayRecords();
    set.DisplayHeaderList();
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
