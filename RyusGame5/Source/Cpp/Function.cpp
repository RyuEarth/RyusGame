#include "Function.h"
#include "Vector2.h"
#include "DxLib.h"
#include "Image.h"

//��_�Ԃ̊p�x��Ԃ�(�Ivec1�A��_vec2)
double getAngle(const Vector2& vec1,const Vector2& vec2) {
	Vector2 *tmp_Vec = new Vector2;
	tmp_Vec->x = vec1.x - vec2.x;
	tmp_Vec->y = vec1.y - vec2.y;
	return atan2(tmp_Vec->y, tmp_Vec->x);
}
//���������߂�֐�
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
//��u�����Ăяo�����֐�
void FlashFunction() {

}
//�C�x���g�n���h���i�ꉞVelocity�Ή��ŗ\��j
void EventHundler() {
	//vel�֐����ǂ���ڂ����H
	//�v������B
	//�^���Ă݂�H�{��^���Ă݂悤���B�R�}���h�p�^�[���Ȃ���̂��g���Ă݂�B
	//�悭�킩���B�Ȃ񂾂���
	//

}

//�C�x���g�n���h������ČĂяo���悤�ɂ������ȁ[
void OneVel(Entity* entity,Vector2 velocity) {
	entity.object.velocity += velocity;
}

void MultiVel(Entity* entity, Vector2 velocity) {
	
}