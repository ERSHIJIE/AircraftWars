## Cursor Cloud specific instructions

AircraftWars is a single Win32 desktop game (Visual Studio 2017, ACLLib). There is no package manager, linter, test suite, or CI. `AircraftWars/README.md` is empty. The solution file is `AircraftWars.sln`.

This VM builds it with MinGW-w64 (`x86_64-w64-mingw32-gcc` / `g++`, win32 thread model) and runs it with 64-bit Wine. `wine32` is not installed and is not required. `DISPLAY` is `:1`.

Build and run details that are easy to miss:

- `acllib.h` includes `<Windows.h>`. MinGW ships `windows.h`. This environment has a symlink `/usr/x86_64-w64-mingw32/include/Windows.h` → `windows.h`. Recreate it if a MinGW reinstall removes it.
- Compile `acllib.c` with `x86_64-w64-mingw32-gcc` as C, not with `g++`. As C++, `OleLoadPicture`'s `REFIID` is a reference and `&IID_IPicture` does not compile.
- GCC will not string-concatenate `__FUNCTION__` inside the ACLLib assert macros (MSVC does). Pass `-D__FUNCTION__='"fn"'` when compiling `acllib.c`.
- Link with `x86_64-w64-mingw32-g++ -mwindows -static-libstdc++ -static-libgcc` and `-lwinmm -lmsimg32 -lole32 -loleaut32 -luuid -lgdi32 -luser32`. Without the static C++ runtime, Wine exits because `libstdc++-6.dll` is missing.
- Start Wine with the working directory set to `AircraftWars/` so `loadImage("Default.jpg")` resolves. `initConsole()` opens a separate Wine console; `std::cout` from `Setup()` shows up there, not in the shell that launched `wine`.
- The checked-in `Actor` constructors call `this->SetRect(...)`, but `SetRect` exists only on `Rect`. That fails on MinGW and on MSVC. A local run can change those two calls to `this->rect.SetRect(0, 0, 0, 0);` without committing the edit.
- Current `Setup()` opens a 1000×800 window titled `Test`, loads `Default.jpg`, then prints `0 0` and, after `SetSpeed(5, 5)` and `MoveSelf()`, `5 5`. `putImage` is commented out, so the client area stays blank after a successful image load.
