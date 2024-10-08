#include "DataFrame.h"

template<class T>
void jjn<T>::push_back(T num)//클래스 jjn의 함수
{
    if (this->size_ >= capacity_)//용량 증가가 필요하다면
    {
        int new_capacity = capacity_ +1;//1증가한 용량 변수 생성
        T* new_data = new T[new_capacity];//증가한 용량으로 새로운 배열 생성

        for (int i = 0; i < this->size_; i++)
        {
            new_data[i] = this->data_[i];//새로운 배열에 기존 데이터 이식
        }

        delete[] this->data_;//기존 배열 삭제
        this->data_ = new_data;
        capacity_ = new_capacity;//새로운 용량을 용량으로 대체
    }

    this->data_[this->size_] = num;//새로운 데이터 삽입
    this->size_++;//사이즈 증가
}

template<class T>
T jjn<T>::at(int index)
{
    if (index >= 0 && index < this->size_)//주소가 0보다 크고 사이즈보다 적다면
    {
        return this->data_[index];//주소에 있는 데이터 반환
    }
    else
    {
        return 9999;//오류 숫자 출력
    }

}

template<class T>
T* jjn<T>::begin()
{
    return this->data_;
}

template<class T>
T* jjn<T>::end()
{
    return this->data_ + this->size_;
}

template<class T>
bool jjn<T>::empty()//0또는 1을 반환하는 bool함수
{
    return this->size_ == 0;//0이라면 true,아니라면 false반환
}

template<class T>
void jjn<T>::erase(int index)
{
    if (index >= 0 && index < this->size_)
    {
        for (int i = index; i < this->size_ - 1; i++)
        {
            this->data_[i] = this->data_[i + 1];//인덱스의 값부터 다음값을 전값에 옮김,사이즈 끝까지 반복,결과적으로 인덱스 값 사라짐
        }
        this->size_--;//사이즈-1
    }
}

template<class T>
void jjn<T>::insert(int index, T num)
{
    if (index >= 0 && index <= this->size_)
    {
        if (this->size_ >= capacity_)
        {
            int new_capacity = capacity_ +1;
            T* new_data = new T[new_capacity];

            for (int i = 0; i < index; i++)
            {
                new_data[i] = this->data_[i];
            }
            new_data[index] = num;

            for (int i = index; i < this->size_; i++)
            {
                new_data[i + 1] = this->data_[i];
            }

            delete[] this->data_;
            this->data_ = new_data;
            capacity_ = new_capacity;
        }
        else
        {
            for (int i = this->size_; i > index; i--)
            {
                this->data_[i] = this->data_[i - 1];
            }
            this->data_[index] = num;
        }
        this->size_++;
    }
}
template class jjn<double>;
