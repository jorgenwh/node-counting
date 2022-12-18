#include <inttypes.h>

#include "mapper.h"

void map_kmers_to_graph_index(
    const uint64_t *index_kmers, 
    const int *index_nodes, 
    const int *hashes_to_index, 
    const int *n_kmers, 
    const uint64_t *kmers, 
    unsigned int *node_counts, 
    const unsigned int modulo, 
    const int max_node_id, 
    const int index_size, 
    const int kmers_size, 
    const int node_counts_size)
{
  for (int i = 0; i < node_counts_size; i++)
  {
    node_counts[i] = i;
  }

  /*
  for (int i = 0; i < kmers_size; i++)
  {
    uint64_t hash = kmers[i] % modulo;
    int index = hashes_to_index[hash];
    int n_local_hits = n_kmers[hash];
    int l = index;
    for (int j = 0; j < n_local_hits; j++)
    {
      if (index_kmers[l] != kmers[i])
      {
        l++;
        continue;
      }

      int node_index = index_nodes[l];
      node_counts[node_index]++;
      l++;
    }
  }
  */
}
