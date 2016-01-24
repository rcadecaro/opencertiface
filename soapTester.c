/* soapTester.c
   Generated by gSOAP 2.8.21 from functions.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/
/*
   Stand-alone server auto-test code:
   Takes request from standard input or over TCP/IP socket and returns
response to standard output or socket

   Compile:
   cc soapTester.c soapServer.c soapC.c stdsoap2.c

   Command line usage with redirect over stdin/out:
   > ./a.out < SomeTest.req.xml
   > ./a.out 12288 < SomeTest.req.xml
     Note: 12288 = SOAP_XML_INDENT | SOAP_XML_STRICT (see codes in stdsoap2.h)
   Command line usage to start server at port 8080:
   > a.out 12288 8080
*/

#include "opencertiface.nsmap"

#ifndef SOAP_DEFMAIN
# define SOAP_DEFMAIN main	/* redefine to use your own main() */
#endif

int SOAP_DEFMAIN(int argc, char **argv)
{
	struct soap *soap = soap_new1(argc > 1 ? atoi(argv[1]) : 0);
	if (argc <= 2)
		return soap_serve(soap);
	if (soap_valid_socket(soap_bind(soap, NULL, atoi(argv[2]), 100)))
		while (soap_valid_socket(soap_accept(soap)))
		{	soap_serve(soap);
			soap_destroy(soap);
			soap_end(soap);
		}
	soap_free(soap);
	return 0;
}


/** Auto-test server operation ns__ping */
int ns__ping(struct soap *soap, char *stringHello, char **result)
{	/* Echo request-response parameter */
	*result = stringHello;
	return SOAP_OK;
}


/** Auto-test server operation ns__verifyImg */
int ns__verifyImg(struct soap *soap, struct xsd__base64Binary *template1, struct xsd__base64Binary *template2, char *id, char **result)
{	
	return SOAP_OK;
}
