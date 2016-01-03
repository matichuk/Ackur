# Ackur
Cross platform scripting SDK with libraries

Windows
- AckurLib folder
   - Static libraries + include files
- AckurConsole.cpp
   - Sample for a command line shell.
- AckurConsole project files
   - Visual Studio project files
- bin folder
   - Precompiled binary.
   - Requires Win8 or higher.

Linux
- AckurLib folder
   - Static libraries + include files
- main.cpp
   - Sample for a command line shell
- build.sh
   - Batch for building command line shell app. 
   - May need to first run "chmod a+x build.sh".
- bin folder
   - Precompiled binary.
   - Compiled with Debian 7.9 but should work on other linux variants.

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
- AckurScript
   - Interface to the scripting engine.
   - This is only needed if you plan on using the scripting engine. Both async and sync commands supported.
- AckurBigInteger
   - Unlimited precision integer math.
- AckurBigFloat
   - Unlimited precision fixed and float math. 
- AckurAES256
   - aes256 encryiption.
- AckurSHA3
   - SHA3 hash generation.
- AckurPrime
   - Prime number generation.
- AckurPublicKey
   - Public/private key encryption.
- AckurZip
   - Zlib type compression. 
   - Deviates slightly by adding a header to the compressed data that is used when decompressing.
- AckurFileIO
   - File I/O. 
- AckurBTree
   - Can operate on a file or memory.
- AckurBlockFile
   - Uses a BTree to store compressed file blocks. Enables random I/O on a compressed (and/or encrypted) file.
   - (Note - needs to be updated to properly implement caching, currently leaves all accessed blocks in memory)
- AckurNet
   - IPv4 and IPv6 networking.
- AckurThread
   - Threads
   - Critical with trigger message support
- AckurValue
   - Ackur data objects.

Not Exposed in SDK
- DB
   - Interface needs to be reworked before exposing the library. At this point, the DB is only accessable through the scripting engine.
- Scripting libraries
   - The user defined syntax associates rule options with libraries - but only the SDK pre-define libraries at this point.
- Ackur Networking Protocol
   - The protocol that Ackur uses to securely communicate between devices/instances is only accessable through the scripting engine.

Example User Syntax
- See http://ackur.com for an example user syntax for setting up a simple calculator supporting entries like "45 + (32 - 30)" and "(2 * 564.45) / 45.2".
