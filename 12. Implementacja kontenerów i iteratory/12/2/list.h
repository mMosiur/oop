#ifndef LIST_H
#define LIST_H

template <typename T>
class List {

    struct Node {
        T value;
        Node *next;
    };

    Node *head, *tail;

public:

    class iterator {
        Node *ptr;
    public:
        iterator(Node *ptr) {
            this->ptr=ptr;
        }

        T& operator *() {
            return ptr->value;
        }

        T *operator ->() {
            return &(ptr->value);
        }

        bool operator ==(const iterator& right) const {
            return ptr==right.ptr;
        }

        bool operator !=(const iterator& right) const {
            return ptr!=right.ptr;
        }

        iterator& operator++() {
            ptr = ptr -> next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp=*this;
            ptr = ptr -> next;
            return temp;
        }
    };

    List();
    ~List();
    bool empty();
    unsigned int size();

    T &front();
    T &back();

    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();
    void clear();

    iterator begin();
    iterator end();
};

template <typename T>
List<T>::List() {
    head=nullptr;
    tail=nullptr;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::clear() {
    if(empty()) return;
    Node *temp = head;
    Node *next = temp->next;
    while (true){
        delete temp;
        temp=next;
        if (!temp) break;
        next = temp->next;
    }
    head=tail=nullptr;
}


template <typename T>
bool List<T>::empty() {
    return head==nullptr;
}

template <typename T>
unsigned int List<T>::size() {
    int cnt=0;
    for(Node *temp = head; temp != nullptr; temp = temp->next) cnt++;
    return cnt;
}

template <typename T>
T &List<T>::front() {
    return head->value;
}

template <typename T>
T &List<T>::back() {
    return tail->value;
}

template <typename T>
void List<T>::push_front(const T &value) {
    Node *p = new Node{value, head};
    head = p;
    if (!tail)
        tail = head;
}

template <typename T>
void List<T>::push_back(const T &value) {
     Node *p= new Node{value, nullptr};
    if(empty()){
        head=p;
    }
    else {
        tail->next=p;
    }
    tail=p;

}

template <typename T>
void List<T>::pop_front() {
    if(empty())
        return;

    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node *temp = head;
    head = temp->next;
    delete temp;
}

template <typename T>
void List<T>::pop_back() {
    if(empty())
        return;

    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node *temp = head;
    while(temp->next!=tail) {
        temp=temp->next;
    }
    delete tail;
    temp->next=nullptr;
    tail=temp;
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(head);
}

template <typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(nullptr);
}


#endif // LIST_H
