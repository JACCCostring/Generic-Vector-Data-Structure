#ifndef __OWN_TYPE_VECTOR__

#define __OWN_TYPE_VECTOR__

#include <iostream>
// #include <cassert>

namespace OST_Container
{


    //iterator for vector class

    template<typename vector> class Iter{
    public:
        //definn types for iter usages
        using Type = typename vector::ValueType;
        using TypePointer = Type*;
        using TypeReference = Type&;
        
        Iter(TypePointer iter): _iter(iter) {}

        //overloading operators for iterator
        Iter& operator ++(){ _iter++; return *this; }

        Iter& operator ++(int){
            TypePointer temp = *this;
            ++(*this); 
        return temp;
        }

        Iter& operator --(){ _iter--; return *this; }
        
        Iter& operator --(int){
            TypePointer temp = *this;
            --(*this); 
            
        return temp;
        }

        bool operator !=(const Iter& rhs){ return _iter !=  rhs._iter; }

        bool operator ==(const Iter& rhs){ return _iter ==  rhs._iter; }

        // bool operator <(const Iter& rhs){ return _iter <  rhs._iter; }

        // bool operator >(const Iter& rhs){ return _iter >  rhs._iter; }

        TypeReference operator [](std::size_t index){ return *(_iter + index); }

        TypePointer operator ->(){ return _iter; }
        
        TypeReference operator *(){ return *_iter; }

    private:
        TypePointer _iter;
    };




    //vector class

    template<typename T> class vector
    {
    public:
    //defining types
    using ValueType = T;
    using Iterator = Iter<vector<T>>;


        vector(/* args */){ //default constructor
            if(data == nullptr) data = new T[_capacity];
        }

        vector(T element, std::size_t dimention){ //parametized constructor
            if(data == nullptr){
                data = new T[dimention];
                _capacity = dimention;
                for(int i = 0; i < dimention; i++) push_back(element);
            }
        }

        vector(std::initializer_list<T> paramList){
            if(paramList.size() > 0){
                data = new T[paramList.size()];
                for(const auto &p: paramList) push_back(p);
            }
            _capacity = paramList.size() * 2 / 2 + 10; //re-calculating _capacity and size
            _size = paramList.size();
        }

        vector(const vector& copy_vector){ //copy constructor
            _capacity = copy_vector.capacity();
            _size = copy_vector.size();
            data = new T[_capacity];
            for(int i = 0; i < _size; i++) data[i] = copy_vector.data[i];
        }

         vector(vector&& copy_vector){ //move constructor
            _capacity = copy_vector.capacity();
            _size = copy_vector.size();
            
            data = new T[_capacity];
            // data = copy_vector.data;

            for(int i = 0; i < _capacity; i++)  data[i] = copy_vector.data[i];

            copy_vector._size = 0;
            copy_vector._capacity = 5;

            // delete [] copy_vector.data;
            // copy_vector.data = nullptr;
        }

        vector& operator =(const vector& copy){ //copy assignment constructor 

            _capacity = copy.capacity();
            _size = copy.size();
            data = new T[_capacity];

            for(int i = 0; i < copy.size(); i++) 
                data[i] = copy.data[i];

            return *this;
        }

        void set_capacity_limit(std::size_t new_limit)
            { limit_capacity = new_limit; }

        T& operator[](std::size_t index){
            if(index <= _size) return data[index]; 

            return data[0];
        }

        T& at(std::size_t index){ if(_size > 0) return data[index]; return data[_size];}

        const std::size_t size() const { return _size; }

        const std::size_t capacity() const { return _capacity; }

        //iterator begin
        Iterator begin(){ return Iterator(data); } //iterators

        //iterator end
        Iterator end(){ return Iterator(data + _size); }
        
        T& front(){ return data[_size - 1]; }

        T& back(){ return data[0]; }

        T& pop(){
            if(_size < 0) return data[_size];
            std::size_t pop_position = _size;

            T* new_data = new T[pop_position];

            if(_size > 0){
            for(int i = 0; i < pop_position; i++)
                new_data[i] = data[i];
                
                delete [] data;
                data = new_data;
                _size = pop_position - 1;
                _capacity--;
            }

            return data[_size];
        }

        bool remove(std::size_t index){
            std::size_t new_size = _size - 1;

            T* new_relocation = new T[new_size];
            
             for(int i = 0; i < index; i++) new_relocation[i] = data[i];

            if(_size > 0 && index < _size){
                for(int i = index; i < _size; i++){
                    
                    if(i == index) _size--;

                    new_relocation[i] = data[i + 1];
                    } 

                delete [] data;

                data = new_relocation;

            return true;
            }

            return false;
        }

        friend std::ostream& operator <<(std::ostream& stream, const vector& data){
            for(int i = 0; i < data._size; i++)
                stream << data.data[i] << " ";

            return stream;
        }

        bool push_back(T new_value){
            // assert(_size < limit_capacity);
            
            if(_size == _capacity){
                resize();
        }

            data[_size] = new_value; 
            _size++;
            
            return true;
        }

        // bool operator <(const vector& rhs){
        //     if(_size > 0){
        //     for(int i = 0; i < rhs._size; i++) return data[i] < rhs.data[i];
        //     }
        // }

         ~vector(){
            if(data != nullptr){
                T zero{};
                for(int i = 0; i < _size; i++) data[i] = zero;

                 _size = 0;
                _capacity = 5;

                delete [] data;
                data = nullptr;
            }
            }


private:

        bool resize(){
            std::size_t new_capcity = (_capacity * 2 ) /  2 + (10);

            T* new_data = new T[new_capcity];

            for(int i = 0; i < _size; i++)  
                new_data[i] = data[i];
            
            delete [] data;
            data = new_data;

            _capacity = new_capcity;
            return true;
        }

    private:
        /* data */
        T* data = nullptr;

        std::size_t _size = 0;
        std::size_t _capacity = 5;
        std::size_t limit_capacity = 0;
    };
    
}

#endif