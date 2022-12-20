#ifndef MAPPER_H_
#define MAPPER_H_

#include <inttypes.h>
#include <immintrin.h>

void experimental_map(
    const uint64_t *index_kmers, 
    const int *index_nodes, 
    const int *hashes_to_index, 
    const int *n_kmers, 
    const uint16_t *index_frequencies, 
    const uint64_t *kmers, 
    uint32_t *node_counts, 
    //const int modulo, 
    const uint64_t *hashes,
    const int max_node_id, 
    const int num_nodes, 
    const int num_kmers);

#endif // MAPPER_H_
