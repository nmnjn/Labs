echo "Enter A"
read A
echo "Enter B"
read B
echo "Enter C"
read C

disc=`expr $B \* $B - 4 \* $A \* $C`
y=-2
if [ $disc -lt 0 ]
then
       	y=-1
elif [ $disc -eq 0 ]
then 
	y=0
else
       	y=1
fi
case $y in
	0) #ans=`expr $B \* -1 \\ 2 \* $A`
		ans=$((-$B/2*$A))
		echo "Roots are equal: $ans"
		;;
	1) 
		disc=$(echo "scale=2;sqrt($disc)"|bc)
		root1=$(((-$B+disc)/(2*$A)))
		root2=$(((-$B-disc)/(2*$A)))
		echo "Root are different: $root1, $root2"
		;;
	-1)
		disc=$((-$disc))
		rootdisc=$(echo "scale=2;sqrt($disc)"|bc)
		real=$(echo "scale=2;((-$B/(2*$A)))"|bc)
        echo "Roots are imaginary: $real+{$rootdisc}i, $real-{$rootdisc}i"
		;;
	*) echo "INVALID"
		;;
esac

