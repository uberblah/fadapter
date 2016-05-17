#!/bin/sh

mkfifo f g

cat g >test_out &
ECHO_PID=$!

./fadapter f >g &
FAD_PID=$!

cat test_in1 >f
cat test_in2 >f

kill $FAD_PID $ECHO_PID 2>&1 >/dev/null
rm f g

diff test_out test_correct
