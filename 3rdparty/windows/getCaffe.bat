:: Avoid printing all the comments in the Windows cmd
@echo off

SET UNZIP_EXE=unzip\unzip.exe
SET WGET_EXE=wget\wget.exe

:: Download temporary zip
echo ----- Downloading Caffe -----
SET CAFEE_FOLDER=caffe\
SET ZIP_NAME=caffe_16_2020_11_14.zip
SET ZIP_FULL_PATH=%CAFEE_FOLDER%%ZIP_NAME%

echo ----- Unzipping Caffe -----
%UNZIP_EXE% %ZIP_FULL_PATH%
echo:

echo ----- Deleting Temporary Zip File %ZIP_FULL_PATH% -----
del "%ZIP_FULL_PATH%"

echo ----- Caffe Downloaded and Unzipped -----
