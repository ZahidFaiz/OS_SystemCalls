       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <unistd.h>
void main ()
{
	mknod("p",S_IFIFO,0);
}
