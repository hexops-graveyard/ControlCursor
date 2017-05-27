#include <stdint.h>
#include <stdbool.h>

typedef struct point{
	int32_t x;
	int32_t y;
} point;

#ifdef _WIN32
	#include <windows.h>
	point getCursorPos(void){
		POINT lpPoint;
		GetCursorPos(&lpPoint);
		return (point){lpPoint.x, lpPoint.y};
	}

	bool setCursorPos(point p){
		return SetCursorPos(p.x, p.y);
	}

#elif __APPLE__

#elif __unix__ 

#else
#   error "Unknown compiler"
#endif

