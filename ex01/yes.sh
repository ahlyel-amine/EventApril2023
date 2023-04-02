#!/bin/bash

while :
do
	ls | tr '.h' ' ' | awk '{print $1}'
done

