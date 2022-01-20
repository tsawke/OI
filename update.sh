#!/bin/bash

time=$(date "+%Y-%m-%d_%H\:%M\:%S")

git add .
git commit -m ``"Generally Update - $time - By 123.56.4.12"``
git push