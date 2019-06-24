#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
    unsigned int m_size;
    T *arr;
public:

    class iterator {
        T *ptr;
    public:
        iterator(T *ptr) {
            this->ptr=ptr;
        }

        T& operator *() {
            return *ptr;
        }

        T *operator ->() {
            return ptr;
        }

        bool operator ==(const iterator& right) const {
            return ptr==right.ptr;
        }

        bool operator !=(const iterator& right) const {
            return ptr!=right.ptr;
        }

        iterator& operator++() {
            ptr++;
            return *this;
        }

        iterator operator++(int) {
            iterator temp=*this;
            ptr++;
            return temp;
        }
    };

    Array(int size);
    ~Array();
    int size();
    T& operator[](int index);

    iterator begin();
    iterator end();
};

template <typename T>
Array<T>::Array(int size) {
    this->m_size=size;
    this->arr=new T[size];
}

template <typename T>
Array<T>::~Array() {
    delete [] arr;
}

template <typename T>
int Array<T>::size() {
    return m_size;
}

template <typename T>
T& Array<T>::operator[](int index) {
    return arr[index];
}

template <typename T>
typename Array<T>::iterator Array<T>::begin() {
    return iterator(arr);
}

template <typename T>
typename Array<T>::iterator Array<T>::end() {
    return iterator(arr+m_size);
}


#endif // ARRAY_H
