/**
 * test.c
 * Small Hello World! example
 * to compile with gcc, run the following command
 * gcc -o test test.c -lulfius
 */
#include <stdio.h>
#include <ulfius.h>

#define PORT 9000

/**
 * Callback function for the web application on /helloworld url call
 */
int callback_hello_world (const struct _u_request * request, struct _u_response * response, void * user_data) {
  ulfius_set_string_body_response(response, 200, "Hello World!");
  return U_CALLBACK_CONTINUE;
}

/**
 * main function
 */
int main(void) {
  struct _u_instance instance;

  // Initialize instance with the port number
  if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK) {
    fprintf(stderr, "Error ulfius_init_instance, abort\n");
    return(1);
  }

  // Endpoint list declaration
  ulfius_add_endpoint_by_val(&instance, "GET", "/helloworld", NULL, 0, &callback_hello_world, NULL);

  // Start the framework
  if (ulfius_start_secure_framework(&instance, "-----BEGIN PRIVATE KEY-----\n"
"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\n"
"2wWsN+xYcSgrb8Ty8Yk6Lu5J9cKCpA==\n"
"-----END PRIVATE KEY-----", "-----BEGIN CERTIFICATE-----\n"
"MIIF1zCCA7+gAwIBAgIUGtJIis48Fkb3/qI4yW5+Rb2DOqEwDQYJKoZIhvcNAQEL\n"
"BQAwezELMAkGA1UEBhMCQlIxCzAJBgNVBAgMAlBCMQswCQYDVQQHDAJDRzELMAkG\n"
"A1UECgwCVlQxDzANBgNVBAMMBlZpcnR1czE0MDIGCSqGSIb3DQEJARYldmxhZHdv\n"
"Z3Vlci5iZXplcnJhQHZpcnR1cy51ZmNnLmVkdS5icjAeFw0yMTAzMjUyMDEzNDVa\n"
"Fw0yMjAzMjUyMDEzNDVaMHsxCzAJBgNVBAYTAkJSMQswCQYDVQQIDAJQQjELMAkG\n"
"A1UEBwwCQ0cxCzAJBgNVBAoMAlZUMQ8wDQYDVQQDDAZWaXJ0dXMxNDAyBgkqhkiG\n"
"9w0BCQEWJXZsYWR3b2d1ZXIuYmV6ZXJyYUB2aXJ0dXMudWZjZy5lZHUuYnIwggIi\n"
"MA0GCSqGSIb3DQEBAQUAA4ICDwAwggIKAoICAQDBf1rZEqlVXFwBcMxwBAEgKKJQ\n"
"RM4KIM55bhxafvc68HDnjcxQZF6+SiO757d/mVWXommCCIckmKD2nJBtM3y6i1Ez\n"
"GzGSlZFJ5JuJuIf6wC6o5EqvWfEFjQNsFbPWFjKoXT0pITAv6ySz8zyXpsFJF34P\n"
"Nf7a5z8B9TLEauEjBEFl/e/fi3uMadG/PooALMQQeuhCM6zGUQcAgNzVbGzzmEHC\n"
"KFuav8dxTt4O4KI0yQJ441FB8CTJa/ruWDOYXrsaSt8th9FQkVsDOpTGs8a4V5Th\n"
"92LwnZldz1n4P+6FUrse1kvvIYKYJXKo8UJCB11KaMiWBYEGtll82SvY6llwTNxy\n"
"NpF4o7ko0PW/OzSj6djv+KfemLn4nwjpYkrjLIGNmOprjVCYslHYsoRyKE7h5kpE\n"
"6mTPqzCs0TrGcI3LhBoCqubmEEN8wUM1Jok0y+OM3VrzzupZIO62Ef+jW4gC/J2a\n"
"tbzBo0VWo4zttVTVsfwHxdeUEBxAEQKVHsdfGJt7HbQ+01dc6wZ1apZIcnd+dBQD\n"
"wfOU7TOr3fNq+enR/qCSA8JWFDOruCMPngO0LVWnn0yCvBRkFinzuH/GSBaBmNtV\n"
"qoqYnC8VO9avwkwt7IVAncZAWTYhxpFuCqAdYOvcC7pEWKUEsDuwfCdVPcyeX09a\n"
"ZJN+0+N1Rg6Wzx9aoQIDAQABo1MwUTAdBgNVHQ4EFgQUm7M0BlB81hnWOT3kN7Yz\n"
"bwE8uQwwHwYDVR0jBBgwFoAUm7M0BlB81hnWOT3kN7YzbwE8uQwwDwYDVR0TAQH/\n"
"BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAgEAuQn4A94+aZvskPd0lavV8RI79T4i\n"
"WXZajH7X8aKVoGk+PGwsNIl4zACwLrqRCUTmlWNIqu/tvFBu7NY8dJ7/8WtyoP0a\n"
"eklw/GpdFDAL2BEKkjL7xkROnwFj3OZOekR1j4FtgLK+sWFaxuVRTiK5CF66shI6\n"
"92LDY2a8fNr5VI/P0XcMYJrBcYL0g+hGlfuSdQLL88hUgLViM+giouwkEBBbEE0U\n"
"0Wr1tQVliMf5bfPepRJ9LuIpVQGdOfZ8Sfw2PaxeWFIyzjSSoHF2jucsi5IZouxo\n"
"abSZA3z4NS3KluryoyUgCRteLCsZHJGpKafaClw0Qp0U1MiJOmXOuTppZANLUyxV\n"
"HytBJzgcqfmF7C4sIKi6Mt8DLhNTiEQdn3eSVIpZvhB4dDY8Z7JBv+l/p04y6h/P\n"
"KpJSpOw2QBaJCobHb8zizgdrUcfVtil+idlYnOKLvvp4PoQB6kueowb+46s93Ms1\n"
"3WhAtC3bc7xRnGlMzVYgQ6+NBMGIty/rCAK+bCKsjhUEoEpDBmwK+an++VomRYJj\n"
"rawww/oveE6pMLt89zmQgl+xmr5MS+XqoVnumraw8pGAQMumcEcn+2PwUIjT8NqG\n"
"Ez4c9CI6JxFeFjn/Fc7A35qTLso/MNs6BnyEt7aTa4Pen6Esupy3616khaNfK41l\n"
"UVgvUOQUb8JapMM=\n"
"-----END CERTIFICATE-----") == U_OK) {
    printf("Start framework on port %d\n", instance.port);

    // Wait for the user to press <enter> on the console to quit the application
    getchar();
  } else {
    fprintf(stderr, "Error starting framework\n");
  }
  printf("End framework\n");

  ulfius_stop_framework(&instance);
  ulfius_clean_instance(&instance);

  return 0;
}
