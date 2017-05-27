using System;
using System.Runtime.InteropServices;

namespace ControlCursor{
	[StructLayout(LayoutKind.Sequential)]
	public struct Point{
		public int x, y;

		public override string ToString () {
			return string.Format ("[Point X:{0}, Y:{1}]", this.x, this.y);
		}
	}

	public static class Cursor {

		#if (UNITY_64 || PLATFORM_ARCH_64 || UNITY_EDITOR_64)
			[DllImport("libcursorpos_x64")]
			private static extern Point getCursorPos ();

			[DllImport("libcursorpos_x64")]
			private static extern bool setCursorPos (Point p);
		#elif (UNITY_32 || PLATFORM_ARCH_32 || UNITY_EDITOR_32)
			[DllImport("libcursorpos_x86")]
			private static extern Point getCursorPos ();

			[DllImport("libcursorpos_x86")]
			private static extern bool setCursorPos (Point p);
		#endif

		public static Point GetPosition() {
			#if (UNITY_32 || UNITY_64 || PLATFORM_ARCH_32 || PLATFORM_ARCH_64 || UNITY_EDITOR_32 || UNITY_EDITOR_64)
				return getCursorPos ();
			#else
				#error "cannot detect architecture"
			#endif
		}

		public static bool SetPosition(Point p) {
			#if (UNITY_32 || UNITY_64 || PLATFORM_ARCH_32 || PLATFORM_ARCH_64 || UNITY_EDITOR_32 || UNITY_EDITOR_64)
				return setCursorPos (p);
			#else
				#error "cannot detect architecture"
			#endif
		}
	}
}