#include "Integer.h"
#include <iostream>
Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) {
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const {
	return *m_pInt;
}

void Integer::SetValue(int value) {
	*m_pInt = value;
}

Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer& Integer::operator++() {
    ++(*m_pInt);
    return *this;
}

Integer Integer::operator++(int val)
{
    Integer temp(*this);
    ++(*m_pInt);
    return temp;
}

bool Integer::operator ==(const Integer &obj) const{
    if(*m_pInt== *obj.m_pInt)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//type conversion operator to int
Integer::operator int(){
    return *m_pInt;
}

// copy assignment operator
Integer& Integer::operator=(const Integer & a)
{
    if(this != &a) // check for self assignment a=a
    {
        delete m_pInt;
        m_pInt = new int(*a.m_pInt);
    }
    return *this;
}

//move assignment operator
Integer & Integer::operator=(Integer&& a)
{
    if(this != &a)
    {
        delete m_pInt;
        m_pInt = new int(*a.m_pInt);
        a.m_pInt = nullptr;
    }
    return *this;
}

Integer Integer::operator +(const Integer& a) const
{
    Integer temp;
    *temp.m_pInt = *m_pInt + *a.m_pInt;
    return temp;
} 

// Global overloads
Integer operator +(int x, const Integer &y)
{
    Integer temp;
    temp.SetValue(x + y.GetValue());
    return temp;
}

std::ostream& operator <<(std::ostream &out, const Integer& a)
{
    out<<a.GetValue();
    return out;
}


class IntPtr {
	Integer *m_p;
public:
	IntPtr(Integer *p) :m_p(p) {

	}
	~IntPtr() {
		delete m_p;
	}
	Integer *operator ->() {
		return m_p;
	}
	Integer & operator *() {
		return *m_p;
	}
};
void Print(std::unique_ptr<Integer> ptr)
{
    std::cout<<ptr->GetValue()<<std::endl;
}

void Print(std::shared_ptr<Integer> ptr)
{
    std::cout<<ptr->GetValue()<<std::endl;
}
void CreateInteger() {
	IntPtr p1 = new Integer; // this object behaves like a smart pointer
    p1->SetValue(3);
    std::cout<<p1->GetValue()<<std::endl;

    // unique pointer doesnt allow you to create a copy of the pointer. This is because the copy constructor of the 
    // unique pointer is deleted;
    // unique pointer has move semantics only and not copy semantics;
    std::unique_ptr<Integer> p2(new Integer);
    p2->SetValue(5);
    //auto p3(p2); // error
    // Print(p2);// error as unique pointer cannot be copied
    Print(std::move(p2)); // works as the std: move is used // however now p2 doesnt hold the resource, and shouldnt be used

    // shared_pointer allows you to share the resources between different parts of the code. It contains reference counting.
    // every time a copy of the share pointer is created, its reference pointer is incremented by 1.
    // The shared pointer will be release the underlying resource once the reference count goes to zero.
    std::shared_ptr<Integer> p4(new Integer(1));
    Print(p4);
    p4->SetValue(3);
} 
void Process(Integer val) {

}

int main() {
    using namespace std;
    Integer a1{5};
    int a2 = a1;
    // a1 = 5; // error as implicit conversions are not allowed
	// Integer a(5), b(5); 
    // Integer sum = a + b;  // operator + has been overloaded
    // a==b?cout<<"a=b"<<endl: cout<<"a!=b"<<endl;
    // cout<<(++sum).GetValue()<<endl;

    // // copy Assignment operator
    // Integer c;
    // c = a;
    // cout<<c.GetValue()<<endl;

    // //move assignement operator
    // Integer d;
    // d = 5;

    // // global overloads
    // Integer sum1 = a + 5;
    // Integer sum2 = 5 + a; //Invokes the global operator
    // cout<<sum1<<" "<<sum2<<endl;

    //Smart pointer basics
    //CreateInteger();

	return 0;
}

/**
 * Operator Overloading
 *  : As global functions, require same no. of args as the operands
 *  : As a member function only one arg has to be specified as the other arguement is implicitly passed to the function
 *  Inorder to distinguish betewent the pre and post increment, the operator overload witha  different function signature.
 *  In post increment, a temp integer is created which is then incremented and returned. Hence usuage of pre increment is more
 *  efficient that post increment.
 * 
 * Rules of operator overloading
 * -Overloaded operator functions should be non static -  except for new and delete
 * -Global overload if first operand is primitive type
 * -Not all the operators can be overloaded .* sizeof ?:(ternary)
 * -cannot define new operators
 * -overloaded for conventional behaviour only
 * 
 *  Friends functions are used to access the private members of the class;
 * 
 *  Smart pointers help to prevent memory leaks. Resource acquistion as initialization(RAII)
 *  Lifetime of a  resource is bound to local object, which is destroyed when the object is destroyed
 *  
 *  explicit keyword is used to tell the compiler not to implicity convert the primitive types to the userdefined types.
 *  Otherwise the compiler will implicility convert between primitive types and userdefined types.
*/
