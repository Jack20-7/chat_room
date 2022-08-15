#!/bin/bash

#重新生成bin目录下的可执行文件和bin/module/下面的动态链接库

if [ ! -d bin/module ];then
    mkdir bin/module
else
    unlink bin/chat_room
    unlink bin/module/libchat_room.so
fi

cp JKYi/bin/test_application bin/chat_room
cp lib/libchat_room.so bin/module/
