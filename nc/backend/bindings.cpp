#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

#include "mapper.h"

namespace py = pybind11;

PYBIND11_MODULE(nc_backend, m) 
{
  m.doc() = "Documentation for the nc C backend module";

  m.def("experimental_map_kmers_to_graph_index", [](const py::array_t<uint64_t> &np_index_kmers, const py::array_t<int> &np_index_nodes, const py::array_t<int> &np_hashes_to_index, const py::array_t<int> &np_n_kmers, const unsigned int modulo, const int max_node_id, const py::array_t<uint64_t> &np_kmers) {
    auto np_node_counts = py::array_t<unsigned int>({max_node_id+1});

    const int index_size = np_index_kmers.size();
    const int kmers_size = np_kmers.size();
    const int node_counts_size = np_node_counts.size();

    const uint64_t *index_kmers = np_index_kmers.data();
    const int *index_nodes = np_index_nodes.data();
    const int *hashes_to_index = np_hashes_to_index.data();
    const int *n_kmers = np_n_kmers.data();
    const uint64_t *kmers = np_kmers.data();
    unsigned int *node_counts = np_node_counts.mutable_data();

    map_kmers_to_graph_index(
        index_kmers, index_nodes, hashes_to_index, n_kmers, kmers, node_counts,
        modulo, max_node_id, index_size, kmers_size, node_counts_size);

    return node_counts;
  });
}

