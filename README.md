<<<<<<< Updated upstream
# Ackur&#0153;
Cross platform process VM SDK with dynamic grammar scripting and libraries for BitInteger, BigFloat, SHA3, AES256, PublicKey, BTree, Networking, Threads, Compression, Conditions, Loops, and File IO.

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
   - Compiled with Debian 7.9 but should work on other Linux variants.

Mac, iPhone, Android
- Work in progress

Running Sample Console App
- Copy the binary to some location on your HDD and run.
- First time will take a minute or two to start - identities and encryption keys are being created.
- Two items will be created:
    * "config.ackur" file is an Ackur DB containing the identities and keys. 
    * "home" folder will contain a subfolder for each user. Directory navigation is restricted to the user home (user GUID folder)
- Default user is "console". The user GUID for "console" will be different on each instance of the tool.

Grammar
- The engine first initializes a syntax that can be used to redefine the language syntax. On the console, enter "$grammar" to view the system syntax.
- A user defined syntax must be provided. The SDK includes a DefaultGrammar function that will return a default grammar that can be passed into the tool using the SetGrammar command. Once set, the SDK will use that grammar to initialize any new script session (including sessions created for a listening network connection). 

SDK
- AckurScript
   - Interface to the scripting engine.
   - This is only needed if you plan on using the scripting engine. Both async and sync commands supported.
   - The other objects can be used independently from the scripting engine.
- AckurBigInteger
   - Unlimited precision integer math.
- AckurBigFloat
   - Unlimited precision fixed and float math. 
- AckurAES256
   - aes256 encryption.
- AckurSHA3
   - SHA3 hash generation.
- AckurPrime
   - Prime number generation.
- AckurPublicKey
   - Public/private key encryption.
- AckurCompress
   - Based on Zlib, but deviates slightly by adding a header to the compressed data that is used when decompressing.
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
   - Interface needs to be reworked before exposing the library. At this point, the DB is only accessible through the scripting engine.
- User Definable Scripting Libraries
   - The user defined syntax associates rule options with libraries - but only the SDK pre-define libraries at this point.
- Ackur Networking Protocol
   - The protocol that Ackur uses to securely communicate between devices/instances is only accessible through the scripting engine.
- Script Raw Results
   - Routines to parse the raw results from a script call have not yet been exposed. So the script results are currently converted to text before returning. Sometime in the future there will be an option of receiving a token and a response message. A script is able to concatenate onto the response message during execution, but will return only a single token.
- Graphics
   - The SDK does not include any graphics libraries at this time. This will come eventually, and once supported will be cross platform within the scripting environment. 

Example User Syntax
- See http://ackur.com for an example user syntax for setting up a simple calculator supporting entries like "45 + (32 - 30)" and "(2 * 564.45) / 45.2".
=======
# Ackur
Cross platform process VM SDK with dynamic grammar scripting and libraries for BitInteger, BigFloat, SHA3, AES256, PublicKey, BTree, Networking, Threads, Compression, Conditions, Loops, and File IO.

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
   - Compiled with Debian 7.9 but should work on other Linux variants.

Mac, iPhone, Android
- Work in progress

Running Sample Console App
- Copy the binary to some location on your HDD and run.
- First time will take a minute or two to start - identities and encryption keys are being created.
- Two items will be created:
    * "config.ackur" file is an Ackur DB containing the identities and keys. 
    * "home" folder will contain a subfolder for each user. Directory navigation is restricted to the user home (user GUID folder)
- Default user is "console". The user GUID for "console" will be different on each instance of the tool.

Grammar
- The engine first initializes a syntax that can be used to redefine the language syntax. On the console, enter "$grammar" to view the system syntax.
- A user defined syntax must be provided. The SDK includes a DefaultGrammar function that will return a default grammar that can be passed into the tool using the SetGrammar command. Once set, the SDK will use that grammar to initialize any new script session (including sessions created for a listening network connection). 

SDK
- AckurScript
   - Interface to the scripting engine.
   - This is only needed if you plan on using the scripting engine. Both async and sync commands supported.
   - The other objects can be used independently from the scripting engine.
- AckurBigInteger
   - Unlimited precision integer math.
- AckurBigFloat
   - Unlimited precision fixed and float math. 
- AckurAES256
   - aes256 encryption.
- AckurSHA3
   - SHA3 hash generation.
- AckurPrime
   - Prime number generation.
- AckurPublicKey
   - Public/private key encryption.
- AckurCompress
   - Based on Zlib, but deviates slightly by adding a header to the compressed data that is used when decompressing.
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
   - Interface needs to be reworked before exposing the library. At this point, the DB is only accessible through the scripting engine.
- User Definable Scripting Libraries
   - The user defined syntax associates rule options with libraries - but only the SDK pre-define libraries at this point.
- Ackur Networking Protocol
   - The protocol that Ackur uses to securely communicate between devices/instances is only accessible through the scripting engine.
- Script Raw Results
   - Routines to parse the raw results from a script call have not yet been exposed. So the script results are currently converted to text before returning. Sometime in the future there will be an option of receiving a token and a response message. A script is able to concatenate onto the response message during execution, but will return only a single token.
- Graphics
   - The SDK does not include any graphics libraries at this time. This will come eventually, and once supported will be cross platform within the scripting environment. 

Example User Syntax
- See http://ackur.com for an example user syntax for setting up a simple calculator supporting entries like "45 + (32 - 30)" and "(2 * 564.45) / 45.2".
>>>>>>> Stashed changes
