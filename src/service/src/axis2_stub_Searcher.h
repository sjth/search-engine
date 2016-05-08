

        /**
        * axis2_stub_Searcher.h
        *
        * This file was auto-generated from WSDL for "Searcher|http://searchengine" service
        * by the Apache Axis2/Java version: 1.6.2  Built on : Apr 17, 2012 (05:33:49 IST)
        */

        #include <stdio.h>
        #include <axiom.h>
        #include <axutil_utils.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>
        #include <axis2_stub.h>

       
         #include "adb_searchserve.h"
        
         #include "adb_searchserveResponse.h"
        

	#ifdef __cplusplus
	extern "C" {
	#endif

        /***************** function prototypes - for header file *************/
        /**
         * axis2_stub_create_Searcher
         * Create and return the stub with services populated
         * @param env Environment ( mandatory)
         * @param client_home Axis2/C home ( mandatory )
         * @param endpoint_uri Service endpoint uri( optional ) - if NULL default picked from WSDL used
         * @return Newly created stub object
         */
        axis2_stub_t* AXIS2_CALL
        axis2_stub_create_Searcher(const axutil_env_t *env,
                                        const axis2_char_t *client_home,
                                        const axis2_char_t *endpoint_uri);
        /**
         * axis2_stub_populate_services_for_Searcher
         * populate the svc in stub with the service and operations
         * @param stub The stub
         * @param env environment ( mandatory)
         */
        void AXIS2_CALL 
        axis2_stub_populate_services_for_Searcher( axis2_stub_t *stub, const axutil_env_t *env);
        /**
         * axis2_stub_get_endpoint_uri_of_Searcher
         * Return the endpoint URI picked from WSDL
         * @param env environment ( mandatory)
         * @return The endpoint picked from WSDL
         */
        axis2_char_t* AXIS2_CALL
        axis2_stub_get_endpoint_uri_of_Searcher(const axutil_env_t *env);


        
            /**
             * Auto generated function declaration
             * for "searchserve|http://searchengine" operation.
             * @param stub The stub (axis2_stub_t)
             * @param env environment ( mandatory)
             * @param _searchserve10 of the adb_searchserve_t*
             *
             * @return adb_searchserveResponse_t*
             */

            adb_searchserveResponse_t* AXIS2_CALL 
            axis2_stub_op_Searcher_searchserve( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_searchserve_t* _searchserve10);
          

        /**
         * Auto generated function for asynchronous invocations
         * for "searchserve|http://searchengine" operation.
         * @param stub The stub
         * @param env environment ( mandatory)
         * @param _searchserve10 of the adb_searchserve_t*
         * @param user_data user data to be accessed by the callbacks
         * @param on_complete callback to handle on complete
         * @param on_error callback to handle on error
         */


        void AXIS2_CALL
        axis2_stub_start_op_Searcher_searchserve( axis2_stub_t *stub, const axutil_env_t *env,
                                                  adb_searchserve_t* _searchserve10,
                                                  void *user_data,
                                                  axis2_status_t ( AXIS2_CALL *on_complete ) (const axutil_env_t *, adb_searchserveResponse_t* _searchserveResponse11, void *data),
                                                  axis2_status_t ( AXIS2_CALL *on_error ) (const axutil_env_t *, int exception, void *data) );

        


    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_STUB_SEARCHER_ERROR_CODES_START (AXIS2_ERROR_LAST + 2000)

    typedef enum 
    {
        AXIS2_STUB_SEARCHER_ERROR_NONE = AXIS2_STUB_SEARCHER_ERROR_CODES_START,
        
        AXIS2_STUB_SEARCHER_ERROR_LAST
    } axis2_stub_Searcher_error_codes;

	#ifdef __cplusplus
	}
	#endif
   

