#!/bin/bash

sudo docker run --rm --security-opt "label:disable" -i -v .:"/mnt/delivery" -v .:"/mnt/reports" ghcr.io/epitech/coding-style-checker:latest "/mnt/delivery" "/mnt/reports"
clear
echo -e "You have \033[94m$(grep -c ": INFO:" "coding-style-reports.log")\033[0m infos !"
echo -e "You have \033[93m$(grep -c ": MINOR:" "coding-style-reports.log")\033[0m minor errors !"
echo -e "You have \033[91m$(grep -c ": MAJOR:" "coding-style-reports.log")\033[0m major errors !"
echo "===== INFOS ====="
cat coding-style-reports.log | grep ": INFO:"
echo "===== MINORS ====="
cat coding-style-reports.log | grep ": MINOR:"
echo "===== MAJORS ====="
cat coding-style-reports.log | grep ": MAJOR:"
rm -f coding-style-reports.log