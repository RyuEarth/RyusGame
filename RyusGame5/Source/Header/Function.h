#ifndef INCLUDED_FUNCTION_H
#define INCLUDED_FUNCTION_H

class Vector2;
//二点間の角度を返す(的vec1、基点vec2)
double getAngle(const Vector2& vec1, const Vector2& vec2);
//二点間の距離を返す
double getDistance(const Vector2& vec1,const Vector2& vec2);

//アニメーションを描画する
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
