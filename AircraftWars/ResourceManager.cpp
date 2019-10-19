#include "acllib.h"
#include "BasicObject.h"

void windowClear() {
	beginPaint();
	clearDevice();
	endPaint();
}