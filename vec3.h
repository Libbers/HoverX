#ifndef __VEC3_H__
#define __VEC3_H__

#include <math.h>

typedef struct {
  float x;
  float y;
  float z;
} Vec3;

static inline void vec3_copy(Vec3* vr, const Vec3* v) {
  vr->x = v->x;
  vr->y = v->y;
  vr->z = v->z;
}

static inline void vec3_add(Vec3* vr, const Vec3* va, const Vec3* vb) {
  vr->x = va->x + vb->x;
  vr->y = va->y + vb->y;
  vr->z = va->z + vb->z;
}

static inline void vec3_subtract(Vec3* vr, const Vec3* va, const Vec3* vb) {
  vr->x = va->x - vb->x;
  vr->y = va->y - vb->y;
  vr->z = va->z - vb->z;
}

static inline void vec3_scale(Vec3* vr, const Vec3* v, float s) {
  vr->x = v->x * s;
  vr->y = v->y * s;
  vr->z = v->z * s;
}

static inline float vec3_dot(const Vec3* va, const Vec3* vb) {
  return va->x * vb->x +
         va->y * vb->y +
         va->z * vb->z;
}

static inline float vec3_length(const Vec3* v) {
  float squared_length = vec3_dot(v, v);
  return sqrtf(squared_length);
}

static inline void vec3_normalize(Vec3* vr, const Vec3* v) {
  float length = vec3_length(v);
  vec3_scale(vr, v, 1.0f / length);
}

#endif
