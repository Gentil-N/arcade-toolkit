#include "../../include/atk_math.h"

#define MTH_DEF_COLLISION(type, t)                                                                                                                                             \
       bool mthIsCollidedPointVsBall##t(const MthPoint##t *point, const MthBall##t *ball, type *distance)                                                                      \
       {                                                                                                                                                                       \
              type x = point->pos.x - ball->pos.x;                                                                                                                             \
              type y = point->pos.y - ball->pos.y;                                                                                                                             \
              type z = point->pos.z - ball->pos.z;                                                                                                                             \
              type d = ((type)1.0 / (type)mthRsqrtssf(x * x + y * y + z * z)) - ball->radius;                                                                                  \
              return (bool)(*distance = d > 0 ? d : 0);                                                                                                                        \
       }                                                                                                                                                                       \
       bool mthIsCollidedBallVsBall##t(const MthBall##t *ball_a, const MthBall##t *ball_b, type *distance)                                                                     \
       {                                                                                                                                                                       \
              type x = ball_a->pos.x - ball_b->pos.x;                                                                                                                          \
              type y = ball_a->pos.y - ball_b->pos.y;                                                                                                                          \
              type z = ball_a->pos.z - ball_b->pos.z;                                                                                                                          \
              type d = ((type)1.0 / (type)mthRsqrtssf(x * x + y * y + z * z)) - ball_a->radius - ball_b->radius;                                                               \
              return (bool)(*distance = d > 0 ? d : 0);                                                                                                                        \
       }                                                                                                                                                                       \
       bool mthIsCollidedBallVsAABB##t(const MthBall##t *ball, const MthAABB##t *aabb, type *distance)                                                                         \
       {                                                                                                                                                                       \
              if ((0 <= ball->pos.x - aabb->pos.x <= aabb->dim.x) && (0 <= ball->pos.y - aabb->pos.y <= aabb->dim.y) && (0 <= ball->pos.z - aabb->pos.z <= aabb->dim.z))       \
              {                                                                                                                                                                \
                     *distance = 0;                                                                                                                                            \
                     return false;                                                                                                                                             \
              }                                                                                                                                                                \
              MthPoint##t point;                                                                                                                                               \
              point.pos.x = atk_min(atk_max(ball->pos.x, aabb->pos.x), aabb->pos.x + aabb->dim.x);                                                                             \
              point.pos.y = atk_min(atk_max(ball->pos.y, aabb->pos.y), aabb->pos.y + aabb->dim.y);                                                                             \
              point.pos.z = atk_min(atk_max(ball->pos.z, aabb->pos.z), aabb->pos.z + aabb->dim.z);                                                                             \
              return mthIsCollidedPointVsBall##t(&point, ball, distance);                                                                                                      \
       }                                                                                                                                                                       \
       bool mthIsCollidedPointVsAABB##t(const MthPoint##t *point, const MthAABB##t *aabb)                                                                                      \
       {                                                                                                                                                                       \
              return (0 <= point->pos.x - aabb->pos.x <= aabb->dim.x) && (0 <= point->pos.y - aabb->pos.y <= aabb->dim.y) && (0 <= point->pos.z - aabb->pos.z <= aabb->dim.z); \
       }                                                                                                                                                                       \
       bool mthIsCollidedAABBVsAABB##t(const MthAABB##t *aabb_a, const MthAABB##t *aabb_b)                                                                                     \
       {                                                                                                                                                                       \
              return (atk_min(aabb_a->pos.x + aabb_a->dim.x, aabb_b->pos.x + aabb_b->dim.x) - atk_max(aabb_a->pos.x, aabb_b->pos.x)) >= 0 &&                                   \
                     (atk_min(aabb_a->pos.y + aabb_a->dim.y, aabb_b->pos.y + aabb_b->dim.y) - atk_max(aabb_a->pos.y, aabb_b->pos.y)) >= 0 &&                                   \
                     (atk_min(aabb_a->pos.z + aabb_a->dim.z, aabb_b->pos.z + aabb_b->dim.z) - atk_max(aabb_a->pos.z, aabb_b->pos.z)) >= 0;                                     \
       }                                                                                                                                                                       \
       type mthGetDistancePointVsAABB##t(const MthPoint##t *point, const MthAABB##t *aabb, bool *collided)                                                                     \
       {                                                                                                                                                                       \
              if (mthIsCollidedPointVsAABB##t(point, aabb))                                                                                                                    \
              {                                                                                                                                                                \
                     *collided = true;                                                                                                                                         \
                     return 0;                                                                                                                                                 \
              }                                                                                                                                                                \
              *collided = false;                                                                                                                                               \
              type x = atk_min(atk_max(point->pos.x, aabb->pos.x), aabb->pos.x + aabb->dim.x);                                                                                 \
              type y = atk_min(atk_max(point->pos.y, aabb->pos.y), aabb->pos.y + aabb->dim.y);                                                                                 \
              type z = atk_min(atk_max(point->pos.z, aabb->pos.z), aabb->pos.z + aabb->dim.z);                                                                                 \
              return ((type)1.0 / (type)mthRsqrtssf(x * x + y * y + z * z));                                                                                                   \
       }                                                                                                                                                                       \
       type mthGetDistanceAABBVsAABB##t(const MthAABB##t *aabb_a, const MthAABB##t *aabb_b, bool *collided)                                                                    \
       {                                                                                                                                                                       \
              type diff_x = atk_min(aabb_a->pos.x + aabb_a->dim.x, aabb_b->pos.x + aabb_b->dim.x) - atk_max(aabb_a->pos.x, aabb_b->pos.x);                                     \
              type diff_y = atk_min(aabb_a->pos.y + aabb_a->dim.y, aabb_b->pos.y + aabb_b->dim.y) - atk_max(aabb_a->pos.y, aabb_b->pos.y);                                     \
              type diff_z = atk_min(aabb_a->pos.z + aabb_a->dim.z, aabb_b->pos.z + aabb_b->dim.z) - atk_max(aabb_a->pos.z, aabb_b->pos.z);                                     \
              type x = 0;                                                                                                                                                      \
              type y = 0;                                                                                                                                                      \
              type z = 0;                                                                                                                                                      \
              if (diff_x >= 0)                                                                                                                                                 \
              {                                                                                                                                                                \
                     x = diff_x;                                                                                                                                               \
                     if (diff_y >= 0)                                                                                                                                          \
                     {                                                                                                                                                         \
                            y = diff_y;                                                                                                                                        \
                            if (diff_y >= 0)                                                                                                                                   \
                            {                                                                                                                                                  \
                                   z = diff_z;                                                                                                                                 \
                                   *collided = true;                                                                                                                           \
                                   return 0;                                                                                                                                   \
                            }                                                                                                                                                  \
                     }                                                                                                                                                         \
              }                                                                                                                                                                \
              *collided = false;                                                                                                                                               \
              return ((type)1.0 / (type)mthRsqrtssf(x * x + y * y + z * z));                                                                                                   \
       }

MTH_DEF_COLLISION(float, f)
MTH_DEF_COLLISION(double, d)
MTH_DEF_COLLISION(int, i)