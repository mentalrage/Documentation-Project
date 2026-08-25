@echo off
setlocal

set "SCRIPT_DIR=%~dp0"
set "VALIDATOR=%SCRIPT_DIR%validator.py"

if not exist "%VALIDATOR%" (
    echo Could not find validator.py:
    echo %VALIDATOR%
    pause
    exit /b 1
)

echo Running full validator scan from:
echo %SCRIPT_DIR%
echo.
echo Command:
echo python "%VALIDATOR%" --queue-timeout -1 --mode full --lock-timeout -1 %*
echo.

python "%VALIDATOR%" --queue-timeout -1 --mode full --lock-timeout -1 %*
set "EXITCODE=%ERRORLEVEL%"

echo.
if "%EXITCODE%"=="0" (
    echo Validator full scan completed successfully.
) else (
    echo Validator full scan exited with code %EXITCODE%.
)
echo.
echo Tip: pass --apply to apply validator changes, for example:
echo %~nx0 --apply
echo.
pause
exit /b %EXITCODE%
