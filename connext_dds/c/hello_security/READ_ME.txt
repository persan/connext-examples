==================================================
RTI Connext DDS Hello_security Example Application
==================================================

Welcome to Connext DDS!


Compiling this Example
======================
You must set the environment variable NDDSHOME to your Connext DDS
installation directory.

To build this example on a Windows platform, open the appropriate solution
file for your version of Microsoft Visual Studio in the win32 directory. Select
from the configuration pull-down menu: Debug, Release, Debug DLL, or Release DLL
where "DLL" is for dynamic linking.

To build this example for a QNX platform, you must set the environment variables QNX_HOST
and QNX_TARGET. For example:

setenv QNX_BASE /opt/qnx660
setenv QNX_HOST ${QNX_BASE}/host/linux/x86
setenv QNX_TARGET ${QNX_BASE}/target/qnx6

To build this example on a UNIX-based system, type the following in a command
shell:

  > make -f make/makefile_HelloWorld_<architecture>

If using Certicom Security Builder Engine, you cannot use the ecdsa-ecdh shared
secret algorithm together with static linking. If you want to use ecdsa-ecdh,
you must use dynamic linking. Aside from that, all combinations of
static/dynamic libraries and release/debug libraries are supported. Dynamic
uses the QoS profile for specifying the security plugin, and static uses code
for that. Static/release is the default.
To use dynamic, run:

 > make -f make/makefile_HelloWorld_<architecture> SHAREDLIB=1

To use debug, run:

 > make -f make/makefile_HelloWorld_<architecture> DEBUG=1

If you want to compile the example using WolfSSL, you must modify your makefile
so that it includes the WolfSSL library. First, add the -lwolfssl linker
flag (look for the LIBS variable in the makefile). Secondly, set the
RTI_OPENSSLHOME environment variable to point to
$NDDSHOME/third_party/wolfssl-<version>. You can then run the make command as
usual.

Running this Example
====================

Linux-based
-----------
If using dynamic libraries, your LD_LIBRARY_PATH must include
$NDDSHOME/lib/<architecture>.
You must also include the path to your crypto library. If you are compiling
against the OpenSSL-based Security Plugins, your LD_LIBRARY_PATH must include
$NDDSHOME/third_party/openssl-<version>/<architecture>/<release or debug>/lib
(location of libcrypto.so).
If you are compiling against the WolfSSL-based Security Plugins, your
LD_LIBRARY_PATH must include $NDDSHOME/third_party/wolfssl-<version>/<architecture>/<release or debug>/lib
(location of libwolfssl.so).

If using Certicom Security Builder Engine for QNX, your LD_LIBRARY_PATH must include
$NDDSHOME/third_party/openssl-<version>/<architecture>/release/lib/:$CERTICOM_SBENGINEHOME/tools/sb/sb-$CERTICOMOS/lib/:$CERTICOM_SBENGINEHOME/lib/$CERTICOMOS.

To run this example, type the following in two different command shells, either
on the same machine or on different machines:

  > objs/<architecture>/HelloWorld_subscriber
  > objs/<architecture>/HelloWorld_publisher

Windows
-------
If using dynamic libraries, your PATH must include
%NDDSHOME%\lib\<architecture> and %NDDSHOME%\third_party\openssl-<version>\<architecture>\<release or debug>\bin
(location of libcrypto DLL).

To run this example, type the following in two different command shells, either
on the same machine or on different machines:

  > objs\<architecture>\HelloWorld_subscriber.exe
  > objs\<architecture>\HelloWorld_publisher.exe

Accepted parameters
-------------------
This example is a modified version of an rtiddsgen generated HelloWorld application.
It has been modified to use security profiles. The first two parameters are the
domain ID and sample count as in the hello_world example.
This example uses the "ecdsa"(*) algorithm suite by default. To run this example
using the "rsa"(**) algorithm suite, add a third command-line argument: "rsa".

* The "ecdsa" algorithm suite consists of ECDSA+P256+SHA256 (digital signature
  for identity trust chain and authentication) and ECDHE-CEUM+P256 (key establishment).
** The "rsa" algorithm suite consists of RSASSA-PKCS1-V1_5+2048+SHA256 (digital
  signature for identity trust chain), RSASSA-PSS-MGF1SHA256+2048+SHA256
  (digital signature for authentication) and ECDHE-CEUM+P256 (key establishment).

Troubleshooting this Example
============================
If you see the following error:

Cryptography_encrypt:error:0607B083:lib(6):func(123):reason(131)

you are likely linking against an older version of OpenSSL. You need version
1.0.1c or later.

For more information, please consult the "RTI Security Plugins Getting Started
Guide".
