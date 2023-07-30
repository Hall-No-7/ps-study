#!/bin/bash

LEVEL=("B1" "B2" "B3" "B4" "B5" "S1" "S2" "S3" "S4" "S5" "G1" "G2" "G3" "G4" "G5" "P1" "P2" "P3" "P4" "P5" "D1" "D2" "D3" "D4" "D5" "R1" "R2" "R3" "R4" "R5" "U")

check_level() {
    for i in ${LEVEL[*]}
    do
        if [ $i == $1 ]
        then
            return 0
        fi
    done
    return 1
}

PROBLEM_TYPES=("TRIE" "DFS" "BFS" "DP" "IMPLEMENTATION" "BINARY_SEARCH" "SIMULATION" "GRAPH" "MATH" "STRING" "DATA_STRUCTURE" "DIJKSTRA" "UNION-FIND" "BACK-TRACKING" "SEGMENT-TREE")

check_type() {
    for i in ${PROBLEM_TYPES[*]}
    do
        if [ $i == $1 ]
        then
            return 0
        fi
    done
    return 1
}

if [ $# -lt 6 ]
then
    echo -e "\033[1;31m[ERROR]\033[0m NOT ENOUGH ARGUMENT"
    echo -e "\033[1;32m[HINT]\033[0m $0 -n 1000 -l B1 -t DFS"
    exit 1
fi

for i in {1..3}
do
    case "$1" in
        -f|--file)
            if [ -n "$2" ]
            then
                if [ ! -e $2 ]
                then
                    echo -e "\033[1;31m[ERROR]\033[0m FILE NOT EXIST"
                    echo -e "\033[1;32m[HINT] 파일이 존재하는지 확인하세요.\033[0m"
                    exit 1
                fi
                echo -e "\033[1;32m[CHECK FILE]\033[0m $2"
                FILE_NAME=$2
                PROBLEM_NUMBER=${FILE_NAME%.*}
                RE="^[0-9]+$"
                if [[ $PROBLEM_NUMBER =~ $RE ]]
                then
                    echo -e "\033[1;32m[CHECK NUMBER]\033[0m $PROBLEM_NUMBER"
                    shift
                    shift
                    continue
                else
                    echo -e "\033[1;31m[ERROR]\033[0m PROBLEM NUMBER ERROR"
                    echo -e "\033[1;32m[HINT]\033[0m $0 \033[1;32m-f 1234.py\033[0m -l B1 -t DFS"
                    echo -e "\033[1;32m[HINT] 파일 이름은 문제 번호로만 지어야 합니다.\033[0m"
                    exit 1
                fi
            else
                echo -e "\033[1;31m[ERROR]\033[0m PROBLEM FILE ERROR"
                echo -e "\033[1;32m[HINT]\033[0m $0 \033[1;32m-f 1234.py\033[0m -l B1 -t DFS"
                exit 1
            fi
            ;;
        -l|--level)
            if [ -n "$2" ]
            then
                check_level $2
                if [ 0 -eq $? ]
                then
                    echo -e "\033[1;32m[CHECK LEVEL]\033[0m $2"
                    PROBLEM_LEVEL=$2
                    shift
                    shift
                    continue
                fi
            fi
            echo -e "\033[1;31m[ERROR]\033[0m PROBLEM LEVEL ERROR"
            echo -e "\033[1;32m[HINT]\033[0m $0 -n 1000 \033[1;32m-l B1\033[0m -t DFS"
            echo -e "\033[1;34m[LEVEL LIST]\033[0m ${LEVEL[*]}" 
            exit 1
            ;;
        -t|--type)
            if [ -n "$2" ]
            then
                check_type $2
                if [ 0 -eq $? ]
                then
                    echo -e "\033[1;32m[CHECK TYPE]\033[0m $2"
                    PROBLEM_TYPE=$2
                    shift
                    shift
                    continue
                fi
            fi
            echo -e "\033[1;31m[ERROR]\033[0m PROBLEM TYPE ERROR"
            echo -e "\033[1;32m[HINT]\033[0m $0 -n 1000 -l B1 \033[1;32m-t DFS\033[0m"
            echo -e "\033[1;34m[TYPE LIST]\033[0m ${PROBLEM_TYPES[*]}"
            echo -e "IF YOU WANT TO ADD TYPE, UPDATE \033[1;32mPROBLEM_TYPES\033[0m ARRAY IN $0"
            ;;
        *)
            echo -e "\033[1;31m[ERROR]\033[0m INVALID OPTION"
            echo -e "\033[1;34m[OPTION LIST]\033[0m -n, --number, -l, --level, -t, --type"
            echo -e "\033[1;32m[HINT]\033[0m $0 -n 1000 -l B1 -t DFS"
            exit 1
            ;;
    esac
done

echo ""
echo -e "\033[1;34m==== 생성한 커밋 메시지 ====\033[0m"
echo "[Solved Problem]
Problem Number : ${PROBLEM_NUMBER}
Problem Type   : ${PROBLEM_TYPE}
Problem Level  : ${PROBLEM_LEVEL}"
echo -e "\033[1;34m==== 생성한 메시지 종료 ====\033[0m"
echo ""

read -p "이대로 ADD -> COMMIT -> PUSH 하시겠습니까? (Y/n)" ANSWER
if [ "$ANSWER" == "Y" ] || [ "$ANSWER" == "y" ] || [ -z $ANSWER ]
then
    echo -e "\033[1;32m[INFO]\033[0m ADD -> COMMIT -> PUSH"
else
    echo -e "\033[1;31m[INFO]\033[0m EXIT"
    exit 1
fi


git add $FILE_NAME
git commit $FILE_NAME -m "[Solved Problem]
Problem Number : ${PROBLEM_NUMBER}
Problem Type   : ${PROBLEM_TYPE}
Problem Level  : ${PROBLEM_LEVEL}"
git pull origin main
git push origin main

