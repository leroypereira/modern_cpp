#include <iostream>
template<typename T, int size>
class Stack{
    T m_Buffer[size];
    int m_Top{-1};
public:
    Stack() = default;
    //copy constuctor
    // short hand notation of stack can be used because it is defined within the class
    // long hand notation of stack => Stack<T,size> should be used when it defined outside the class
    Stack(const Stack &obj);

    void Push(const T &elem){
        m_Buffer[++m_Top] = elem;
    }
    void Pop();

    const T& Top() const {
        return m_Buffer[m_Top];
    }

    bool isEmpty()
    {
        return m_Top == -1;
    }
    // factory method to create the stack
    static Stack Create(){
        return Stack<T, size>();
    }

};

template<typename T, int size>
void Stack<T,size>::Pop()
{
    m_Top--;
}

template<typename T, int size>
Stack<T,size>::Stack(const Stack &obj)
{
    m_Top = obj.m_Top;
    for(int i=0; i<=m_Top; i++)
    {
        m_Buffer[i] = obj.m_Buffer[i];
    }
}

int main()
{
    Stack<float, 10> s = Stack<float, 10>::Create();
    s.Push(3);
    s.Push(1);
    s.Push(4);
    s.Push(5);

    while(!s.isEmpty()){
        std::cout<<s.Top()<<" ";
        s.Pop();
    }
    return 0;
}