@echo off

if "%~1"=="" goto no_arg

echo Copying AGG Wrapper DLLs to '%~1'

xcopy /Y/R "%~p0release\AntiGrain.NET.dll" "%~1" 1>NUL
xcopy /Y/R "%~p0release\AntiGrain.Win32.dll" "%~1" 1>NUL

goto end

:no_arg
echo -
echo No arguments specified. You should provide the path of the target

echo directory.
echo -

:end
