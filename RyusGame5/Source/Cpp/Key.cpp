#include "Key.h"
#include "DxLib.h"

static unsigned mKey[256];

void Key_update() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) {
			mKey[i]++;

		}
		else {
			mKey[i] = 0;
		}
	}


}
int Key_get(int KeyCode) {
	return mKey[KeyCode];//KeyCode‚Ì“ü—Íó‘Ô‚ð•Ô‚·
}
