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
	//�_���[�W�l�A�V���b�g�J���[

	int ini_mX, ini_mY,mX,mY, mCount;
	//�������W�A���W�A�J�E���g�A�_���[�W�l
	double mSpd, mSpd_acc;
	//�X�s�[�h�A�����x

private:


};

#endif