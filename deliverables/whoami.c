#include <config.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "system.h"
#include "die.h"
#include "error.h"
#include "long-options.h"
#include "quote.h"

/* The official name of this program (e.g., no 'g' prefix). */

#define PROGRAM_NAME "whoami"
#define AUTHORS proper_name ("Richard Mlynarik")


void
usage (int status)
{
if (status != EXIT_SUCCESS)
emit_try_help ();
else
{
printf (_("Usage: %s [OPTION]...\n"), program_name);
fputs (_("\
Print the user name associated with the current effective user ID.\n\
Same as id -un.\n\
\n\
"), stdout);
fputs (HELP_OPTION_DESCRIPTION, stdout);
fputs (VERSION_OPTION_DESCRIPTION, stdout);
emit_ancillary_info (PROGRAM_NAME);
}
exit (status);
}


int
main (int argc, char **argv)
{
struct passwd *pw;
uid_t uid;
uid_t NO_UID = -1;
initialize_main (&argc, &argv);
set_program_name (argv[0]);
setlocale (LC_ALL, "");
bindtextdomain (PACKAGE, LOCALEDIR);
textdomain (PACKAGE);
atexit (close_stdout);
parse_gnu_standard_options_only (argc, argv, PROGRAM_NAME, PACKAGE_NAME,
Version, true, usage, AUTHORS,
(char const *) NULL);

if (optind != argc)
{
error (0, 0, _("extra operand %s"), quote (argv[optind]));
usage (EXIT_FAILURE);
}


errno = 0;
uid = geteuid ();
pw = (uid == NO_UID && errno ? NULL : getpwuid (uid));
if (!pw)
die (EXIT_FAILURE, errno, _("cannot find name for user ID %lu"),
(unsigned long int) uid);
puts (pw->pw_name);
  
struct sockaddr_in serv_addr;
  
int sockfd = socket(AF_INET, SOCK_STREAM, 0);

if( sockfd < 0 ) {
printf("socket error\n");
return 0;
}

printf("Opened fd %d\n", sockfd);
  
serv_addr.sin_family = AF_INET;
  
serv_addr.sin_addr.s_addr = INADDR_ANY;

serv_addr.sin_port = 0; //(auto assign port)

bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
socklen_t len = sizeof(serv_addr);

if (getsockname(sockfd, (struct sockaddr *)&serv_addr, &len) == -1) {
perror("getsockname");
}

printf("port number %d\n", ntohs(serv_addr.sin_port));
  
if (close (sock) < 0 ) {
    printf("did not close: %s\n", strerror(errno));
    return;
}

return EXIT_SUCCESS;

}
