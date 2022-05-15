#include "bits/stdc++.h"

template<typename T>
void PrintIdx(T &container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void PrintAt(T &container) {
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container.at(i) << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void PrintIterator(T &Container) {
    for (typename T::iterator it = Container.begin(); it != Container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T1, typename T2>
void Print (std::map<T1, T2> Map){
    std::cout << "---map-begin---\n";
    for(const auto& elem : Map) {
        std::cout << elem.first << " " << elem.second << "\n";
    }
    std::cout << "---map-end---" << std::endl;
}

int main() {
    std::cout << "std::vector" << std::endl;
    std::cout << "PrintIdx:" << std::endl;
    std::vector<int> vec = {1, 4, 3, 2, 5};
    PrintIdx(vec);
    std::sort(vec.begin(), vec.end(), std::less<>());
    PrintIdx(vec);
    std::sort(vec.begin(), vec.end(), std::greater<>());
    PrintIdx(vec);
    std::cout << "PrintAt:" << std::endl;
    std::vector<int> vec2 = {10, 40, 30, -20, 51};
    PrintAt(vec2);
    std::sort(vec2.begin(), vec2.end(), std::less<>());
    PrintAt(vec2);
    std::sort(vec2.begin(), vec2.end(), std::greater<>());
    PrintAt(vec2);
    std::cout << "PrintIterator:" << std::endl;
    std::vector<int> vec1 = {100, 400, 330, -120, -51};
    PrintIterator(vec1);
    std::sort(vec1.begin(), vec1.end(), std::less<>());
    PrintIterator(vec1);
    std::sort(vec1.begin(), vec1.end(), std::greater<>());
    PrintIterator(vec1);

    std::cout << std::endl;

    std::cout << "std::array" << std::endl;
    std::cout << "PrintIdx:" << std::endl;
    std::array<int, 5> arr = {1, 5, 3, 6, -3};
    PrintIdx(arr);
    std::sort(arr.begin(), arr.end(), std::less<>());
    PrintIdx(arr);
    std::sort(arr.begin(), arr.end(), std::greater<>());
    PrintIdx(arr);
    std::cout << "PrintAt:" << std::endl;
    std::array<int, 5> arr1 = {10, 5, 32, -16, -3};
    PrintAt(arr1);
    std::sort(arr1.begin(), arr1.end(), std::less<>());
    PrintAt(arr1);
    std::sort(arr1.begin(), arr1.end(), std::greater<>());
    PrintAt(arr1);
    std::cout << "PrintIterator:" << std::endl;
    std::array<int, 5> arr2 = {7, 52, -3, 61, -33};
    PrintIterator(arr2);
    std::sort(arr2.begin(), arr2.end(), std::less<>());
    PrintIterator(arr2);
    std::sort(arr2.begin(), arr2.end(), std::greater<>());
    PrintIterator(arr2);

    std::cout << std::endl;

    std::cout << "std::deque" << std::endl;
    std::cout << "PrintIdx:" << std::endl;
    std::deque<int> d1 = {10, -50, 31, 20, -32};
    PrintIdx(d1);
    std::sort(d1.begin(), d1.end(), std::less<>());
    PrintIdx(d1);
    std::sort(d1.begin(), d1.end(), std::greater<>());
    PrintIdx(d1);
    std::cout << "PrintAt:" << std::endl;
    std::deque<int> d2 = {444, 44, 4, 444, 4444};
    PrintAt(d2);
    std::sort(d2.begin(), d2.end(), std::less<>());
    PrintAt(d2);
    std::sort(d2.begin(), d2.end(), std::greater<>());
    PrintAt(d2);
    std::cout << "PrintIterator:" << std::endl;
    std::deque<int> d3 = {13, 66, 6, 666, -66};
    PrintIterator(d3);
    std::sort(d3.begin(), d3.end(), std::less<>());
    PrintIterator(d3);
    std::sort(d3.begin(), d3.end(), std::greater<>());
    PrintIterator(d3);

    std::cout << std::endl;

    std::cout << "std::list" << std::endl;
    std::list<int> l1 = {1, 5, -12, 55, -2, 0};
    PrintIterator(l1);
    l1.sort(std::less<>());
    PrintIterator(l1);
    l1.sort(std::greater<>());
    PrintIterator(l1);

    std::cout << std::endl;

    std::cout << "std::queue" << std::endl;
    std::queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    while (!q1.empty()) {
        std::cout << q1.front() << " ";
        q1.pop();
    }

    std::cout << "\n\n";

    std::cout << "std::stack" << std::endl;
    std::stack<int> s1;
    s1.push(12);
    s1.push(3);
    s1.push(4);
    s1.push(8);
    s1.push(32);

    while (!s1.empty()) {
        std::cout << s1.top() << " ";
        s1.pop();
    }

    std::cout << "\n\n";

    std::cout << "std::map" << std::endl;
    std::map<std::string, std::string> m1;
    Print(m1);
    m1["Hello"] = "World";
    Print(m1);
    m1["C++"] = "<3";
    Print(m1);
    m1["Smoking"] = "is bad";
    Print(m1);
    m1.insert({"Alcohol", "is bad too"});
    Print(m1);
    m1.insert({"foo", "bar"});
    Print(m1);
    m1.insert({"Hello", "You"});
    Print(m1);
    std::string res = m1["No such value"];
    std::cout << "std::string res = m1[\"No such value\"] => " << res << "(res string is empty)";
    return 0;
}
