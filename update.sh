#!/bin/bash

time=$(date "+%Y-%m-%d_%H:%M:%S")

git add .
git commit -m ``"Generally Update - $time - By Monkey@jdoi-virtual-machine"``
git push