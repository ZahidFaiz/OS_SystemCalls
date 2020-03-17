       #include <sys/types.h>
       #include <sys/stat.h>
void main()
{
	mkfifo("p2",S_IFIFO);
}
