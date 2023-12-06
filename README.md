# UnitTest

컴파일 명령어
gcc -o test unitTest.c `pkg-config --cflags --libs check`

처음 주소 이동할 때 
/mnt/d 

// 처음 라이브러리 생성
sudo apt update
sudo apt install check

// vs code에 wsl깔고, wsl상에서 code . 실행 



// 정적 분석을 위한 cppCheck
sudo apt-get install cppcheck

// 실제 정적 분석 실행
cppcheck --enable=all --suppress=missingIncludeSystem .
