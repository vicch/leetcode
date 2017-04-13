// Problem:
// Given a number of envelopes with widths and heights as a pair of integers
// (w, h). One envelope can fit into another if both the width and height of
// one envelope is greater than the width and height of the other envelope.
// Calculate the maximum number of envelopes that you can Russian doll.
// 
// Example:
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 ([2,3] => [5,4] => [6,7])
// 
// Solution:
// Sort the envelopes ascendingly by width and height. Each envelope has 2
// possibilities: whether in the Russian doll or not. Calculate recursively the
// max depth either possibility can be achieved for each envelope. Cache the
// results to increase speed.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxEnvelopes(int** envelopes, int envelopesRowSize, int envelopesColSize);

int main()
{

}

int maxEnvelopesSub(int** envelopes, int count, int index, int width, int height, int* cache);
int cmpEnvelope(const void* a, const void* b);

int maxEnvelopes(int** envelopes, int envelopesRowSize, int envelopesColSize)
{
    if (envelopesRowSize == 0)
        return 0;

    int cache[envelopesRowSize];
    memset(cache, -1, sizeof(cache));

    // Sort envelopes first by width, then by height
    qsort(envelopes, envelopesRowSize, sizeof(envelopes[0]), cmpEnvelope);

    return maxEnvelopesSub(envelopes, envelopesRowSize, 0, 0, 0, cache);
}

int maxEnvelopesSub(int** envelopes, int count, int index, int width, int height, int* cache)
{
    if (index == count)
        return 0;

    int useMax, nouseMax;

    // Can use this envelope
    if (envelopes[index][0] > width && envelopes[index][1] > height) {
        // Max when using this envelope
        if (cache[index] != -1)
            useMax = cache[index];
        else {
            useMax = 1 + maxEnvelopesSub(envelopes, count, index + 1, envelopes[index][0], envelopes[index][1], cache);
            cache[index] = useMax;
        }
        nouseMax = maxEnvelopesSub(envelopes, count, index + 1, width, height, cache);
        return useMax > nouseMax ? useMax : nouseMax;

    // Cannot use this envelope
    } else
        return maxEnvelopesSub(envelopes, count, index + 1, width, height, cache);
}

int cmpEnvelope(const void* a, const void* b)
{
    if ((*(int**)a)[0] < (*(int**)b)[0])
        return -1;
    else if ((*(int**)a)[0] > (*(int**)b)[0])
        return 1;
    else 
        return ((*(int**)a)[1] - (*(int**)b)[1]);
}