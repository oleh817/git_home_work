#!/bin/sh

# Infinite loop to send a message to the server every 3 seconds
while true; do
  echo "Hello from Client!" | nc -w 3 server 12345
  sleep 3
done
