# GET NEXT LINE

##### NAME: 
    get_next_line

##### SYNOPSIS: 
    int get_next_line(int fd,  char **line)
    
    ==> fd: Fildes descriptor
    ==> line: destination buffer

##### DESCRIPTION
    The get next line program attempts to read BUFFER_SIZE bytes from the object referenced by 
    the descriptor fildes untill a new line is met then then write that line into a buff 
    pointed by line. If descriptor fildes is not close and the programme is called again, 
    it will to do the same thing but this time for the second line.
  
    In general, this program at every call will send the first next line met.
  
##### RETURN VALUES
    * -1 if unable to read from descriptor fildes.
    * 1 if successful.
    * 0 is returned when the last line is read ie EOF is reached.
  
##### HOW TO COMPILE
    gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=x get_next_line.c get_next_line_utils.c main.c
    
    ==> x must be greater than 0 or -1 will be returned;
    ==> main.c is your main file. you can look at mine to have an idea.
    
##### BONUS PART
    The bonus part allows you to read from more than one fd (fildes descriptor). 
    you can pass only one fildes descriptor to the program. But it you have more than one fd, at each call 
    the program will copy next line from the given fd into the the buff pointed by line. You just have to 
    compile the *_bonus files intead.
    
