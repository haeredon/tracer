#!/bin/sh

echo "Starting Tests\n"

g++ responder/main.cpp -o responder_app
g++ requester/main.cpp -o requester_app

./responder_app &
./requester_app

rm responder_app requester_app