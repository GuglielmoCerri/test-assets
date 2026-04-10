@echo off
:: sample.bat — Synthetic Windows batch script for parser and syntax testing.
:: Demonstrates: variables, conditionals, loops, functions (labels), error levels.

setlocal EnableDelayedExpansion

:: ── Configuration ─────────────────────────────────────────────────────────────

set APP_NAME=sample-service
set LOG_DIR=C:\Logs\%APP_NAME%
set DATA_DIR=C:\Data\%APP_NAME%
set ARCHIVE_DAYS=30

:: ── Entry point ───────────────────────────────────────────────────────────────

call :log INFO "Starting %APP_NAME% maintenance script"
call :check_directories
call :check_dependencies
call :print_summary
call :log INFO "Done."
endlocal
exit /b 0

:: ── :log ──────────────────────────────────────────────────────────────────────

:log
    set LEVEL=%~1
    shift
    echo %DATE% %TIME% [%LEVEL%] %*
    exit /b 0

:: ── :check_directories ────────────────────────────────────────────────────────

:check_directories
    call :log INFO "Checking required directories..."
    for %%D in ("%LOG_DIR%" "%DATA_DIR%") do (
        if not exist "%%~D\" (
            mkdir "%%~D" 2>nul
            if !errorlevel! equ 0 (
                call :log INFO "Created directory: %%~D"
            ) else (
                call :log ERROR "Failed to create directory: %%~D"
                exit /b 1
            )
        ) else (
            call :log INFO "Directory exists: %%~D"
        )
    )
    exit /b 0

:: ── :check_dependencies ───────────────────────────────────────────────────────

:check_dependencies
    call :log INFO "Checking dependencies..."
    for %%C in (curl.exe powershell.exe) do (
        where %%C >nul 2>&1
        if !errorlevel! neq 0 (
            call :log ERROR "Required command not found: %%C"
            exit /b 1
        )
        call :log INFO "Found: %%C"
    )
    exit /b 0

:: ── :print_summary ────────────────────────────────────────────────────────────

:print_summary
    call :log INFO "Environment summary:"
    call :log INFO "  APP_NAME   = %APP_NAME%"
    call :log INFO "  LOG_DIR    = %LOG_DIR%"
    call :log INFO "  DATA_DIR   = %DATA_DIR%"
    call :log INFO "  OS         = %OS%"
    call :log INFO "  USERNAME   = %USERNAME%"
    exit /b 0
