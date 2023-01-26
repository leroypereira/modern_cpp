#pragma once

class Integer{
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& obj);
    int GetValue() const;
    void SetValue(int);
    ~Integer()
    {
        delete m_pInt;
    }
};