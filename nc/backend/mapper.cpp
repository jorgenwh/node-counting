#include <inttypes.h>
#include <immintrin.h>

#include "mapper.h"

/*__m256i _mm256_modulo(__m256i dividend, __m256i divisor)
{
  __m256i quotient, remainder;
  quotient = _mm256_div_epu64(dividend, divisor);
  remainder = _mm256_extract_epi64(quotient, 1);
  quotient = _mm256_mul_epu64(quotient, divisor);
  return _mm256_sub_epi64(dividend, quotient);
}*/

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
    const int num_kmers)
{
  /*const uint64_t _modulo = uint64_t(modulo);
  
  uint64_t *hashes = new uint64_t[num_kmers];
  __m256i modulo_vec = _mm256_set1_epi64x(_modulo);

  for (int i = 0; i < num_kmers; i+=8)
  {
    __m256i kmer_vec = _mm256_load_si256((__m256i*)&kmers[i]);
    //__m256i res_vec = _mm256_mod_epu64(kmer_vec, modulo_vec);
    __m256i res_vec = _mm256_modulo(kmer_vec, modulo_vec);
    _mm256_store_si256((__m256i*)&hashes[i], res_vec);
  }

  int remainder = num_kmers % 8;
  if (remainder)
  {
    for (int i = num_kmers - remainder; i < num_kmers; i++)
    {
      hashes[i] = kmers[i] % _modulo;
    }
  }*/

  for (int i = 0; i < num_kmers; i++)
  {
    //uint64_t h = kmers[i] % modulo_;
    uint64_t h = hashes[i];
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

  //delete[] hashes;
}
