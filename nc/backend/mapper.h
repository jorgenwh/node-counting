#ifndef MAPPER_H_
#define MAPPER_H_

#include <inttypes.h>

void map_kmers_to_graph_index(const uint64_t *index_kmers, const int *index_nodes, 
    const int *hashes_to_index, const int *n_kmers, const uint64_t *kmers, 
    unsigned int *node_counts, const unsigned int modulo, const int max_node_id, 
    const int index_size, const int kmers_size, const int node_counts_size);

#endif // MAPPER_H_
