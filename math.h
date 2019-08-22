#include <math.h>

static inline void pointOnCircle(float* x, float* y, float angle, float radius) {
  if (x) {
    *x = sinf(angle) * radius;
  }
  if (y) {
    *y = cosf(angle) * radius;
  }
}
