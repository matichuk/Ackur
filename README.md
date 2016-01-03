# Ackur
Cross platform scripting SDK with libraries

Windows
- AckurLib: static libraries + include files
- AckurConsole.cpp: sample for a command line shell
- AckurConsole project files: Visual Studio project
- bin: precompiled binary, requires Win8 or higher

Linux
- AckurLib: static libraries + include files
- main.cpp: sample for a command line shell
- build.sh: batch for building command line shell app. May need to first run "chmod a+x build.sh".
- bin: precompiled binary, compiled with Debian 7.9 but should work on other linux variants.

Mac, iPhone, Android
- Work in progress

Running Sample Console App
- Copy the binary to some location on your HDD and run.
- First time will take a minute or two to start - identies and ecryption keys are being created.
- Two items will be created:
    * "config.ackur" file is an Ackur DB containing the identies and keys. 
    * "home" folder will contain a subfolder for each user. Directory navigation is restricted to the user home (user GUID folder)
- Default user is "console". The user GUID for "console" will be different on each instance of the tool.

Grammar
- The engine first initializes a syntax that can be used to redefine the language syntax. On the console, enter "$grammar" to view the system syntax.
- If a user syntax is not provided to the tool, the tool will initialze with a default syntax. On the console, enter "grammar" to view the default user syntax.

SDK
- AckurLink: Used to initialize the engine. This is only needed if you plan on using the scripting engine. Both async and sync commands supported.
- AckurBigInteger: Library for unlimited precision integer math.
- AckurBigFloat: Library for unlimited precision fixed and float math. 
- AckurAES256: Library for aes256 encryiption.
- AckurSHA3: Library for SHA3 hash generation.
- AckurPrime: Library for prime number generation.
- AckurPublicKey: Library for public/private key encryption.
- AckurZip: Library for Zlib type compression. Deviates slightly by adding a header to the compressed data that is used when decompressing.
- AckurFileIO: Library for file I/O. 
- AckurCore: Library for B*Tree. 
- AckurNet: Library for IPv4 and IPv6 networking.
- AckurThread: Library for threads and critical
- AckurValue: Library for Ackur data objects.

Not Exposed in SDK
- Several base items are not yet exposed in the SDK.
- DB: Interface needs to be reworked before exposing the library. At this point, the DB is only accessable through the scripting engine.
- Scripting libraries: The user defined syntax associates rule options with libraries - but only the SDK pre-define libraries at this point.
- Ackur Networking Protocol: The protocol that Ackur uses to securely communicate between devices/instances is only accessable through the scripting engine.

Example User Syntax
- The following is an example user syntax for setting up a simple calculator supporting entries like "45 + (32 - 30)" and "(2 * 564.45) / 45.2".
    $[
    $token LP = $SYM("(");
    $token RP = $SYM(")");
    $token SUB = $SYM("-");
    $token ADD = $SYM("+");
    $token MUL = $SYM("*");
    $token DIV = $SYM("/");
    $rule literal
    = $STR {$item.literal($1)}
    | $INT {$item.literal($1)}
    | $FLOAT {$item.literal($1)}
    ;
    $rule item
    = LP <add> RP
    | <literal>
    ;
    $rule multiply
    = <item> MUL <multiply> {$compute.mul($1,$3)}
    | <item> DIV <multiply> {$compute.div($1,$3)}
    | <item>
    ;
    $rule add 
    = <multiply> ADD <multiply> {$compute.add($1,$3)}
    | <multiply> SUB <multiply> {$compute.sub($1,$3)}
    | <multiply>
    ;
    $rule commands
    = <add> $SYM(";") <commands>
    | <add> $SYM(";")
    | <add>
    | $SYM(";")
    ;
    $rule start
    = <commands>
    ;
    $]
    
