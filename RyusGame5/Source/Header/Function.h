#ifndef INCLUDED_FUNCTION_H
#define INCLUDED_FUNCTION_H

class Vector2;
//��_�Ԃ̊p�x��Ԃ�(�Ivec1�A��_vec2)
double getAngle(const Vector2& vec1, const Vector2& vec2);
//��_�Ԃ̋�����Ԃ�
double getDistance(const Vector2& vec1,const Vector2& vec2);

//�A�j���[�V������`�悷��
void DrawAnimation(
	const Vector2& vec,
	const int width,
	const int flame,
	const int muki,
	const int* handle,
	const int count,
	const double exrate,
	const double angle
);

#endif
