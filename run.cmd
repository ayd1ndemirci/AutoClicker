@echo off
set EXEFILE=AutoClicker.exe
set SOURCEFILES=src\code\Main.cpp src\code\AutoClicker.cpp

if not exist %EXEFILE% (
    echo AutoClicker program is being compiled...
    g++ -o %EXEFILE% %SOURCEFILES%
    if %ERRORLEVEL% neq 0 (
        echo Compilation failed.
        pause
        exit /b 1
    ) else (
        echo Compilation successful.
    )
)

if not exist %EXEFILE% (
    echo Error: AutoClicker.exe not found.
    pause
    exit /b 1
)

echo Starting the AutoClicker program...
start %EXEFILE%
