#!/bin/bash

x=0
for file in compiled_a/*
do
	if [ $x -gt 25 ]
	then
		rm $file
	fi
	x=$((x+1))
done

x=0
for file in compiled_b/*
do
	if [ $x -le 25 ] || [ $x -gt 50 ]
	then
		rm $file
	fi
	x=$((x+1))
done

x=0
for file in compiled_c/*
do
	if [ $x -le 50 ] || [ $x -gt 75 ]
	then
		rm $file
	fi
	x=$((x+1))
done

x=0
for file in compiled_d/*
do
	if [ $x -le 75 ]
	then
		rm $file
	fi
	x=$((x+1))
done