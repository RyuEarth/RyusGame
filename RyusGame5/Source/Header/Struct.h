#ifndef INCLUDED_STRUCT_H
#define INCLUDED_STRUCT_H

typedef struct {
	int cnt, pattern, knd, x, y, sp, bltime, blknd, col, hp,
		blknd2, wait, item_n[6];
	//カウント、移動パターン、敵の種類、出現座標、スピード、弾を撃つまでの時間、
	//弾幕の種類、弾の色、敵のｈｐ、敵の弾の種類、停滞時間、アイテム六種類
}t_enemy_order;

#endif
