#take input from the user and find the sum of its digits. print whether the sum #is odd or even

digit=0
sum=0
echo "Enter your number"
read number
while [ $number -gt 0 ]
do
	digit=$(($number%10))
	sum=$(($sum+$digit))
	number=$(($number/10))
done
echo "The sum of the digits is $sum"
check=$(($sum%2))
case $check in
	0)
		echo "The sum is even"
		;;
	1)
		echo "The sum is odd"
		;;
	*) 
		echo "Invalid Error"
		;;
esac
