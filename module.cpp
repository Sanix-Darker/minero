#include <boost/python.hpp>
#include "minero.hpp"

BOOST_PYTHON_MODULE(minero)
{
    using namespace boost::python;
    def("hello", hello);
}