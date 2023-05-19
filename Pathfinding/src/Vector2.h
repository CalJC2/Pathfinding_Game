//
// Created by cj2-cornelius on 19/05/2023.
//

#ifndef WHACKAMOLESFML_VECTOR2_H
#define WHACKAMOLESFML_VECTOR2_H

struct Vector2
{
  // construction
  Vector2(float x_, float y_);
  Vector2(const Vector2& rhs);

  // operations
  Vector2 operator*(float scalar);
  Vector2& operator=(const Vector2& rhs);
  void normalise();

  // data
  float x = 0;
  float y = 0;
};

#endif // WHACKAMOLESFML_VECTOR2_H
