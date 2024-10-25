@echo off

cd kernel 
rd .xmake /s /q
rd obj /s /q
rd build /s /q
del boot.o /f
del kernel.exe /f
cd ..