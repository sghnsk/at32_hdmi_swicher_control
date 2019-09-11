REM @echo off

cd "%~dp0"
cd ..

set python_dir=c:\Python37-32
set work_dir=%cd%
set src_dir=src

:: clean
if exist dist rd /s /q dist
if exist build rd /s /q build
for /f %%a in ('dir /b *.spec') do (
	if exist "%%a" del /q "%%a"
)

:: build 
%python_dir%\Scripts\pyinstaller.exe -F %src_dir%\hdmi_switch.py || exit /b 1
