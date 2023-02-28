#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <list>

template <class T>
class CircularBuffer
{
public:
    CircularBuffer(int buf_size) : max_buf_size(buf_size)
    {
        std::list<T> data;
    };

    int get_max_size()
    {
        return max_buf_size;
    };

    std::list<T> peak_all()
    {
        return data;
    };

    int size()
    {
        return data.size();
    };

    void push(T value)
    {
        if (data.size() >= max_buf_size)
        {
            data.pop_front();
        }
        data.push_back(value);
    };

    T pop()
    {
        T temp = data.back();
        data.pop_back();
        return temp;
    };

private:
    std::list<T> data;
    int max_buf_size;
};

#endif /* CIRCULAR_BUFFER_H_ */
