set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set nf [open out.nam w]
$ns namtrace-all $nf

proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]


$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n3 $n2 0.5Mb 10ms SFQ

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

$ns duplex-link-op $n2 $n3 queuePos 0.5
set cbr0 [new Agent/CBR]
$ns attach-agent $n0 $cbr0
$cbr0 set packet_size_ 500
$cbr0 set interval_ 0.005
$cbr0 set fid_ 1

set cbr1 [new Agent/CBR]
$ns attach-agent $n1 $cbr1
$cbr1 set packet_size_ 500
$cbr1 set interval_ 0.005
$cbr1 set fid_ 2

set null0 [new Agent/Null]
$ns attach-agent $n3 $null0

$ns connect $cbr0 $null0
$ns connect $cbr1 $null0

$ns at 0.5 "$cbr0 start"
$ns at 1.0 "$cbr1 start"
$ns at 4.0 "$cbr1 stop"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run
