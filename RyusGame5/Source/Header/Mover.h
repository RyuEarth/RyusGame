#ifndef INCLUDED_MOVER_H
#define INCLUDED_MOVER_H

class Mover {
public:
	Mover() {};
	~Mover() {};

	virtual void Initialize()=0;
	virtual void Process() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() = 0;


protected:

	int mDamage, mCol;
	//ダメージ値、ショットカラー

	int ini_mX, ini_mY,mX,mY, mCount;
	//初期座標、座標、カウント、ダメージ値
	double mSpd, mSpd_acc;
	//スピード、加速度

private:


};

#endif