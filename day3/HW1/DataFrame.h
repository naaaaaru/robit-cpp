#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <cstddef>
#include <iostream>

template<class T>
class DataFrame
{
protected:
    T* data_;
    int size_;
public:
    DataFrame()
    {
        data_ = nullptr;
        size_ = 0;
    }

    virtual ~DataFrame()
    {
        if(data_ != nullptr)
        {
            delete [] data_;
        }
    }

    virtual int size() = 0;
    virtual void clear() = 0;
};

template<class T>//상속받는 클래스
class jjn : public DataFrame<T>
{
protected:
    using DataFrame<T>::data_;//데이터와 사이즈 변수 가져옴
    using DataFrame<T>::size_;
    int capacity_;//배열 크기
public:
    jjn()
    {
        capacity_ = 10;//초기 배열크기 설정
        this->data_ = new T[capacity_];//메모리 할당
        //"this"객체의 주소를 가르키는 포인터, 상속받은 멤버 변수에 접근하기 위해 사용
        this->size_ = 0;
    }

    int size() override
//부모의 함수를 오버라이드(구현)
    {
        return this->size_;
    }//함수 사이즈 리턴

    void clear() override
    {
        delete[] this->data_;
        this->data_ = new T[capacity_];
        this->size_ = 0;
    }//배열안의 데이터 비우고 사이즈 0으로 반환
    void push_back(T num);
    T at(int index);
    T* begin();
    T* end();
    bool empty();
    void erase(int index);
    void insert(int index, T num);
};

#endif // DATAFRAME_H
