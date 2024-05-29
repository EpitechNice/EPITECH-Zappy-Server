#!/bin/bash

sudo docker run --rm --security-opt "label:disable" -i -v .:"/mnt/delivery" -v .:"/mnt/reports" ghcr.io/epitech/coding-style-checker:latest "/mnt/delivery" "/mnt/reports"
echo -e "You have \033[94m$(grep -v "libs" "coding-style-reports.log" | grep -c ": INFO:")\033[0m infos !"
echo -e "You have \033[93m$(grep -v "libs" "coding-style-reports.log" | grep -c ": MINOR:")\033[0m minor errors !"
echo -e "You have \033[91m$(grep -v "libs" "coding-style-reports.log" | grep -c ": MAJOR:")\033[0m major errors !"
echo "===== INFOS ====="
cat coding-style-reports.log | grep ": INFO:" | grep -v "libs"
echo "===== MINORS ====="
cat coding-style-reports.log | grep ": MINOR:" | grep -v "libs"
echo "===== MAJORS ====="
cat coding-style-reports.log | grep ": MAJOR:" | grep -v "libs"
rm -f coding-style-reports.log