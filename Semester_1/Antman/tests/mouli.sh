#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## mouli.sh
## File description:
## mouli.sh
##

get_test() {
    if [ $1 = 0 ]; then
        if [ $2 = "time" ]; then
            echo -e "\n\n\e[34;1mAntman Execution Time\e[0m"
            time ./antman/antman ./antman/test_files/TXT/test.txt > ./giantman/test_files/temp
            echo -e "\n\e[34;1mGiantman Execution Time\e[0m"
            time ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/TXT/test.txt" > ./tests/tmp
            echo -e "\n\e[36;1mTXT File\e[0m:"
        else
            ./antman/antman ./antman/test_files/TXT/test.txt > ./giantman/test_files/temp
            ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/TXT/test.txt" > ./tests/tmp
            echo -e "\n\e[36;1mTXT File\e[0m:"
        fi
    elif [ $1 = 1 ]; then
        if [ $2 = "time" ]; then
            echo -e "\n\n\e[34;1mAntman Execution Time\e[0m"
            time ./antman/antman ./antman/test_files/LYR/test.lyr > ./giantman/test_files/temp
            echo -e "\n\e[34;1mGiantman Execution Time\e[0m"
            time ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/LYR/test.lyr" > ./tests/tmp
            echo -e "\n\e[36;1mLYR File\e[0m:"
        else
            ./antman/antman ./antman/test_files/LYR/test.lyr > ./giantman/test_files/temp
            ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/LYR/test.lyr" > ./tests/tmp
            echo -e "\n\e[36;1mLYR File\e[0m:"
        fi
    elif [ $1 = 2 ]; then
        if [ $2 = "time" ]; then
            echo -e "\n\n\e[34;1mAntman Execution Time\e[0m"
            time ./antman/antman ./antman/test_files/HTML/test.html > ./giantman/test_files/temp
            echo -e "\n\e[34;1mGiantman Execution Time\e[0m"
            time ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/HTML/test.html" > ./tests/tmp
            echo -e "\n\e[36;1mHTML File\e[0m:"
        else
            ./antman/antman ./antman/test_files/HTML/test.html > ./giantman/test_files/temp
            ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/HTML/test.html" > ./tests/tmp
            echo -e "\n\e[36;1mHTML File\e[0m:"
        fi
    elif [ $1 = 3 ]; then
        if [ $2 = "time" ]; then
            echo -e "\n\n\e[34;1mAntman Execution Time\e[0m"
            time ./antman/antman ./antman/test_files/PPM/test.ppm > ./giantman/test_files/temp
            echo -e "\n\e[34;1mGiantman Execution Time\e[0m"
            time ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/PPM/test.ppm" > ./tests/tmp
            echo -e "\n\e[36;1mPPM File\e[0m:"
        else
            ./antman/antman ./antman/test_files/PPM/test.ppm > ./giantman/test_files/temp
            ./giantman/giantman ./giantman/test_files/temp > ./tests/res
            echo "./antman/test_files/PPM/test.ppm" > ./tests/tmp
            echo -e "\n\e[36;1mPPM File\e[0m:"
        fi
        #elif [ $1 = 4 ]; then
        #   if [ $2 = "time" ]; then
        #      echo -e "\n\n\e[34;1mAntman Execution Time\e[0m"
        #     time ./antman/antman ./antman/test_files//test.png > ./giantman/test_files/temp
        #    echo -e "\n\e[34;1mGiantman Execution Time\e[0m"
        #   time ./giantman/giantman ./giantman/test_files/temp > ./tests/res
        #  echo  "./antman/test_files/PNG/test.png" > ./tests/tmp
        # echo -e "\n\e[36;1mPNG File\e[0m:"
        #else
        #./antman/antman ./antman/test_files/PNG/test.png > ./giantman/test_files/temp
        #   ./giantman/giantman ./giantman/test_files/temp > ./tests/res
        #  echo  "./antman/test_files/PNG/test.png" > ./tests/tmp
        # echo -e "\n\e[36;1mPNG File\e[0m:"
        #fi
    #elif [ $1 = 4 ]; then
     #   if [ $2 = "time" ]; then
      #      echo -e "\n\n\e[34;1mAntman Execution Time\e[0m"
       #     time ./antman/antman ./antman/test_files/SVG/test.svg > ./giantman/test_files/temp
        #    echo -e "\n\e[34;1mGiantman Execution Time\e[0m"
         #   time ./giantman/giantman ./giantman/test_files/temp > ./tests/res
          #  echo "./antman/test_files/SVG/test.svg" > ./tests/tmp
           # echo -e "\n\e[36;1mSVG File\e[0m:"
    #else
     #       ./antman/antman ./antman/test_files/SVG/test.svg > ./giantman/test_files/temp
     #       ./giantman/giantman ./giantman/test_files/temp > ./tests/res
      #      echo "./antman/test_files/SVG/test.svg" > ./tests/tmp
       #     echo -e "\n\e[36;1mSVG File\e[0m:"
        #fi
    fi
}

print_percent() {
    if [ $1 -lt 0 ]; then
        echo -e "\e[91;1mFAIL: \e[0mThe file was compressed and reduced to \e[91;1m0%\e[0m of it's original size"
    elif [ $1 = 100 ]; then
        echo -e "\e[92;1mSUCCES: \e[0mThe file was compressed and reduced to \e[92;1m100%\e[0m of it's original size"
    elif [ $1 -gt 79 ]; then
        echo -e "\e[33;1mWITH LOSSES: \e[0mThe file was compressed and reduced to \e[33;1m$1%\e[0m of it's original size"
    else
        echo -e "\e[91;1mFAIL: \e[0mThe file was compressed and reduced to \e[91;1m$1%\e[0m of it's original size"
    fi
}
flags="nothing"
i=0
if [ "$#" = 1 ]; then
    if [ $1 = "-t" ]; then
        flags="time"
    else
        echo -e "\e[34;1mTry -t to see each execution time\e[0m"
    fi
fi
while [ $i -lt 4 ]; do
    get_test $i $flags
    filepath=$( cat ./tests/tmp )
    cmp -s ./tests/res $filepath
    if [ $? -eq 0 ]; then
        echo -e "\e[92;1mThe files are identical\e[0m"
        f1=$(stat -c %s $filepath)
        f2=$(stat -c %s "./tests/res")
        echo "Original File Size =" $f1
        echo "Result File Size =" $f2
        print_percent 100
    else
        echo -e "\e[91;1mThe files are not identical\e[0m"
        f1=$(stat -c %s $filepath)
        f2=$(stat -c %s "./tests/res")
        echo "Original File Size =" $f1
        echo "Result File Size =" $f2
        res=$(expr $f1 - $f2)
        if [ $res -lt 0 ]; then
            res=$(($res * -1))
        fi
        res=$(($res * 100))
        res=$(($res / $f1))
        res=$((100 - $res))
        print_percent $res
    fi
    i=$((i + 1))
done
echo -e ""
rm ./tests/tmp
rm ./tests/res

