#include "List.h"

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    List l1;
    l1.Print();
    l1.Add(1);
    l1.Print();
    l1.AddAfter(2, 1);
    l1.Print();
    l1.AddBefore(3, 2);
    l1.Print();
    l1.Delete(2);
    l1.Print();
    List l2(4);
    l2.Add(5);
    l2.AddBefore(6,2);
    l2.AddAfter(6, 3);
    l1 = l2;
    l1.PrintReverse();
    l1.DeleteAllWithVal(6);
    l1.PrintReverse();
    l2.Clear();
    l2.Print();
    List l3(std::move(l1));
    l3.Print();
    l1 = std::move(l3);
    l1.Print();
    if (l1.IsEmpty()){
        std::cout << "l1 is empty" << std::endl;
    }
    else{
        std::cout << "l1 isn't empty" << std::endl;
    }
    List l4;
    in >> l4;
    out << l4;
    return 0;
}
