set ns [new Simulator]

$ns color 1 Green 
$ns color 2 Red

set nt [open simulate.nam w]
$ns namtrace-all $nt

set tr [open simulate.tr w]
$ns trace-all $tr

proc finish {} {
	global ns nt tr
	$ns flush-trace
	#close the NAM Trace File
	close $nt
	close $tr
	exec nam simulate.nam &
	exit 0
}


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 20ms DropTail

$ns duplex-link $n3 $n4 2Mb 10ms DropTail
$ns duplex-link $n3 $n5 2Mb 10ms DropTail


$ns queue-limit $n2 $n3 10

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n3 $n4 orient right-up
$ns duplex-link-op $n3 $n5 orient right-down


$ns duplex-link-op $n2 $n3 queuePos 0.5



set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 2


set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP


set udp [new Agent/UDP]
$ns attach-agent $n1 $udp

set null [new Agent/Null]
$ns attach-agent $n5 $null
$ns connect $udp $null
$udp set fid_ 1


set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set pack_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false


$ns at 0.2 "$cbr start"
$ns at 1.0 "$ftp start"

$ns at 4.0 "$ftp stop"
$ns at 4.6 "$cbr stop"

$ns at 5.0 "finish"

$ns run
