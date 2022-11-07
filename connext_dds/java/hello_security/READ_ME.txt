==================================================
RTI Connext DDS Hello_security Example Application
==================================================

Welcome to Connext DDS.


Compiling this Example
----------------------
You must set the environment variable NDDSHOME to your Connext DDS
installation directory.

Before compiling, make sure that the desired version of javac compiler
is in your PATH environment variable.

To build this example on a Windows system, type the following in a 
command shell:

  > build

To build this example on a UNIX-based system, type the following in a 
command shell:

  > ./build.sh

To remove all the generated files (.class files), just delete the 'objs'
directory. 

On UNIX-based systems:
  > rm -Rf objs

On Windows systems:
  > RD /S /Q OBJS


Running this Example
--------------------
You must set the environment variable NDDSHOME to your Connext DDS installation
directory. You must also set RTI_EXAMPLE_ARCH to <architecture> 
(e.g., x64Linux2.6gcc4.4.5).

To run this example on a Windows system, you must type the following in two
different command shells, either on the same machine or on different machines:

  > runSub
  > runPub

To run this example on a UNIX-based system, you must type the following in two
different command shells, either on the same machine or on different machines:

  > ./runSub.sh
  > ./runPub.sh

Accepted parameters
-------------------
This example takes 3 parameters. The first two are the same as hello_world
and other examples; the domain ID and number of samples. The third parameter
allows you to specify the encryption algorithm. This example uses the
"ecdsa"(*) algorithm suite by default. To run this example using the "rsa"(**)
algorithm suite, add a third command-line argument: "rsa", following
the domain ID and number of samples. e.g. "0 0 rsa"

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

If you see the following error:

Authentication_get_certificate:failed to verify certificate

your certificates have likely expired and you need to regenerate them.
You can find the path to your certificates by looking in the dds.sec.auth.identity_ca
and dds.sec.auth.identity_certificate fields of the USER_QOS_PROFILES.xml.
The certificates in this example have a filename ending in Cert.pem.
When regenerating the certificates, follow the instructions in the
"RTI Security Plugins Getting Started Guide".

For more information, please consult the "RTI Security Plugins Getting Started
Guide".
