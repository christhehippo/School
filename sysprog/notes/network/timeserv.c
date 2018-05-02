#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <strings.h>


#define  PORTNUM  1300
#define  HOSTLEN  256

#define oops(msg)   { perror(msg); exit(1); }


int main (int argc, char **argv)
{
	struct sockaddr_in  saddr;
	struct hostent	   *hp		= NULL;
	char   hostname[HOSTLEN];
	int    sock_id, sock_fd;
	FILE  *sock_fp  = NULL;
	char  *ctime();
	time_t thetime;

	// query the kernal for a socket
	sock_id  = socket(PF_INET, SOCK_STREAM, 0);
	if (sock_id == -1)
		oops("socket");

	// bind address to socket
	bzero((void *)&saddr, sizeof(saddr));
	gethostname(hostname, HOSTLEN);
	hp = gethostbyname(hostname);

	bcopy ((void *) hp -> h_addr_list[0], (void *) &saddr.sin_addr, hp->h_length);
	saddr.sin_port = htons(PORTNUM);
	saddr.sin_family = AF_INET;
	
	if (bind(sock_id, (struct sockaddr *)&saddr, sizeof(saddr)) != 0)
		oops("bind");

	// allow incoming connections to socket (ie enablification the 
	// listenificationinf, naough)
	// 
	if (listen(sock_id, 1) != 0)
		oops("listen");

	//  main screen turn on: accept(), write(), close()
	//
	while (1)
	{
		sock_fd = accept(sock_id,NULL, NULL);
		fprintf(stdout, "What happen!!\n");
		if (sock_fd == -1)
			oops("accept");

		sock_fp = fdopen(sock_fd, "w");
		if (sock_fp == NULL)
			oops("fdopen");

		thetime = time(NULL);

		fprintf(sock_fp, "somebody set us up the bomb, at ..");
		fprintf(sock_fp, "%s", ctime(&thetime));
		fclose (sock_fp);
	}



	return(0);
}
