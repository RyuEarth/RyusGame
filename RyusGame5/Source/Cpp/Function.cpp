#include "Function.h"
#include "Vector2.h"
#include "DxLib.h"
#include "Image.h"

//二点間の角度を返す(的vec1、基点vec2)
double getAngle(const Vector2& vec1,const Vector2& vec2) {
	Vector2 *tmp_Vec = new Vector2;
	tmp_Vec->x = vec1.x - vec2.x;
	tmp_Vec->y = vec1.y - vec2.y;
	return atan2(tmp_Vec->y, tmp_Vec->x);
}
//距離を求める関数
double getDistance(const Vector2& vec1,const Vector2& vec2) {
	double d = (vec1.x - vec2.x)*(vec1.x - vec2.x) + (vec1.y - vec2.y)*(vec1.y - vec2.y);
	return sqrt(d);
}

void DrawAnimation(
	const Vector2& vec,
	const int width,
	const int flame,
	const int muki,
	const int* handle,
	const int count,
	const double exrate,
	const double angle) {
	int width_x = (count / flame) % width;
	DrawRotaGraph(vec.x, vec.y, exrate, angle, handle[muki*width + width_x], true);
}
//一瞬だけ呼び出される関数
void FlashFunction() {

}
//イベントハンドラ（一応Velocity対応版予定）
void EventHundler() {
	//vel関数をどうよぼうか？
	//思いつかん。
	//真似てみる？本を真似てみようか。コマンドパターンなるものを使ってみる。
	//よくわからん。なんだこれ
	//

}

//イベントハンドラを介して呼び出すようにしたいなー
void OneVel(Entity* entity,Vector2 velocity) {
	entity.object.velocity += velocity;
}

void MultiVel(Entity* entity, Vector2 velocity) {
	
}