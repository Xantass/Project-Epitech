#!/bin/bash

function clean_up {

    rm original
    rm home_made
}

function compare_hexdump {

    hexdump $1 > original
    hexdump $2 > home_made

    cmp -s original home_made

    if [ $? == 0 ]; then
        echo -e "\e[0;32mfiles are identical\e[0;m"
    else
        echo -e "\e[0;31mfiles are not identical\e[0;m"
        echo -e "\e[0;32m"
        cmp -b home_made original
        echo -e "\e[0;m"
        echo -e "\e[0;33m"
        cat home_made
        echo -e "\e[0;m"
    fi
}

function run_test {
    b_name=`basename $1`
    b_name=${b_name%?}

    ./perfect_binary/asm $1
    clean_binary_return=$?

    mv $b_name* clean_binary.cor &> /dev/null
    ../asm $1 &> /dev/null

    if [ $? != $clean_binary_return ]; then
        echo -e "\e[0;36m$1:\e[0;33m Test not passed, Bad return: $? != $clean_binary_return\e[0;m"
        rm *.cor
        return
    fi
    if [ $clean_binary_return == 84 ]; then
        echo -e "\e[0;36m$1:\e[0;32m Test passed.\e[0;m"
        return
    fi

    mv $b_name* test_file.cor
    hexdump clean_binary.cor > test_one
    hexdump test_file.cor > test_two
    cmp -s test_one test_two

    if [ $? != 0 ]; then
        echo -e "\e[0;36m$1:\e[0;33m Test not passed, Differing hexdump..\e[0;m"
        rm *.cor;rm test_*
        return
    fi
    echo -e "\e[0;36m$1:\e[0;32m Test passed.\e[0;m"
    rm *.cor;rm test_*
}

function run_tests_collection {
    cd ..
    make &> /dev/null
    cd ./tests
    for file in ./asm_file/*.s; do
        run_test $file
    done
}
if [ $1 == "-all" ]; then
    run_tests_collection
else
    compare_hexdump $1 $2
    clean_up
fi
