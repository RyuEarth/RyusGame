#ifndef INCLUDED_BACKGROUND_H
#define INCLUDED_BACKGROUND_H

class Background {
public:
	Background();
	~Background();
	void Initialize();
	void Process();
	void Draw();
	void Finalize();

private:
	int mImage[1];
	int mBackground_Y;
	int count;

};

#endif
