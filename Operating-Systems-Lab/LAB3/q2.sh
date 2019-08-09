echo "Enter a number"
read number
echo "The first $number odd numbers are: "
x=1
while [ $number -gt 0 ]
do
	mod=`expr $x \% 2`
	if [ $mod -eq 1 ]
	then
		echo $x
		number=`expr $number - 1`
	fi
	x=`expr $x + 1`
done

	


