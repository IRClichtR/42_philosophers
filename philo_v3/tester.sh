#!/bin/bash

# quick tester for philosopher

./philo 200 150 60 60 > 200_150_60_60.txt 2>&1
philo_pid=$!

sleep 20

kill -15 $philo_pid > /dev/null 2>&1
sleep 5
kill -9 $philo_pid
if grep -q "died" 200_150_60_60.txt; then
	echo -e "\033[0;31m200 150 60 60 -- FAILED!\033[0m"
else
	echo -e "\033[0;32m200 150 60 60 -- SUCCESS!\033[0m"
fi

./philo 4 410 200 200 > 4_410_200_200.txt 2>&1
philo_pid=$!

sleep 20

kill -15 $philo_pid > /dev/null 2>&1
sleep 5
kill -9 $philo_pid
if grep -q "died" 4_410_200_200.txt; then
	echo -e "\033[0;31m4 410 200 200 -- FAILED!\033[0m"
else
	echo -e "\033[0;32m4 410 200 200 -- SUCCESS!\033[0m"
fi

./philo 5 800 200 200 7 > 5_800_200_200_7.txt 2>&1
philo_pid=$!

sleep 20

kill -15 $philo_pid > /dev/null 2>&1
sleep 5
kill -9 $philo_pid
if grep -q "died" 5_800_200_200_7.txt; then
	echo -e "\033[0;31m200 150 60 60 -- FAILED (diedd)!\033[0m"
else
	eating_count=$(grep -o "1 is eating\|2 is eating\|3 is eating\|4 is eating\|5 is eating" 5_800_200_200_7.txt | wc -l)
	if [ "$eating_count" -lt 7 ]; then
        echo -e "\033[0;31m5 800 200 200 7 -- FAILED! (Less than 7 eating occurrences)\033[0m"
    else
        echo -e "\033[0;32m5 800 200 200 7 -- SUCCESS!\033[0m"
    fi
fi

./philo 5 800 200 200 > 5_800_200_200.txt 2>&1
philo_pid=$!

sleep 20

kill -15 $philo_pid > /dev/null 2>&1
sleep 5
kill -9 $philo_pid
if grep -q "died" 5_800_200_200.txt; then
	echo -e "\033[0;31m5 800 200 200 -- FAILED!\033[0m"
else
	echo -e "\033[0;32m5 800 200 200 -- SUCCESS!\033[0m"
fi

./philo 3 620 200 200 > 3_620_200_200.txt 2>&1
philo_pid=$!

sleep 20

kill -15 $philo_pid > /dev/null 2>&1
sleep 5
kill -9 $philo_pid
if grep -q "died" 3_620_200_200.txt; then
	echo -e "\033[0;31m3 620 200 200 -- FAILED!\033[0m"
else
	echo -e "\033[0;32m3 620 200 200 1 -- SUCCESS!\033[0m"
fi

./philo 4 310 200 100 > 4_310_200_100.txt 2>&1
philo_pid=$!

sleep 20

kill -15 $philo_pid > /dev/null 2>&1
sleep 5
kill -9 $philo_pid
if grep -q "died" 4_310_200_100.txt; then
	echo -e "\033[0;32m4 310 200 100 -- SUCCESS!\033[0m"
else
	echo -e "\033[0;31m4 310 200 100 -- FAILED!\033[0m"
fi

./philo 2 410 200 200 > 2_410_200_200.txt 2>&1
philo_pid=$!

sleep 20

kill -15 $philo_pid > /dev/null 2>&1
sleep 5
kill -9 $philo_pid
if grep -q "died" 2_410_200_200.txt; then
	echo -e "\033[0;31m2 410 200 200 -- FAILED!\033[0m"
else
	echo -e "\033[0;32m2 410 200 200 -- SUCCESS!\033[0m"
fi

mv *.txt TESTS_LOGS/

#4 410 200 200
#5 800 200 200 7
#5 800 200 200
#3 620 200 200
#4 310 200 100 --> should stop
#2 410 200 200
