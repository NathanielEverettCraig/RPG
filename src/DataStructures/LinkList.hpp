#pragma once

template<class T>
struct Link {
    T data;
    Link* next = nullptr;
};

template<class T>
class LinkList {
public:
    void Insert(size_t _targetIndex, T _value) {
        Link<T>* link = new Link<T>();
        link->data = _value;

        Link<T>** current = &m_head;
        for (size_t i = 0; *current && i < _targetIndex; i++, current = &(*current)->next) {}

        link->next = *current;
        *current = link;
    }
private:
    Link<T>* m_head;
};