#include <iostream>
#include <inttypes.h>
#include <string.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

#include "mapper.h"

namespace py = pybind11;

void experimental_func_binder(
        const py::array_t<uint64_t> &np_index_kmers, 
        const py::array_t<int> &np_index_nodes, 
        const py::array_t<int> &np_hashes_to_index, 
        const py::array_t<int> &np_n_kmers, 
        const py::array_t<uint16_t> &np_index_frequencies,
        //const int modulo,
        const py::array_t<uint64_t> &np_hashes,
        const int max_node_id,
        const py::array_t<uint64_t> &np_kmers,
        py::array_t<uint32_t> &np_node_counts)
{
  const uint64_t *index_kmers = np_index_kmers.data();
  const int *index_nodes = np_index_nodes.data();
  const int *hashes_to_index = np_hashes_to_index.data();
  const int *n_kmers = np_n_kmers.data();
  const uint16_t *index_frequencies = np_index_frequencies.data();
  const uint64_t *kmers = np_kmers.data();
  uint32_t *node_counts = np_node_counts.mutable_data();

  const int num_nodes = np_index_nodes.size();
  const int num_kmers = np_kmers.size();

  const uint64_t *hashes = np_hashes.data();

  experimental_map(
      index_kmers, index_nodes, hashes_to_index, n_kmers, index_frequencies, 
      kmers, node_counts, hashes, max_node_id, num_nodes, num_kmers);
}

PYBIND11_MODULE(nc_backend, m) 
{
  m.doc() = "Documentation for the nc C backend module";

  m.def("experimental_func", &experimental_func_binder);
}

