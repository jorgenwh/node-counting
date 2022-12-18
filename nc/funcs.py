import time
import numpy as np

from nc_backend import experimental_map_kmers_to_graph_index as __backend_experimental_map_kmers_to_graph_index

def experimental_map_kmers_to_graph_index(kmers, index):
    index_kmers = index._kmers
    index_nodes = index._nodes
    hashes_to_index = index._hashes_to_index    
    n_kmers = index._n_kmers
    max_node_id = index.max_node_id()
    modulo = index._modulo

    assert kmers.dtype == np.uint64
    assert index_kmers.dtype == np.uint64
    assert index_nodes.dtype == np.int32
    assert hashes_to_index.dtype == np.int32
    assert n_kmers.dtype == np.int32
    assert isinstance(modulo, (int, np.int32, np.uint32))

    return __backend_experimental_map_kmers_to_graph_index(
        index_kmers, index_nodes, hashes_to_index, n_kmers, modulo, max_node_id, kmers)

