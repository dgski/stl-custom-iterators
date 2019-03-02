#include <iterator>
#include <iostream>
#include <algorithm>

template <class T> class col_iterator;

template<class T, int N>
class Collection
{
    T data[N] = { 0 };
public:
    col_iterator<T> begin()
    {
        return col_iterator<T>(data);
    }
    col_iterator<T> end()
    {
        return col_iterator<T>(data + N);
    }
};

template <class T>
class col_iterator
{
public:
    T* data;
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = size_t;
    using pointer = T*;
    using reference = T&;

    col_iterator(){}
    col_iterator(pointer _data) : data(_data) {}

    reference operator*() { return *data; }
    bool operator!=(const col_iterator& other)
    {
        return data != other.data;
    }
    col_iterator<T>& operator++()
    {
        data += 1;
        return *this;
    }
    col_iterator<T> operator++(int)
    {
        return col_iterator<T>(data + 1);
    }
};

int main(void)
{
    Collection<int,10> test;

    std::fill(test.begin(), test.end(), 2);

    std::transform(test.begin(), test.end(), test.begin(), [](int i)
    {
        return i * i;
    });

    for(auto t : test)
        std::cout << t << std::endl;
}   