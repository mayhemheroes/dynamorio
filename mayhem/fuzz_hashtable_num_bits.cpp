#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" uint hashtable_num_bits(uint size);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    uint sz = provider.ConsumeIntegral<uint>();
    hashtable_num_bits(sz);

    return 0;
}
