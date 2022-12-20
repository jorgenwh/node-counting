import time
import numpy as np

from nc_backend import experimental_func as __backend_experimental_func

def experimental_func(kmers, index):
    index_kmers = index._kmers
    index_nodes = index._nodes
    hashes_to_index = index._hashes_to_index
    n_kmers = index._n_kmers
    index_frequencies = index._frequencies
    modulo = index._modulo
    max_node_id = index.max_node_id()

    """
    assert index_kmers.dtype == np.uint64
    assert index_nodes.dtype == np.int32
    assert hashes_to_index.dtype == np.int32
    assert n_kmers.dtype == np.int32
    assert index_frequencies.dtype == np.uint16
    assert isinstance(modulo, (int, np.int32))
    assert isinstance(max_node_id, (int, np.int32))
    assert kmers.dtype == np.uint64
    """

    hashes = kmers % modulo

    node_counts = np.zeros(max_node_id+1, dtype=np.uint32)
    __backend_experimental_func(
            index_kmers, index_nodes, hashes_to_index, n_kmers, index_frequencies, 
            hashes, max_node_id, kmers, node_counts)

    return node_counts

