#include <boost/python.hpp>
#include "./include/minero.h"

BOOST_PYTHON_MODULE(minero)
{
    using namespace boost::python;
    
    def("proof_of_work", proof_of_work);
}