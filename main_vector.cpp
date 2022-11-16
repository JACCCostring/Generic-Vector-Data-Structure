#include "vector.hpp"

#include "test.hpp" //for testing

template<typename T> void testing(T &object)
{    
    //populating data
    object.push_back(55);
    object.push_back(55);

    // cases
    EQ_TEST<int>                                    (object.size(), 2,          "container size");
    EQ_TEST<int>                                    (object.capacity(), 5,      "container capacity");
    EQ_TEST<OST_Container::vector<int>::ValueType>  (object.front(), 55,        "container front");
    EQ_TEST<OST_Container::vector<int>::ValueType>  (object.at(0), object.at(1),"populating vector");
    EQ_TEST<OST_Container::vector<int>::ValueType>  (object.back(), 55,         "container back");

    //cases when re-sizing
    object.push_back(55);
    object.push_back(55);
    object.push_back(55);
    object.push_back(55); //6 elements now in vector

    EQ_TEST<int>                                    (object.size(), 6,          "container size"); 
    EQ_TEST<int>                                    (object.capacity(), 15,     "container capacity"); 
    EQ_TEST<bool>                                   (object.remove(0), true,    "item removed");
    
    object.clear(); //cleaning all items container

    EQ_TEST<int>                                    (object.size(), 0,          "container clear");
}   


int main(int argc, char **argv)
{   
    OST_Container::vector<int>                  test_vector;

    testing< OST_Container::vector<int> >       (test_vector);

    return 0;
}
