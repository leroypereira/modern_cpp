#include <iostream>
class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer()
    {
        std::cout<<"Integer()"<<std::endl;
        m_pInt = new int(0);
    }

	//Parameterized constructor
	Integer(int value)
    {
        std::cout<<"Integer(int)"<<std::endl;
        m_pInt = new int(value);
    }

	//Copy constructor
	Integer(const Integer &obj)
    {
        std::cout<<"Integer(const Integer &)"<<std::endl;
        m_pInt = new int(*obj.m_pInt);
    }

	//Move constructor
	Integer(Integer &&obj)
    {
        std::cout<<"Integer(Integer &&)"<<std::endl;
        m_pInt = obj.m_pInt;
	    obj.m_pInt = nullptr;
    }

    // copy assignment operator
    Integer& operator=(const Integer & a) &
    {
        std::cout<<"Integer& operator=(const Integer &)"<<std::endl;
        if(this != &a) // check for self assignment a=a
        {
            delete m_pInt;
            m_pInt = new int(*a.m_pInt);
        }
        return *this;
    }

    //move assignment operator
    Integer & operator=(Integer&& a)
    {
        std::cout<<"Integer& operator=(Integer &&)"<<std::endl;
        if(this != &a)
        {
            delete m_pInt;
            m_pInt = new int(*a.m_pInt);
            a.m_pInt = nullptr;
        }
        return *this;
    }

	int GetValue()const
    {
        return *m_pInt;
    }

	void SetValue(int value)
    {
        *m_pInt = value;
    }

	~Integer()
    {
        delete m_pInt;
    }
	// Integer & operator ++();
	// Integer operator ++(int);
	// bool operator ==(const Integer &a)const;
    
	// Integer operator +(const Integer & a)const;

	// void operator ()();

    // operator int();
};