echo [INFO]: Building problem 'exams'.
pushd problems\exams
call doall.bat
popd

echo [INFO]: Building problem 'andorxor'.
pushd problems\andorxor
call doall.bat
popd

echo [INFO]: Building problem 'naruto-and-ichiraku-san'.
pushd problems\naruto-and-ichiraku-san
call doall.bat
popd

echo [INFO]: Building problem 'keys-and-lamps-codeforces'.
pushd problems\keys-and-lamps-codeforces
call doall.bat
popd

echo [INFO]: Building english contest statement.
pushd statements\english
call doall.bat
popd

