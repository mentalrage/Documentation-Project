@echo off
setlocal

set "SCRIPT=E:\NTK\GhidraBridge\source-3\project-documentation\tools\launch_idalib_mcp_nexustk.ps1"

if not exist "%SCRIPT%" (
    echo Could not find launcher script:
    echo %SCRIPT%
    pause
    exit /b 1
)

powershell -NoProfile -ExecutionPolicy Bypass -File "%SCRIPT%" -NoRestartOnLaunch
set "EXITCODE=%ERRORLEVEL%"

if not "%EXITCODE%"=="0" (
    echo.
    echo Launcher exited with code %EXITCODE%.
    pause
)

exit /b %EXITCODE%
