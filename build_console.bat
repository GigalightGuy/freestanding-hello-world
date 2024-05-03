@echo off

pushd %~dp0
call cl /nologo /GS- /DWIN32_CONSOLE_APP nocrt.c /link /nodefaultlib /subsystem:console kernel32.lib 
popd
