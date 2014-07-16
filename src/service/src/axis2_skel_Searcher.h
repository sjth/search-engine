

    /**
     * axis2_skel_Searcher.h
     *
     * This file was auto-generated from WSDL for "Searcher|http://searchengine" service
     * by the Apache Axis2/C version: 1.6.2  Built on : Apr 17, 2012 (05:33:49 IST)
     * axis2_skel_Searcher Axis2/C skeleton for the axisService- Header file
     */


	#include <axis2_svc_skeleton.h>
	#include <axutil_log_default.h>
	#include <axutil_error_default.h>
    #include <axutil_error.h>
	#include <axiom_text.h>
	#include <axiom_node.h>
	#include <axiom_element.h>
    #include <stdio.h>


   
     #include "adb_searchserve.h"
    
     #include "adb_searchserveResponse.h"
    

	#ifdef __cplusplus
	extern "C" {
	#endif

     

		 
        /**
         * auto generated function declaration
         * for "searchserve|http://searchengine" operation.
         * @param env environment ( mandatory)* @param MessageContext the outmessage context
         * @param _searchserve of the adb_searchserve_t*
         *
         * @return adb_searchserveResponse_t*
         */
        adb_searchserveResponse_t* axis2_skel_Searcher_searchserve(const axutil_env_t *env,axis2_msg_ctx_t *msg_ctx,
                                              adb_searchserve_t* _searchserve);


     

    /** we have to reserve some error codes for adb and for custom messages */
    #define AXIS2_SKEL_SEARCHER_ERROR_CODES_START (AXIS2_ERROR_LAST + 2500)

    typedef enum 
    {
        AXIS2_SKEL_SEARCHER_ERROR_NONE = AXIS2_SKEL_SEARCHER_ERROR_CODES_START,
        
        AXIS2_SKEL_SEARCHER_ERROR_LAST
    } axis2_skel_Searcher_error_codes;

	#ifdef __cplusplus
	}
	#endif
    

