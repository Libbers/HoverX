#include <math.h>
#include <GL/gl.h>

#include "math.h"
#include "vec3.h"

static void drawDebugLine(Vec3* va, Vec3* vb) {
  glBegin(GL_LINES);
  glVertex3f(va->x, va->y, va->z);
  glVertex3f(vb->x, vb->y, vb->z);
  glEnd();
}

static void drawDebugCircle(Vec3* center, float radius) {
  unsigned int segments = 16;
  float angle_per_segment = (M_PI * 2.0f) / segments;
  float angle = 0.0f;
  float cx;
  float cy;
  glBegin(GL_LINE_LOOP);
  for(int i = 0; i < segments; i++) {
    pointOnCircle(&cx, &cy, angle, radius);
    glVertex3f(center->x + cx, center->y + cy, center->z);
    angle += angle_per_segment;
  }
  glEnd();
}
