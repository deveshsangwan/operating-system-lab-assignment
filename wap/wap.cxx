#include <iostream>
#include <cstring>
#include <fcntl.h>

using namespace std;

int main()
{
    int fd = open("./example.txt", O_CREAT|O_RDWR);
    if(fd == -1){
        cout<<"Some Error occured!";
        return 0;
    }
    char c[1024];
    cout<<"Reading the file\n";
    while(read(fd, c, 1) > 0){
        cout<<*c;
    }
    cout<<"\n\nAppending into the file\n";
    char nc[1024] = "\nthis is some new text\n";
    if(write(fd, nc, strlen(nc)) > 0){
        cout<<"write operation is successfull\n";
    } else{
        cout<<"write operation failed\n";
    }
    cout<<"\nClosing file..\n";
    close(fd);
    cout<<"\nEnd of Program";
    return 0;
}
