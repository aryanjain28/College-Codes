#!/bin/bash

while true
do
	echo "1. Create address book."
	echo "2. Insert record."
	echo "3. Display records."
	echo "4. Modify record."
	echo "5. Delete record."
	echo "6. Search record."
	echo "7. Use existing address book."
	echo "8. Delete complete address book."
	echo "9. Exit."
	echo "Enter your choice."
	read choice

	case $choice in

	1)	echo "Enter name of address book."
		read fname

		if [ -e $fname ]; then
		echo "File already exists."

		else
		touch $fname

		echo "File created successfully."
		fi
		;;

	2)	echo "Enter your name : "
		read name
		echo "Enter your age : "
		read age
		echo "Enter your marks : "
		read marks

		echo $name $age $marks >> $fname
		echo "Data inserted successfully."
		;;

	3)	echo "Address book : "
		cat $fname
		;;

	4)	echo "Enter name of the record to be modified : "
		read modifyRecord
		grep -i -v "^$modifyRecord" $fname >> nFile.txt
		cp nFile.txt $fname
		rm nFile.txt

		echo "Enter new name : "
		read name
		echo "Enter new age : "
		read age
		echo "Enter new marks : "
		read marks

		echo $name $age $marks >> $fname		
		;;

	5)	echo "Enter name of the record to be deleted : "
		read deleteRecord
		grep -i -v "^$deleteRecord" $fname >> nFile.txt
		cp nFile.txt $fname
		rm nFile.txt		
		;;

	6)	echo "Enter name of the record to be searched : "
		read searchRecord
		grep -i "^$searchRecord" $fname >> nFile
		cat nFile
		rm nFile
		;;

	7)	echo "Enter name of address book : "
		read fname

		if [ -e $fname ]; then
		echo "File exists."

		else
		echo "File not exists."
		fi
		;;
	
	8)	echo "Enter name of address book : "
		read fname

		if [ -e $fname ]; then
		rm $fname
		echo "Address book deleted."

		else
		echo "File not exists."
		fi
		;;

	9) 	echo "Thank you!"
		exit
		;;

	*)	echo "INVALID!"

	esac
done
