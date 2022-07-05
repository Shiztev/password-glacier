# password-glacier
A secure password generator. 

## Dependancies
 - <a target="_blank" href="https://github.com/jedisct1/libsodium">libsodium</a>

## Build
In the cloned repository, run:
 - gcc -std=c99 -Wall -Wextra -pedantic -c *.c
 - gcc -std=c99 -o glacier glacier.o password.o -lsodium
