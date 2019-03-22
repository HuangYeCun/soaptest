/* soaptestProxy.cpp
   Generated by gSOAP 2.8.82 for ../test.h

gSOAP XML Web services tools
Copyright (C) 2000-2018, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soaptestProxy.h"

testProxy::testProxy() : soap(SOAP_IO_DEFAULT)
{	testProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

testProxy::testProxy(const testProxy& rhs)
{	soap_copy_context(this, &rhs);
	this->soap_endpoint = rhs.soap_endpoint;
}

testProxy::testProxy(const struct soap &_soap) : soap(_soap)
{ }

testProxy::testProxy(const struct soap &_soap, const char *soap_endpoint_url) : soap(_soap)
{
	soap_endpoint = soap_endpoint_url;
}

testProxy::testProxy(const char *soap_endpoint_url) : soap(SOAP_IO_DEFAULT)
{	testProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = soap_endpoint_url;
}

testProxy::testProxy(soap_mode iomode) : soap(iomode)
{	testProxy_init(iomode, iomode);
}

testProxy::testProxy(const char *soap_endpoint_url, soap_mode iomode) : soap(iomode)
{	testProxy_init(iomode, iomode);
	soap_endpoint = soap_endpoint_url;
}

testProxy::testProxy(soap_mode imode, soap_mode omode) : soap(imode, omode)
{	testProxy_init(imode, omode);
}

testProxy::~testProxy()
{
	this->destroy();
}

void testProxy::testProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] = {
        { "SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL },
        { "SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL },
        { "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL },
        { "xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL },
        { "ns", "urn:test", NULL, NULL },
        { NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this, namespaces);
}

testProxy *testProxy::copy()
{	testProxy *dup = SOAP_NEW_UNMANAGED(testProxy(*(struct soap*)this));
	return dup;
}

testProxy& testProxy::operator=(const testProxy& rhs)
{	soap_done(this);
	soap_copy_context(this, &rhs);
	this->soap_endpoint = rhs.soap_endpoint;
	return *this;
}

void testProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void testProxy::reset()
{	this->destroy();
	soap_done(this);
	soap_initialize(this);
	testProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void testProxy::soap_noheader()
{	this->header = NULL;
}

::SOAP_ENV__Header *testProxy::soap_header()
{	return this->header;
}

::SOAP_ENV__Fault *testProxy::soap_fault()
{	return this->fault;
}

const char *testProxy::soap_fault_subcode()
{	return ::soap_fault_subcode(this);
}

const char *testProxy::soap_fault_string()
{	return ::soap_fault_string(this);
}

const char *testProxy::soap_fault_detail()
{	return ::soap_fault_detail(this);
}

int testProxy::soap_close_socket()
{	return ::soap_closesock(this);
}

int testProxy::soap_force_close_socket()
{	return ::soap_force_closesock(this);
}

void testProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void testProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *testProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int testProxy::send_test(const char *soap_endpoint_url, const char *soap_action)
{
	struct soap *soap = this;
	struct ns__test soap_tmp_ns__test;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost/test.cgi";
	soap_begin(soap);
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_ns__test(soap, &soap_tmp_ns__test);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__test(soap, &soap_tmp_ns__test, "ns:test", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__test(soap, &soap_tmp_ns__test, "ns:test", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int testProxy::recv_test(std::string &response)
{
	struct soap *soap = this;
	struct ns__testResponse *soap_tmp_ns__testResponse;
	soap_default_std__string(soap, &response);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__testResponse = soap_get_ns__testResponse(soap, NULL, "ns:testResponse", NULL);
	if (!soap_tmp_ns__testResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	response = soap_tmp_ns__testResponse->response;
	return soap_closesock(soap);
}
/* End of client proxy code */