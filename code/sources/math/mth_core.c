#include "../../include/math.h"

#include <xmmintrin.h>

float mthRsqrtssf(float val)
{
       float result;
       _mm_store_ss(&result, _mm_rsqrt_ss(_mm_load_ss(&val)));
       return result;
}