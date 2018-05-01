
@echo off
@set DEVCON="C:\Program Files (x86)\Windows Kits\10\Tools\x64\devcon.exe"
%DEVCON% status "HID\VID_04F3&PID_0000&Col02" >> dev-state.log
checkstate.exe
del dev-state.log