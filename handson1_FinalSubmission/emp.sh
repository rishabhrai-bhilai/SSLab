#!/bin/bash
file="employee.txt"
while [ 1 ]
do
	#clear
	echo "1. Add an employee"
	echo "2. List all employees"
	echo "3. Search an employee"
	echo "4. Delete an employee"
	echo "5. Sort the record"
	echo "0. Exit"
	echo -n "Enter your choice - "
	read choice
	case $choice in
		1)
			echo -n "Name: "
		       read name
	       		echo -n "Employee number: "
	 		read num
			echo -n "Telephone number: "
			read tel
			echo "$name $num $tel" >> $file
			echo "Emplyee added"		
			;;
		2)
			clear
			if [ -r $file ]
			then
				awk 'BEGIN {print "Sr.\tName\tEmployee Number\tTelephone Number";}
				{print NR"\t",$1,"\t",$2,"\t\t",$NF;}
				END{print "--------------------------------------"}' $file
			else
				echo "File not present"
			fi
			;;
		3)
			read -p "Employee number to search: " num
			awk -v num="$num" '{ if($2 == num) print $1,"\t",$2,"\t",$NF;}' employee.txt
			;;
		4)
			echo "Deleting"
			read -p "Employee number to delete: " num
			awk -v num="$num" '{ if($2 != num) print $0;}' $file > "$file.bak"
			mv "$file.bak" $file
			;;
		5)
			sort -k 2n $file > "$file.bak"
			mv "$file.bak" $file
		        echo "Employee sorted"	
			;;
		0)
			echo "Bye"
			break
			;;
		*)
			echo "Enter a valid choice"
			;;
	esac
done
