sudo apt -y install libulfius-dev
openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 -subj '/CN=localhost' -nodes
gcc -o test test.c -lulfius
./test
