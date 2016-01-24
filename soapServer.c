/* soapServer.c
   Generated by gSOAP 2.8.21 from functions.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapServer.c ver 2.8.21 2016-01-21 05:33:57 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns:ping"))
		return soap_serve_ns__ping(soap);
	if (!soap_match_tag(soap, soap->tag, "ns:verifyImg"))
		return soap_serve_ns__verifyImg(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__ping(struct soap *soap)
{	struct ns__ping soap_tmp_ns__ping;
	struct ns__pingResponse soap_tmp_ns__pingResponse;
	char * soap_tmp_xsd__string;
	soap_default_ns__pingResponse(soap, &soap_tmp_ns__pingResponse);
	soap_tmp_xsd__string = NULL;
	soap_tmp_ns__pingResponse.result = &soap_tmp_xsd__string;
	soap_default_ns__ping(soap, &soap_tmp_ns__ping);
	if (!soap_get_ns__ping(soap, &soap_tmp_ns__ping, "ns:ping", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns__ping(soap, soap_tmp_ns__ping.stringHello, soap_tmp_ns__pingResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__pingResponse(soap, &soap_tmp_ns__pingResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__pingResponse(soap, &soap_tmp_ns__pingResponse, "ns:pingResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__pingResponse(soap, &soap_tmp_ns__pingResponse, "ns:pingResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__verifyImg(struct soap *soap)
{	struct ns__verifyImg soap_tmp_ns__verifyImg;
	struct ns__verifyImgResponse soap_tmp_ns__verifyImgResponse;
	char * soap_tmp_xsd__string;
	soap_default_ns__verifyImgResponse(soap, &soap_tmp_ns__verifyImgResponse);
	soap_tmp_xsd__string = NULL;
	soap_tmp_ns__verifyImgResponse.result = &soap_tmp_xsd__string;
	soap_default_ns__verifyImg(soap, &soap_tmp_ns__verifyImg);
	if (!soap_get_ns__verifyImg(soap, &soap_tmp_ns__verifyImg, "ns:verifyImg", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns__verifyImg(soap, soap_tmp_ns__verifyImg.template1, soap_tmp_ns__verifyImg.template2, soap_tmp_ns__verifyImg.id, soap_tmp_ns__verifyImgResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__verifyImgResponse(soap, &soap_tmp_ns__verifyImgResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__verifyImgResponse(soap, &soap_tmp_ns__verifyImgResponse, "ns:verifyImgResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__verifyImgResponse(soap, &soap_tmp_ns__verifyImgResponse, "ns:verifyImgResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.c */
