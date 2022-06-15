# Webserv
<p align="left"> <a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a> <a href="https://www.php.net" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/php/php-original.svg" alt="php" width="40" height="40"/> </a> </p>

## Purpose
- Write a http server in c++98
- Base file configuration should follow nginx model
- Server should work as per RFC standard for HTTP/1.1
- A request to the server should never hang forever
- Server must be compatible with the web browser of our choice (mozilla and chrome)
- HTTP response status codes must be accurate
- Server must have default error pages if none are provided
- Server must be able to serve a fully static website
- Clients must be able to upload files (binary files are not handled)
- GET, POST, and DELETE methods are required
- Server must stay available at all cost (stress test using siege)
- Implement multiplexed socket management using either select, poll, epoll or kqueue (we used kqueue)

## Grade
**110 / 100**
<br>
<br>
![Alt text](../images/rank110.png)

## Usage
Run the Makefile with the `make all` command to compile all the files
Then run the executable `./webserv`

## Dependencies :
Has we used kqueue to implement our server which is less portable than select, program might not compile depending on the OS you are using (project was built and tested on MacOS).
* __clang++__
* __MacOS__
* __make__


## Resources

  [bash reference manual](https://www.gnu.org/software/bash/manual/bash.pdf)