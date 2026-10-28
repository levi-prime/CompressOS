@echo off
title CompressOS Pinecil Firmware Builder

echo ========================================
echo   CompressOS Pinecil Firmware Build
echo ========================================
echo.
:: copy and paste the dirrectory of IronOS or CompressOS into the space below, eg. C:\Users\*your_username*\Projects\IronOS.
:: this script needs to know where your IronOS or CompressOS location is, as the makers of IronOS made scripts in that location.
cd "C:\Users\*your_IronOS_driectory*"
wsl bash -c "./scripts/deploy.sh pinecilv2"
:: this script is definded for english because that's what the current dev speaks. For your language modify the entry in deploy.sh
:: Change the two letter designator to your language of choice or make a new elif with your two letter designator.

if errorlevel 1 (
    echo.
    echo Build Failed!
) else (
    echo.
    echo Build Compleated Succesfully!
    echo look int the source/ directory for the generated Hexfile and use .bin for flashing.
)

echo.
pause