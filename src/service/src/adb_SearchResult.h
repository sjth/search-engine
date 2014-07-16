

        #ifndef ADB_SEARCHRESULT_H
        #define ADB_SEARCHRESULT_H

       /**
        * adb_SearchResult.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: 1.6.2  Built on : Apr 17, 2012 (05:34:40 IST)
        */

       /**
        *  adb_SearchResult class
        */

        

        #include <stdio.h>
        #include <axiom.h>
        #include <axis2_util.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>

        #include "axis2_extension_mapper.h"

        #ifdef __cplusplus
        extern "C"
        {
        #endif

        #define ADB_DEFAULT_DIGIT_LIMIT 1024
        #define ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT 64
        

        typedef struct adb_SearchResult adb_SearchResult_t;

        
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_SearchResult_t
         * @param env pointer to environment struct
         * @return newly created adb_SearchResult_t object
         */
        adb_SearchResult_t* AXIS2_CALL
        adb_SearchResult_create(
            const axutil_env_t *env );

        /**
         * Wrapper for the "free" function, will invoke the extension mapper instead
         * @param  _SearchResult adb_SearchResult_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_free (
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        /**
         * Free adb_SearchResult_t object
         * @param  _SearchResult adb_SearchResult_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_free_obj (
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for rank. 
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SearchResult_get_rank(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        /**
         * Setter for rank.
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param arg_rank int
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_set_rank(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            const int  arg_rank);

        /**
         * Resetter for rank
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_reset_rank(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        
        

        /**
         * Getter for snippet. 
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SearchResult_get_snippet(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        /**
         * Setter for snippet.
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param arg_snippet axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_set_snippet(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            const axis2_char_t*  arg_snippet);

        /**
         * Resetter for snippet
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_reset_snippet(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        
        

        /**
         * Getter for title. 
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SearchResult_get_title(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        /**
         * Setter for title.
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param arg_title axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_set_title(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            const axis2_char_t*  arg_title);

        /**
         * Resetter for title
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_reset_title(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        
        

        /**
         * Getter for url. 
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SearchResult_get_url(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        /**
         * Setter for url.
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param arg_url axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_set_url(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            const axis2_char_t*  arg_url);

        /**
         * Resetter for url
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_reset_url(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether rank is nill
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SearchResult_is_rank_nil(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env);


        

        /**
         * Check whether snippet is nill
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SearchResult_is_snippet_nil(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env);


        
        /**
         * Set snippet to nill (currently the same as reset)
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_set_snippet_nil(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env);
        

        /**
         * Check whether title is nill
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SearchResult_is_title_nil(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env);


        
        /**
         * Set title to nill (currently the same as reset)
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_set_title_nil(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env);
        

        /**
         * Check whether url is nill
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_SearchResult_is_url_nil(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env);


        
        /**
         * Set url to nill (currently the same as reset)
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_set_url_nil(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Wrapper for the deserialization function, will invoke the extension mapper instead
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_deserialize(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);

        /**
         * Deserialize an XML to adb objects
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs,
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_SearchResult_deserialize_obj(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_SearchResult_declare_parent_namespaces(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Wrapper for the serialization function, will invoke the extension mapper instead
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param SearchResult_om_node node to serialize from
         * @param SearchResult_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_SearchResult_serialize(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            axiom_node_t* SearchResult_om_node, axiom_element_t *SearchResult_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Serialize to an XML from the adb objects
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @param SearchResult_om_node node to serialize from
         * @param SearchResult_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_SearchResult_serialize_obj(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env,
            axiom_node_t* SearchResult_om_node, axiom_element_t *SearchResult_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_SearchResult is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_SearchResult_is_particle();

        /******************************* Alternatives for Create and Free functions *********************************/

        

        /**
         * Constructor for creating adb_SearchResult_t
         * @param env pointer to environment struct
         * @param _rank int
         * @param _snippet axis2_char_t*
         * @param _title axis2_char_t*
         * @param _url axis2_char_t*
         * @return newly created adb_SearchResult_t object
         */
        adb_SearchResult_t* AXIS2_CALL
        adb_SearchResult_create_with_values(
            const axutil_env_t *env,
                int _rank,
                axis2_char_t* _snippet,
                axis2_char_t* _title,
                axis2_char_t* _url);

        


                /**
                 * Free adb_SearchResult_t object and return the property value.
                 * You can use this to free the adb object as returning the property value. If there are
                 * many properties, it will only return the first property. Other properties will get freed with the adb object.
                 * @param  _SearchResult adb_SearchResult_t object to free
                 * @param env pointer to environment struct
                 * @return the property value holded by the ADB object, if there are many properties only returns the first.
                 */
                int AXIS2_CALL
                adb_SearchResult_free_popping_value(
                        adb_SearchResult_t* _SearchResult,
                        const axutil_env_t *env);
            

        /******************************* get the value by the property number  *********************************/
        /************NOTE: This method is introduced to resolve a problem in unwrapping mode *******************/

        
        

        /**
         * Getter for rank by property number (1)
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return int
         */
        int AXIS2_CALL
        adb_SearchResult_get_property1(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

    
        

        /**
         * Getter for snippet by property number (2)
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SearchResult_get_property2(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

    
        

        /**
         * Getter for title by property number (3)
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SearchResult_get_property3(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

    
        

        /**
         * Getter for url by property number (4)
         * @param  _SearchResult adb_SearchResult_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_SearchResult_get_property4(
            adb_SearchResult_t* _SearchResult,
            const axutil_env_t *env);

    
     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_SEARCHRESULT_H */
    

