#!/bin/bash

if [ $# != 1 ]
then
	echo '문제 번호 파라미터로 넘길것!'
	exit
fi

cd /Volumes/Program/ps-study/dalcom/boj

if [ -d $1 ]
then 
	echo '이미 존재하는 폴더임!'
	exit
fi

mkdir $1
touch $1/$1.py $1/input.txt

echo -e "from sys import stdin as input\ninput = open(\"/Volumes/Program/ps-study/dalcom/boj/$1/input.txt\", \"rt\")" > $1/$1.py

echo '완료!' 
