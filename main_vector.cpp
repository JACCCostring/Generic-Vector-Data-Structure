#include "vector.hpp"

#include "test.hpp" //for testing

template<typename T> void testing(T &object)
{    
    //populating data
    object.push_back(55);
    object.push_back(55);

    // cases
    EQ_TEST<OST_Container::vector<int>::ValueType>  (object.at(0), object.at(1),"populating vector");
    EQ_TEST<int>                                    (object.size(), 2,          "vector size");
    EQ_TEST<int>                                    (object.capacity(), 5,      "vector capacity");
    EQ_TEST<OST_Container::vector<int>::ValueType>  (object.front(), 55,        "vector front");
    EQ_TEST<OST_Container::vector<int>::ValueType>  (object.back(), 55,         "vector back");

    //cases when re-sizing
    object.push_back(55);
    object.push_back(55);
    object.push_back(55);
    object.push_back(55); //6 elements now in vector

    EQ_TEST<int>                                    (object.size(), 6,          "vector size"); 
    EQ_TEST<int>                                    (object.capacity(), 15,     "vector capacity"); 
    EQ_TEST<bool>                                   (object.remove(0), true,    "item removed");  
}   


int main(int argc, char **argv)
{
    OST_Container::vector<int>                  vect;

    testing     < OST_Container::vector<int> >  (vect);

    return 0;
}