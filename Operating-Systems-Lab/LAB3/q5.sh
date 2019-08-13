echo "Enter first number"
read number1
echo "Enter second number"
read number2
echo "Enter Operation: ( + - * /)"
read operand
case $operand in
	"+")
		ans=`expr $number1 \+ $number2`
		echo "The sum of $number1 and $number2 is $ans"
		;;
	"-")
		ans=`expr $number1 \- $number2`
                echo "The difference of $number1 and $number2 is $ans"
                ;;
	'*')
		ans=`expr $number1 \* $number2`
                echo "The product of $number1 and $number2 is $ans"
                ;;
	"/")
		ans=`expr $number1 \/ $number2`
                echo "The dividend of $number1 and $number2 is $ans"
                ;;
	"*")	
		echo "WRONG CHOICE"
		;;
esac
