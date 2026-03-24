@echo off
setlocal

set "TARGET=%~1"

if "%TARGET%"=="" (
    echo Missing executable path.
    pause
    exit /b 1
)

if not exist "%TARGET%" (
    echo Executable not found:
    echo %TARGET%
    pause
    exit /b 1
)

start "C++ Run" cmd /k ""%TARGET%" ^& echo. ^& pause"
