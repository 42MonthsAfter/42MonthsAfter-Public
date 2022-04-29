@echo off
:START
DayZServer_x64.exe -cpuCount=2 -mod=@DeerIsle;@GameLabs; -config=serverDZ.cfg -port=2302 -noFilePatching -profiles=myprofile -scrAllowFileWrite -adminlog
timeout 10
goto START