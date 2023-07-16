#!/bin/bash

if [ $# != 1 ]
then
	echo '문제 번호 파라미터로 넘길것!'
	exit
fi

cd /Volumes/Program/ps-study/dalcom

if [ -d $1 ]
then 
	echo '이미 존재하는 폴더임!'
	exit
fi

mkdir $1
touch $1/$1.py $1/input.txt

echo -e "from sys import stdin \ninput = (lambda: open(\"/Volumes/Program/ps-study/dalcom/$1/input.txt\", \"rt\").readline().strip())" > $1/$1.py

echo '완료!' 
