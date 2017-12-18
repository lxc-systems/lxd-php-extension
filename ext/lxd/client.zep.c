
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Lxd_Client) {

	ZEPHIR_REGISTER_CLASS(Lxd, Client, lxd, client, lxd_client_method_entry, 0);

	zend_declare_property_null(lxd_client_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lxd_client_ce, SL("curl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lxd_client_ce, SL("certificate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lxd_Client, __construct) {

	zval *config_param = NULL, __$null, _0, _2, _5, _3$$3, _4$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6;
	zval config, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(&config);
		array_init(&config);
	} else {
		zephir_get_arrval(&config, config_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 6, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("url"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("ip"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("port"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("secret"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("endpoint"), &__$null, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_1, SL("version"), SL("1.0"));
	zephir_fast_array_merge(&_0, &_1, &config TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("config"), &_0);
	zephir_read_property(&_2, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string(&_2, SL("certificate_path")))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "certificate_path");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, ".certificates");
		zephir_update_property_array(this_ptr, SL("config"), &_3$$3, &_4$$3 TSRMLS_CC);
	}
	zephir_read_property(&_5, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string(&_5, SL("timeout")))) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "timeout");
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_LONG(&_7$$4, 10);
		zephir_update_property_array(this_ptr, SL("config"), &_6$$4, &_7$$4 TSRMLS_CC);
	} else {
		zephir_read_property(&_8$$5, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_9$$5, &_8$$5, SL("timeout"), PH_NOISY | PH_READONLY, "lxd/client.zep", 32 TSRMLS_CC);
		if (!(zephir_is_numeric(&_9$$5))) {
			ZEPHIR_INIT_VAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "timeout");
			ZEPHIR_INIT_VAR(&_11$$6);
			ZVAL_LONG(&_11$$6, 10);
			zephir_update_property_array(this_ptr, SL("config"), &_10$$6, &_11$$6 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Lxd_Client, connect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *url_param = NULL, *secret_param = NULL, ip, port, ping, _0, _2, _3, _4, _5, _6, _7, _8, _9, _14, _15, _10$$5, _11$$5, _12$$5, _13$$5;
	zval url, secret;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&secret);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&ping);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url_param, &secret_param);

	if (!url_param) {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_STRING(&url, "");
	} else {
		zephir_get_strval(&url, url_param);
	}
	if (!secret_param) {
		ZEPHIR_INIT_VAR(&secret);
		ZVAL_STRING(&secret, "");
	} else {
		zephir_get_strval(&secret, secret_param);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&ip, "parse_url", &_1, 3, &url, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&port, "parse_url", &_1, 3, &url, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&port)) {
		ZEPHIR_INIT_NVAR(&port);
		ZVAL_LONG(&port, 8443);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "url");
	zephir_update_property_array(this_ptr, SL("config"), &_2, &url TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "ip");
	zephir_update_property_array(this_ptr, SL("config"), &_3, &ip TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "port");
	zephir_update_property_array(this_ptr, SL("config"), &_4, &port TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "secret");
	zephir_update_property_array(this_ptr, SL("config"), &_5, &secret TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_6, &_0, SL("timeout"), PH_NOISY | PH_READONLY, "lxd/client.zep", 53 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&ping, this_ptr, "connectable", NULL, 0, &ip, &port, &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&ping, -1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Could not connect.", "lxd/client.zep", 56);
		return;
	}
	zephir_read_property(&_7, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_8, &_7, SL("certificate_path"), PH_NOISY | PH_READONLY, "lxd/client.zep", 60 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_VSVS(&_9, &_8, "/", &ip, "/client.pem");
	if (!((zephir_file_exists(&_9 TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_10$$5);
		object_init_ex(&_10$$5, lxd_lib_certificate_ce);
		zephir_read_property(&_11$$5, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_12$$5, &_11$$5, SL("certificate_path"), PH_NOISY | PH_READONLY, "lxd/client.zep", 62 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 4, &_12$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("certificate"), &_10$$5);
		zephir_read_property(&_13$$5, this_ptr, SL("certificate"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_13$$5, "generate", NULL, 0, &ip);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_14);
	object_init_ex(&_14, lxd_lib_curl_ce);
	zephir_read_property(&_15, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_14, "__construct", NULL, 5, &_15);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("curl"), &_14);
	RETURN_THIS();

}

/**
 * Check connection to server
 *
 * @param string ip
 * @param int port
 * @param int timeout
 *
 * @return int - response time -1 for error
 */
PHP_METHOD(Lxd_Client, connectable) {

	unsigned long start = 0, stop = 0;
	zend_long port, timeout, ZEPHIR_LAST_CALL_STATUS;
	zval *ip_param = NULL, *port_param = NULL, *timeout_param = NULL, __$true, time, sock, _0, _1, _2, _3, _4, _5, _6$$5, _7$$5, _8$$5;
	zval ip;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ip);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&sock);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &ip_param, &port_param, &timeout_param);

	zephir_get_strval(&ip, ip_param);
	if (!port_param) {
		port = 8443;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!timeout_param) {
		timeout = 10;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&ip, "")) {
		RETURN_MM_LONG(-1);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true TSRMLS_CC);
	start = zephir_get_intval(&_0);
	ZVAL_LONG(&_1, port);
	ZVAL_NULL(&_2);
	ZVAL_NULL(&_3);
	ZVAL_LONG(&_4, timeout);
	ZEPHIR_MAKE_REF(&_2);
	ZEPHIR_MAKE_REF(&_3);
	ZEPHIR_CALL_FUNCTION(&sock, "fsockopen", NULL, 6, &ip, &_1, &_2, &_3, &_4);
	ZEPHIR_UNREF(&_2);
	ZEPHIR_UNREF(&_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_microtime(&_5, &__$true TSRMLS_CC);
	stop = zephir_get_intval(&_5);
	ZEPHIR_INIT_VAR(&time);
	ZVAL_LONG(&time, 0);
	ZEPHIR_INIT_NVAR(&time);
	if (!zephir_is_true(&sock)) {
		ZVAL_LONG(&time, -1);
	} else {
		zephir_fclose(&sock TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_LONG(&_7$$5, ((((stop - start)) * 1000)));
		ZVAL_LONG(&_8$$5, 2);
		zephir_round(&_6$$5, &_7$$5, &_8$$5, NULL TSRMLS_CC);
		ZVAL_DOUBLE(&time, zephir_get_doubleval(&_6$$5));
	}
	RETURN_CCTOR(&time);

}

/**
 *
 */
PHP_METHOD(Lxd_Client, __get) {

	zend_class_entry *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *endpoint_param = NULL, _0, _1$$3, _3$$3, _4$$3, _5$$4;
	zval endpoint, ns, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&endpoint);
	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &endpoint_param);

	zephir_get_strval(&endpoint, endpoint_param);


	ZEPHIR_INIT_VAR(&ns);
	ZEPHIR_CONCAT_SSV(&ns, "Lxd", "\\Endpoints\\", &endpoint);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "endpoint");
	zephir_update_property_array(this_ptr, SL("config"), &_0, &endpoint TSRMLS_CC);
	if (zephir_class_exists(&ns, 1 TSRMLS_CC)) {
		zephir_fetch_safe_class(&_1$$3, &ns);
		_2$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1$$3), Z_STRLEN_P(&_1$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(return_value, _2$$3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			zephir_read_property(&_3$$3, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_4$$3, this_ptr, SL("curl"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_3$$3, &_4$$3);
			zephir_check_call_status();
		}
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SVS(&_6$$4, "Endpoint ", &ns, ", not implemented.");
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 2, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "lxd/client.zep", 118 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

