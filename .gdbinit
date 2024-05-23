# disable messages like "[New Thread ...]" and "[Thread ... exited]"
set print thread-events off
# disable messages like "[Detaching after {v}fork from child process ...]"
set print inferior-events off

set $_exitcode = -999
define hook-stop
    # quit if program finished or received SIGSEGV after program finish (WSL bug)
    # 0x00007fffe972d7f6 in ?? () from /usr/lib/wsl/drivers/nvmdi.inf_amd64_af623d743ca2092d/libnvwgf2umx.so
    if $_exitcode != -999
        echo "exit: _exitcode="
        print $_exitcode
        set confirm off
        quit
    end
    if $_exitcode == -999 && $pc == 0x7fffe972d7f6
        echo "exit=SEGV"
        set confirm off
        quit
    end
end

run
