#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

class List {
private:
    struct ListNode {
        int data;
        ListNode *next;
        ListNode *prev;

        explicit ListNode(int data = int(), ListNode *next = nullptr, ListNode *prev = nullptr) : data(data),
                                                                                                  next(next),
                                                                                                  prev(prev) {}
    };

    ListNode head;
    ListNode tail;
    size_t size = 0;
public:
    List();

    explicit List(int Val);

    List(const List &Lst);

    List(List &&Lst) noexcept;

    ~List();

    List &operator=(const List &Lst);

    List &operator=(List &&Lst) noexcept;

    void Add(int Val);

    void AddAfter(int Val, unsigned int Pos);

    void AddBefore(int Val, unsigned int Pos);

    void Print() const;

    void PrintReverse() const;

    void Delete(int Val);

    void DeleteAllWithVal(int Val);

    void Clear();

    bool IsEmpty() const;

    friend std::ofstream &operator<<(std::ofstream &File, List &Lst);
};

std::ifstream &operator>>(std::ifstream &File, List &Lst);

#endif
