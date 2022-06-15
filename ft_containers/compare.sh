#!/usr/bin/env bash
make re

./ft_containers > ft.out
./std_containers > std.out
printf "comparings files
----------------------------------\n"
if diff std.out ft.out > diff.out
then
	printf "No difference found between the files\n"
else
	printf "Differences found !    :'(
----------------------------------
Open \"diff.out\" to analyse differences\n"
fi

