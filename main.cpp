#include <string>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/chrono.hpp>
#include <cmath>
#include "foo.h"
#include "sharedlib.h"

using namespace std;

int main(int argc, const char** argv)
{
    int i=5;
    i++;
    cout<<"Hello World "<< i<<endl;
    i=88;
    i++;
    
    std::string hello( "Hello, from boost!" );
    BOOST_FOREACH( char ch, hello )
    {
        std::cout << ch;
    }
    cout<<endl;
    
    foo(); 
    
    cout <<"Sum from shared lib = "<< sumint(3, 8) <<endl;

    boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
    for ( long i = 0; i < 10000000; ++i )
    std::sqrt( 123.456L ); // burn some time
    boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
    std::cout << "took " << sec.count() << " seconds\n";

        if (argc>1)
        {
        string tmp =argv[1];
        if (tmp=="0")return 0;
        else if (tmp=="1") return 1;
        }


    return 0;
}