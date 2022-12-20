#include <inttypes.h>

#include "mapper.h"

void experimental_map(
    const uint64_t *index_kmers, 
    const int *index_nodes, 
    const int *hashes_to_index, 
    const int *n_kmers, 
    const uint16_t *index_frequencies, 
    const uint64_t *kmers, 
    uint32_t *node_counts, 
    const int modulo, 
    const int max_node_id, 
    const int num_nodes, 
    const int num_kmers)
{
  const uint64_t modulo_ = uint64_t(modulo);
  
  for (int i = 0; i < num_kmers; i++)
  {
    uint64_t h = kmers[i] % modulo_;
    int num_local_hits = n_kmers[h];
    int index_position = hashes_to_index[h];
    int l = index_position;

    for (int j = 0; j < num_local_hits; j++)
    {
      if (index_kmers[l] != kmers[i])
      {
        l += 1;
        continue;
      }

      if (index_frequencies[l] > 1000)
      {
        l += 1;
        continue;
      }

      node_counts[index_nodes[l]] += 1;
      l += 1;
    }
  }
}
