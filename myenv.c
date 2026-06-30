/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif

extern char **environ;
int main(int argc, char *argv[]) {
  if(argc==1){
    for(int i = 0; environ[i]!=NULL; i++){
      printf("%s\n",environ[i]);
    }
  }
  else{
    for(int j = 1; j < argc; j++){
      if(putenv(argv[j])==-1){
        execvp(argv[j], &argv[j]);
        perror(argv[j]);
        return 1;
      }
    }
    for(int k = 0; environ[k]!=NULL; k++){
      printf("%s\n",environ[k]);
    }
  }
  return 0;
}

/* 実行例

ここに実行例を書く
$ make
cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c

$ ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--  1 yoshikawayuuma  staff     132  6月 29 22:23 Makefile
-rwxr-xr-x  1 yoshikawayuuma  staff   33736  6月 29 22:49 myenv
-rw-r--r--  1 yoshikawayuuma  staff     701  6月 29 22:49 myenv.c
-rwxr-xr-x  1 yoshikawayuuma  staff     216  6月 29 22:23 myputenv.c
-rw-r--r--  1 yoshikawayuuma  staff      93  6月 29 22:23 myputenv.h
-rw-r--r--  1 yoshikawayuuma  staff    1268  6月 29 22:23 README.md
-rw-r--r--  1 yoshikawayuuma  staff  139098  6月 29 22:23 README.pdf

$ ./myenv LC_TIME=en_US.UTF-8 TZ=Russia date
Tue Jun 30 02:53:03 UTC 2026

$ ./myenv X=Y LANG=en_UK.UTF-8
TMPDIR=/var/folders/tw/bc_wj80x41jg4d9qqnr7phkc0000gn/T/
__CFBundleIdentifier=com.apple.Terminal
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/var/run/com.apple.launchd.vTY7m7e6XL/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
COLORTERM=truecolor
OSLogRateLimit=64
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=F045CC58-C690-4BDD-AE16-B3A2B296CDB4
SHELL=/bin/zsh
HOME=/Users/yoshikawayuuma
LOGNAME=yoshikawayuuma
USER=yoshikawayuuma
PATH=/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:
/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/
local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/
bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/
appleinternal/bin:/pkg/env/global/bin:/opt/homebrew/bin
SHLVL=1
PWD=/Users/yoshikawayuuma/Syspro2/kadai09-i23yosikawa
OLDPWD=/Users/yoshikawayuuma/Syspro2
LANG=en_UK.UTF-8
_=/Users/yoshikawayuuma/Syspro2/kadai09-i23yosikawa/./myenv
X=Y

$ ./myenv
TMPDIR=/var/folders/tw/bc_wj80x41jg4d9qqnr7phkc0000gn/T/
__CFBundleIdentifier=com.apple.Terminal
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/var/run/com.apple.launchd.vTY7m7e6XL/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
COLORTERM=truecolor
OSLogRateLimit=64
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=F045CC58-C690-4BDD-AE16-B3A2B296CDB4
SHELL=/bin/zsh
HOME=/Users/yoshikawayuuma
LOGNAME=yoshikawayuuma
USER=yoshikawayuuma
PATH=/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:
/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/
local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/
bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/
appleinternal/bin:/pkg/env/global/bin:/opt/homebrew/bin
SHLVL=1
PWD=/Users/yoshikawayuuma/Syspro2/kadai09-i23yosikawa
OLDPWD=/Users/yoshikawayuuma/Syspro2
LANG=ja_JP.UTF-8
_=/Users/yoshikawayuuma/Syspro2/kadai09-i23yosikawa/./myenv

$ ./myenv TZ=Russia aaa
aaa: No such file or directory


*/
