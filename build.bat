@echo off
echo Compilando KeyRemap.dll...
x86_64-w64-mingw32-gcc -Wall -shared -Wl,--subsystem,windows -o KeyRemap.dll KeyRemap.c -luser32 -lkernel32
pause