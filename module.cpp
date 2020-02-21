#include <boost/python.hpp>
#include "./include/minero.h"

BOOST_PYTHON_MODULE(minero)
{
    using namespace boost::python;
    def("compute_hash", compute_hash);
}