#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

PYBIND11_MODULE(custats_backend, m) 
{
  m.doc() = "Documentation for the nc C backend module";
}
