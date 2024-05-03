@echo off

pushd %~dp0
call cl /nologo /GS- /DWIN32_WINDOWS_APP nocrt.c /link /nodefaultlib /subsystem:windows kernel32.lib 
popd
