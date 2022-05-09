#include "List.h"

List::List() {
    head.next = &tail;
    tail.prev = &head;
    size = 0;
    std::cout << "List::List()" << std::endl;
}

List::List(int Val) {
    auto *ptr = new ListNode(Val, &tail, &head);
    head.next = ptr;
    tail.prev = ptr;
    ptr = nullptr;
    size = 1;
    std::cout << "List::List(int Val)" << std::endl;
}

List::List(const List &Lst) {
    head.next = &tail;
    tail.prev = &head;
    auto *ptr = Lst.head.next;
    while (ptr != &Lst.tail) {
        Add(ptr->data);
        ptr = ptr->next;
    }
    std::cout << "List::List(const List &Lst)" << std::endl;
}

List &List::operator=(const List &Lst) {
    if (this != &Lst) {
        Clear();
        auto *ptr = Lst.head.next;
        while (ptr != &Lst.tail) {
            Add(ptr->data);
            ptr = ptr->next;
        }
    }
    std::cout << "List &List::operator=(const List &Lst)" << std::endl;
    return *this;
}

List::List(List &&Lst) noexcept {
    head.next = Lst.head.next;
    tail.prev = Lst.tail.prev;
    Lst.head.next->prev = &head;
    Lst.tail.prev->next = &tail;
    Lst.head.next = &Lst.tail;
    Lst.tail.prev = &Lst.head;
    size = Lst.size;
    Lst.size = 0;
    std::cout << "List::List(List &&Lst)" << std::endl;
}

List &List::operator=(List &&Lst) noexcept {
    if (this != &Lst) {
        Clear();
        head.next = Lst.head.next;
        tail.prev = Lst.tail.prev;
        Lst.head.next->prev = &head;
        Lst.tail.prev->next = &tail;
        Lst.head.next = &Lst.tail;
        Lst.tail.prev = &Lst.head;
        size = Lst.size;
        Lst.size = 0;
    }
    std::cout << "List &List::operator=(List &&Lst)" << std::endl;
    return *this;
}

bool List::IsEmpty() const {
    if (!size)
        return true;
    return false;
}

void List::Add(int Val) {
    auto *ptr = new ListNode(Val, &tail, tail.prev);
    tail.prev->next = ptr;
    tail.prev = ptr;
    ptr = nullptr;
    ++size;
}

List::~List() {
    auto *ptr = tail.prev;
    while (!IsEmpty()) {
        auto *tmp = ptr->prev;
        delete ptr;
        ptr = tmp;
        tmp = nullptr;
        --size;
    }
    ptr = nullptr;
    head.next = &tail;
    tail.prev = &head;
    std::cout << "List::~List()" << std::endl;
}

void List::Clear() {
    this->~List();
}

void List::AddAfter(int Val, unsigned int Pos) {
    if (Pos > size) {
        Add(Val);
    } else {
        size_t counter = 1;
        auto *ptr = head.next;
        while (counter != Pos) {
            ++counter;
            ptr = ptr->next;
        }
        auto *ptr1 = new ListNode(Val, ptr->next, ptr);
        ptr->next->prev = ptr1;
        ptr->next = ptr1;
        ptr1 = nullptr;
        ptr = nullptr;
        ++size;
    }
}

void List::AddBefore(int Val, unsigned int Pos) {
    if (Pos > size) {
        Add(Val);
    } else if (Pos == 1) {
        auto ptr = new ListNode(Val, head.next, &head);
        head.next->prev = ptr;
        head.next = ptr;
        ptr = nullptr;
        ++size;
    } else {
        size_t counter = 1;
        auto *ptr = head.next;
        while (counter != Pos - 1) {
            ++counter;
            ptr = ptr->next;
        }
        auto *ptr1 = new ListNode(Val, ptr->next, ptr);
        ptr->next->prev = ptr1;
        ptr->next = ptr1;
        ptr1 = nullptr;
        ptr = nullptr;
        ++size;
    }
}

void List::Print() const {
    if (IsEmpty()) {
        std::cout << "List is empty" << std::endl;
    } else {
        auto *ptr = head.next;
        while (ptr != &tail) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
}

void List::PrintReverse() const {
    if (IsEmpty()) {
        std::cout << "List is empty" << std::endl;
    } else {
        auto *ptr = tail.prev;
        while (ptr != &head) {
            std::cout << ptr->data << " ";
            ptr = ptr->prev;
        }
        std::cout << std::endl;
    }
}

void List::Delete(int Val) {
    auto *ptr = head.next;
    while (ptr != &tail){
        if (ptr->data == Val){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete ptr;
            ptr = nullptr;
            --size;
            break;
        }
        ptr = ptr->next;
    }
}

void List::DeleteAllWithVal(int Val) {
    auto *ptr = head.next;
    while (ptr != &tail){
        if (ptr->data == Val){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            auto *tmp = ptr;
            ptr = ptr->next;
            delete tmp;
            tmp = nullptr;
            --size;
        }
        else {
            ptr = ptr->next;
        }
    }
}

std::ofstream &operator<<(std::ofstream &File, List &Lst) {
    if (Lst.IsEmpty()) {
        File << "List is empty" << std::endl;
    } else {
        auto *ptr = Lst.head.next;
        while (ptr != &Lst.tail) {
            File << ptr->data << " ";
            ptr = ptr->next;
        }
        File << std::endl;
    }
    return File;
}

std::ifstream &operator>>(std::ifstream &File, List &Lst){
    int num;
    while (File >> num){
        Lst.Add(num);
    }
    return File;
}








