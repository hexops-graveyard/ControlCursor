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
	#include <ApplicationServices/ApplicationServices.h>

	point getCursorPos(void) {
		CGEventRef event = CGEventCreate(nil);
		CGPoint p = CGEventGetLocation(event);
		CFRelease(event);
		return (point){p.x, p.y};
	}

	bool setCursorPos(point p){
		return CGWarpMouseCursorPosition((CGPoint){p.x, p.y});
	}

#elif __unix__ 
	#include <X11/Xlib.h>

	point getCursorPos(void){
		Window root, child;
		int rootX, rootY, winX, winY;
		unsigned int mask;

		Display* dpy = XOpenDisplay(0);
		Window root_window = XRootWindow(dpy, 0);
		XQueryPointer(dpy, root_window, &root, &child, &rootX, &rootY, &winX, &winY, &mask); 
		return (point){rootX, rootY};
	}

	bool setCursorPos(point p){
		Display* dpy = XOpenDisplay(0);
		Window root_window = XRootWindow(dpy, 0);
		XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, p.x, p.y);
		XFlush(dpy);
		return true;
	}

#else
#   error "Unknown compiler"
#endif
