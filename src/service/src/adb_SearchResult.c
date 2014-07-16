

        /**
         * adb_SearchResult.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_SearchResult.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = SearchResult
                 * Namespace URI = http://searchengine/xsd
                 * Namespace Prefix = ns1
                 */
           


        struct adb_SearchResult
        {
            axis2_char_t *property_Type;

            int property_rank;

                
                axis2_bool_t is_valid_rank;
            axis2_char_t* property_snippet;

                
                axis2_bool_t is_valid_snippet;
            axis2_char_t* property_title;

                
                axis2_bool_t is_valid_title;
            axis2_char_t* property_url;

                
                axis2_bool_t is_valid_url;
            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_SearchResult_set_rank_nil(
                        adb_SearchResult_t* _SearchResult,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_SearchResult_t* AXIS2_CALL
        adb_SearchResult_create(
            const axutil_env_t *env)
        {
            adb_SearchResult_t *_SearchResult = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _SearchResult = (adb_SearchResult_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_SearchResult_t));

            if(NULL == _SearchResult)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_SearchResult, 0, sizeof(adb_SearchResult_t));

            _SearchResult->property_Type = axutil_strdup(env, "adb_SearchResult");
            _SearchResult->is_valid_rank  = AXIS2_FALSE;
            _SearchResult->property_snippet  = NULL;
                  _SearchResult->is_valid_snippet  = AXIS2_FALSE;
            _SearchResult->property_title  = NULL;
                  _SearchResult->is_valid_title  = AXIS2_FALSE;
            _SearchResult->property_url  = NULL;
                  _SearchResult->is_valid_url  = AXIS2_FALSE;
            

            return _SearchResult;
        }

        adb_SearchResult_t* AXIS2_CALL
        adb_SearchResult_create_with_values(
            const axutil_env_t *env,
                int _rank,
                axis2_char_t* _snippet,
                axis2_char_t* _title,
                axis2_char_t* _url)
        {
            adb_SearchResult_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_SearchResult_create(env);

            
              status = adb_SearchResult_set_rank(
                                     adb_obj,
                                     env,
                                     _rank);
              if(status == AXIS2_FAILURE) {
                  adb_SearchResult_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SearchResult_set_snippet(
                                     adb_obj,
                                     env,
                                     _snippet);
              if(status == AXIS2_FAILURE) {
                  adb_SearchResult_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SearchResult_set_title(
                                     adb_obj,
                                     env,
                                     _title);
              if(status == AXIS2_FAILURE) {
                  adb_SearchResult_free (adb_obj, env);
                  return NULL;
              }
            
              status = adb_SearchResult_set_url(
                                     adb_obj,
                                     env,
                                     _url);
              if(status == AXIS2_FAILURE) {
                  adb_SearchResult_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        int AXIS2_CALL
                adb_SearchResult_free_popping_value(
                        adb_SearchResult_t* _SearchResult,
                        const axutil_env_t *env)
                {
                    int value;

                    
                    
                    value = _SearchResult->property_rank;

                    adb_SearchResult_free(_SearchResult, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_SearchResult_free(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env)
        {
            
            
            return axis2_extension_mapper_free(
                (adb_type_t*) _SearchResult,
                env,
                "adb_SearchResult");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SearchResult_free_obj(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);

            if (_SearchResult->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _SearchResult->property_Type);
            }

            adb_SearchResult_reset_rank(_SearchResult, env);
            adb_SearchResult_reset_snippet(_SearchResult, env);
            adb_SearchResult_reset_title(_SearchResult, env);
            adb_SearchResult_reset_url(_SearchResult, env);
            

            if(_SearchResult)
            {
                AXIS2_FREE(env->allocator, _SearchResult);
                _SearchResult = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_SearchResult_deserialize(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return axis2_extension_mapper_deserialize(
                (adb_type_t*) _SearchResult,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs,
                "adb_SearchResult");
            
        }

        axis2_status_t AXIS2_CALL
        adb_SearchResult_deserialize_obj(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
           
             const axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for SearchResult : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building rank element
                      */
                     
                     
                     
                                   current_node = first_node;
                                   is_early_node_valid = AXIS2_FALSE;
                                   
                                   
                                    while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                    {
                                        current_node = axiom_node_get_next_sibling(current_node, env);
                                    }
                                    if(current_node != NULL)
                                    {
                                        current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                        qname = axiom_element_get_qname(current_element, env, current_node);
                                    }
                                   
                                 element_qname = axutil_qname_create(env, "rank", "http://searchengine/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_SearchResult_set_rank(_SearchResult, env,
                                                                   atoi(text_value));
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element rank");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for rank ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building snippet element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "snippet", "http://searchengine/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_SearchResult_set_snippet(_SearchResult, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for snippet ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building title element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "title", "http://searchengine/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_SearchResult_set_title(_SearchResult, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for title ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building url element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "url", "http://searchengine/xsd", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_SearchResult_set_url(_SearchResult, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for url ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_SearchResult_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_SearchResult_declare_parent_namespaces(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_SearchResult_serialize(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
            if (_SearchResult == NULL)
            {
                return adb_SearchResult_serialize_obj(
                    _SearchResult, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            }
            else
            {
                return axis2_extension_mapper_serialize(
                    (adb_type_t*) _SearchResult, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index, "adb_SearchResult");
            }
            
        }

        axiom_node_t* AXIS2_CALL
        adb_SearchResult_serialize_obj(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
             axis2_char_t *string_to_stream;
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
         axis2_char_t* xsi_prefix = NULL;
         
         axis2_char_t* type_attrib = NULL;
         axiom_namespace_t* xsi_ns = NULL;
         axiom_attribute_t* xsi_type_attri = NULL;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
                    axis2_char_t text_value_1[ADB_DEFAULT_DIGIT_LIMIT];
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
                    axis2_char_t *text_value_3;
                    axis2_char_t *text_value_3_temp;
                    
                    axis2_char_t *text_value_4;
                    axis2_char_t *text_value_4_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _SearchResult, NULL);
            
            
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  
            if(!parent_tag_closed)
            {
            
              
 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
              type_attrib = axutil_strcat(env, " ", xsi_prefix, ":type=\"SearchResult\"", NULL);
              axutil_stream_write(stream, env, type_attrib, axutil_strlen(type_attrib));

              AXIS2_FREE(env->allocator, type_attrib);
                
              string_to_stream = ">"; 
              axutil_stream_write(stream, env, string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            
            }
            else {
              /* if the parent tag closed we would be able to declare the type directly on the parent element */ 
              if(!(xsi_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING)))
              {
                  /* it is better to stick with the standard prefix */
                  xsi_prefix = (axis2_char_t*)axutil_strdup(env, "xsi");
                  
                  axutil_hash_set(namespaces, "http://www.w3.org/2001/XMLSchema-instance", AXIS2_HASH_KEY_STRING, xsi_prefix);

                  if(parent_element)
                  {
                        axiom_namespace_t *element_ns = NULL;
                        element_ns = axiom_namespace_create(env, "http://www.w3.org/2001/XMLSchema-instance",
                                                            xsi_prefix);
                        axiom_element_declare_namespace_assume_param_ownership(parent_element, env, element_ns);
                  }
              }
            }
            xsi_ns = axiom_namespace_create (env,
                                 "http://searchengine/xsd",
                                 xsi_prefix);
            xsi_type_attri = axiom_attribute_create (env, "type", "SearchResult", xsi_ns);
            
            axiom_element_add_attribute (parent_element, env, xsi_type_attri, parent);
        
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://searchengine/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SearchResult->is_valid_rank)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("rank"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("rank")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing rank element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%srank>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%srank>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                               sprintf (text_value_1, AXIS2_PRINTF_INT32_FORMAT_SPECIFIER, _SearchResult->property_rank);
                             
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://searchengine/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SearchResult->is_valid_snippet)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("snippet"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("snippet")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing snippet element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%ssnippet>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%ssnippet>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _SearchResult->property_snippet;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_2_temp = axutil_xml_quote_string(env, text_value_2, AXIS2_TRUE);
                           if (text_value_2_temp)
                           {
                               axutil_stream_write(stream, env, text_value_2_temp, axutil_strlen(text_value_2_temp));
                               AXIS2_FREE(env->allocator, text_value_2_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://searchengine/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SearchResult->is_valid_title)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("title"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("title")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing title element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%stitle>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%stitle>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_3 = _SearchResult->property_title;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_3_temp = axutil_xml_quote_string(env, text_value_3, AXIS2_TRUE);
                           if (text_value_3_temp)
                           {
                               axutil_stream_write(stream, env, text_value_3_temp, axutil_strlen(text_value_3_temp));
                               AXIS2_FREE(env->allocator, text_value_3_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_3, axutil_strlen(text_value_3));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://searchengine/xsd", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://searchengine/xsd",
                                            p_prefix));
                       }
                      

                   if (!_SearchResult->is_valid_url)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("url"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("url")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing url element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%surl>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%surl>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_4 = _SearchResult->property_url;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_4_temp = axutil_xml_quote_string(env, text_value_4, AXIS2_TRUE);
                           if (text_value_4_temp)
                           {
                               axutil_stream_write(stream, env, text_value_4_temp, axutil_strlen(text_value_4_temp));
                               AXIS2_FREE(env->allocator, text_value_4_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_4, axutil_strlen(text_value_4));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * Getter for rank by  Property Number 1
             */
            int AXIS2_CALL
            adb_SearchResult_get_property1(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env)
            {
                return adb_SearchResult_get_rank(_SearchResult,
                                             env);
            }

            /**
             * getter for rank.
             */
            int AXIS2_CALL
            adb_SearchResult_get_rank(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (int)0);
                    AXIS2_PARAM_CHECK(env->error, _SearchResult, (int)0);
                  

                return _SearchResult->property_rank;
             }

            /**
             * setter for rank
             */
            axis2_status_t AXIS2_CALL
            adb_SearchResult_set_rank(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env,
                    const int  arg_rank)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
                
                if(_SearchResult->is_valid_rank &&
                        arg_rank == _SearchResult->property_rank)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SearchResult_reset_rank(_SearchResult, env);

                _SearchResult->property_rank = arg_rank;
                        _SearchResult->is_valid_rank = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for rank
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_reset_rank(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
               

               _SearchResult->is_valid_rank = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether rank is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SearchResult_is_rank_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_TRUE);
               
               return !_SearchResult->is_valid_rank;
           }

           /**
            * Set rank to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_set_rank_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               return adb_SearchResult_reset_rank(_SearchResult, env);
           }

           

            /**
             * Getter for snippet by  Property Number 2
             */
            axis2_char_t* AXIS2_CALL
            adb_SearchResult_get_property2(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env)
            {
                return adb_SearchResult_get_snippet(_SearchResult,
                                             env);
            }

            /**
             * getter for snippet.
             */
            axis2_char_t* AXIS2_CALL
            adb_SearchResult_get_snippet(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SearchResult, NULL);
                  

                return _SearchResult->property_snippet;
             }

            /**
             * setter for snippet
             */
            axis2_status_t AXIS2_CALL
            adb_SearchResult_set_snippet(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_snippet)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
                
                if(_SearchResult->is_valid_snippet &&
                        arg_snippet == _SearchResult->property_snippet)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SearchResult_reset_snippet(_SearchResult, env);

                
                if(NULL == arg_snippet)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SearchResult->property_snippet = (axis2_char_t *)axutil_strdup(env, arg_snippet);
                        if(NULL == _SearchResult->property_snippet)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for snippet");
                            return AXIS2_FAILURE;
                        }
                        _SearchResult->is_valid_snippet = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for snippet
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_reset_snippet(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
               

               
            
                
                if(_SearchResult->property_snippet != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SearchResult->property_snippet);
                     _SearchResult->property_snippet = NULL;
                }
            
                
                
                _SearchResult->is_valid_snippet = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether snippet is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SearchResult_is_snippet_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_TRUE);
               
               return !_SearchResult->is_valid_snippet;
           }

           /**
            * Set snippet to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_set_snippet_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               return adb_SearchResult_reset_snippet(_SearchResult, env);
           }

           

            /**
             * Getter for title by  Property Number 3
             */
            axis2_char_t* AXIS2_CALL
            adb_SearchResult_get_property3(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env)
            {
                return adb_SearchResult_get_title(_SearchResult,
                                             env);
            }

            /**
             * getter for title.
             */
            axis2_char_t* AXIS2_CALL
            adb_SearchResult_get_title(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SearchResult, NULL);
                  

                return _SearchResult->property_title;
             }

            /**
             * setter for title
             */
            axis2_status_t AXIS2_CALL
            adb_SearchResult_set_title(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_title)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
                
                if(_SearchResult->is_valid_title &&
                        arg_title == _SearchResult->property_title)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SearchResult_reset_title(_SearchResult, env);

                
                if(NULL == arg_title)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SearchResult->property_title = (axis2_char_t *)axutil_strdup(env, arg_title);
                        if(NULL == _SearchResult->property_title)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for title");
                            return AXIS2_FAILURE;
                        }
                        _SearchResult->is_valid_title = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for title
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_reset_title(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
               

               
            
                
                if(_SearchResult->property_title != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SearchResult->property_title);
                     _SearchResult->property_title = NULL;
                }
            
                
                
                _SearchResult->is_valid_title = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether title is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SearchResult_is_title_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_TRUE);
               
               return !_SearchResult->is_valid_title;
           }

           /**
            * Set title to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_set_title_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               return adb_SearchResult_reset_title(_SearchResult, env);
           }

           

            /**
             * Getter for url by  Property Number 4
             */
            axis2_char_t* AXIS2_CALL
            adb_SearchResult_get_property4(
                adb_SearchResult_t* _SearchResult,
                const axutil_env_t *env)
            {
                return adb_SearchResult_get_url(_SearchResult,
                                             env);
            }

            /**
             * getter for url.
             */
            axis2_char_t* AXIS2_CALL
            adb_SearchResult_get_url(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _SearchResult, NULL);
                  

                return _SearchResult->property_url;
             }

            /**
             * setter for url
             */
            axis2_status_t AXIS2_CALL
            adb_SearchResult_set_url(
                    adb_SearchResult_t* _SearchResult,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_url)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
                
                if(_SearchResult->is_valid_url &&
                        arg_url == _SearchResult->property_url)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_SearchResult_reset_url(_SearchResult, env);

                
                if(NULL == arg_url)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _SearchResult->property_url = (axis2_char_t *)axutil_strdup(env, arg_url);
                        if(NULL == _SearchResult->property_url)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for url");
                            return AXIS2_FAILURE;
                        }
                        _SearchResult->is_valid_url = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for url
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_reset_url(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_FAILURE);
               

               
            
                
                if(_SearchResult->property_url != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _SearchResult->property_url);
                     _SearchResult->property_url = NULL;
                }
            
                
                
                _SearchResult->is_valid_url = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether url is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_SearchResult_is_url_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _SearchResult, AXIS2_TRUE);
               
               return !_SearchResult->is_valid_url;
           }

           /**
            * Set url to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_SearchResult_set_url_nil(
                   adb_SearchResult_t* _SearchResult,
                   const axutil_env_t *env)
           {
               return adb_SearchResult_reset_url(_SearchResult, env);
           }

           

