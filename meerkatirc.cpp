#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

IRC::meerkt(QString name)

{
    if (hook->function)
    {
        if (!hook->next)
        {
            hook->next=new irc_command_hook;
            hook->next->function=0;
            hook->next->irc_command=0;
            hook->next->next=0;
        }
        insert_irc_command_hook(hook->next, cmd_name, function_ptr);
    }
    else
    {
        hook->function=function_ptr;
        hook->irc_command=new char[strlen(cmd_name)+1];
        strcpy(hook->irc_command, cmd_name);
    }
}

void IRC::hook_irc_command(char* cmd_name, int (*function_ptr)(char*, irc_reply_data*, void*))
{
    if (!hooks)
    {
        hooks=new irc_command_hook;
        hooks->function=0;
        hooks->irc_command=0;
        hooks->next=0;
        insert_irc_command_hook(hooks, cmd_name, function_ptr);
    }
    else
    {
        insert_irc_command_hook(hooks, cmd_name, function_ptr);
    }
}
