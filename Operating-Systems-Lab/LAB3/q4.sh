echo "Enter a number"
read number
fact=1;
while [ $number -gt 0 ]
do
	fact=`expr $fact \* $number`
        number=`expr $number - 1`
done
echo The factorial of the number is: $fact

