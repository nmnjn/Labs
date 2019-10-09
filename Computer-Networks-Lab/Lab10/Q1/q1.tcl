set ns [new Simulator]

set nf [open out.nam w]
$ns namtrace-all $nf

set tr [open 2.tr w]
$ns trace-all $tr

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

$ns duplex-link $n0 $n1 1Mb 50ms DropTail
$ns duplex-link $n1 $n2 100Kb 5ms DropTail
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right

$ns queue-limit $n1 $n2 10
$ns duplex-link-op $n1 $n2 queuePos 0.5

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 1000
$cbr0 set rate_ 80kb
$cbr0 set random_ false
$cbr0 attach-agent $udp0

set null0 [new Agent/Null]
$ns attach-agent $n2 $null0

$ns connect $udp0 $null0

$ns at 0.5 "$cbr0 start"
$ns at 10.5 "$cbr0 stop"

$ns at 11.0 "finish"

$ns run
