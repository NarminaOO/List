#include<iostream>

template<typename T>
class List
{
private:
    struct Node
    {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node(const T& elem, Node* p, Node* n) : element(elem), prev(p), next(n) {} 
    };
    Node* first = nullptr;
    Node* last = nullptr;
    int elementsCount = 0;

public:
   
    List() = default;

    // copy constructor
    List(const List<T>& other) 
    {
        Node* temp = other.first;
        while (temp != nullptr)
        {
            PushBack(temp->element);
            temp = temp->next;
        }
    }

    //copy assignment operator
    List<T>& operator=(const List<T>& other)
    {
        if (this != &other)
        {
            clear();
            Node* temp = other.first;
            while (temp != nullptr)
            {
                PushBack(temp->element);
                temp = temp->next;
            }
        }
        return *this;
    }

    
    size_t Size() const
    {
        return elementsCount;
    }

    void PushBack(const T& elem)
    {
        Node* node = new Node(elem, last, nullptr);
        if (last != nullptr)
        {
            last->next = node;
        }
        else
        {
            first = node;
        }
        last = node;
        ++elementsCount;
    }

    void PushFront(const T& elem)
    {
        Node* node = new Node(elem, nullptr, first);
        if (first != nullptr)
        {
            first->prev = node;
        }
        else
        {
            last = node;
        }
        first = node;
        ++elementsCount;
    }

    void clear()
    {
        Node* current = first;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        first = nullptr;
        last = nullptr;
        elementsCount = 0;
    }

    void PopBack()
    {
        if (last != nullptr)
        {
            Node* temp = last;
            last = last->prev;
            if (last != nullptr)
            {
                last->next = nullptr;
            }
            delete temp;
            --elementsCount;
        }
    }

    void PopFront()
    {
        if (first != nullptr)
        {
            Node* temp = first;
            first = first->next;
            if (first != nullptr)
            {
                first->prev = nullptr;
            }
            delete temp;
            --elementsCount;
        }
    }

    
    ~List()
    {
        clear();
    }
};

int main()
{
    
    List<int>list;
    list.PushFront(1);
    list.PushFront(3);
    list.PushFront(5);
    list.PushFront(7);
    list.PushFront(9);
    std::cout << list.Size() << " " << "Size1" << "\n";
    list.PopFront();
    std::cout << list.Size() << " " << "Size2" << "\n";
    list.PopFront();
    list.PopFront();
    std::cout << list.Size() << " " << "Size3" << "\n";
    list.clear();
    std::cout << list.Size() << " " << "Size4" << "\n";
  return 0;
}
