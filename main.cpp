/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    //1
    T(float v, const char* n):
    value(v),
    name(n)
    {

    }  
    //2
    float value;
    //3
    std::string name;
};

struct Struct1                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float float1 { 0 }, float2 { 0 };
    float memberFunc(const float& updatedValue)      //12
    {
        std::cout << "U's float1 value: " << this->float1 << std::endl;
        this->float1 = updatedValue;
        std::cout << "U's float1 updated value: " << this->float1 << std::endl;
        while( std::abs(this->float2 - this->float1) > 0.001f )
        {
            /*
            write something that makes the distance between this->float2 and this->float1 get smaller
            */
            this->float2 += 0.01f;
        }
        std::cout << "U's float2 updated value: " << this->float2 << std::endl;
        return this->float2 * this->float1;
    }
};

struct Struct2
{
    static float staticFunc(U& that, const float& updatedValue )        //10
    {
        std::cout << "U's float1 value: " << that.float1 << std::endl;
        that.float1 = updatedValue;
        std::cout << "U's float1 updated value: " << that.float1 << std::endl;
        while( std::abs(that.float2 - that.float1) > 0.001f )
        {
            /*
            write something that makes the distance between that->float2 and that->float1 get smaller
            */
            that.float2 += 0.01f;
        }
        std::cout << "U's float2 updated value: " << that.float2 << std::endl;
        return that.float2 * that.float1;
    }
};
        
int main()
{
    T t1( 8, "t1" );                                             //6
    T t2( 13, "t2" );                                             //6
    
    Struct1 f;                                            //7
    auto* smaller = f.compare( t1, t2);                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U u1; 
    const float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Struct2::staticFunc( u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.memberFunc( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
