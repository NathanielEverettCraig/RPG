//list link<T>* m_head

#pragma once

template<class T>

struct Link {
    T* data
    Link* next = nullptr;
};

template<class T>

class Linklist{
    public:
        void Insert(size_T _targetIndex, T_value){
            Link<T>* link = new Link();
            link->data = _value;

            Link<T>** current = &m_head;
            for (size_t i = 0; *current && i < _targetIndex; i++, current = &(*current)->next){

            }
            link->next = *current;
            *current = link;
        }

        int CountFor(){
            Link<T>* current = m_head;
            int count = 0;
            for (; current; count++)
                current = current->next;
            return count;

        }
        
        int count(){
            Link<T>* current = m_head;
            int count = 0;
            while (current){
                count++;
                current = current->next;
            }
            return count;
        }
        
        int getlinkat(i){
            
            int count = c;
            
            if (i < 0)
            {
                break;
            }
            else if (i > c)
            {
                break;
            }
            else
            {
                Link<T>* current = m_head;
                while (current){
                    if i == m_head
                    {
                        return Link<T>*;
                    }
                   else
                    {
                        current = current->next;
                    }
            }
                
            }
        }
        
    private:
        Link<T>* m_head;
};