@echo off
net session >NUL 2>nul
if %errorlevel% neq 0 (
	@powershell -Command "Start-Process cmd -ArgumentList \"/C\",'cd /D %cd%&&\"%~0\"' -Verb Runas"
	goto :EOF
)
call "make.sh"
