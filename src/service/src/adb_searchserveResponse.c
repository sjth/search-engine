

        /**
         * adb_searchserveResponse.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_searchserveResponse.h"
        
               /*
                * implmentation of the searchserveResponse|http://searchengine element
                */
           


        struct adb_searchserveResponse
        {
            axis2_char_t *property_Type;

            
                axutil_qname_t* qname;
            axutil_array_list_t* property_return;

                
                axis2_bool_t is_valid_return;
            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_searchserveResponse_t* AXIS2_CALL
        adb_searchserveResponse_create(
            const axutil_env_t *env)
        {
            adb_searchserveResponse_t *_searchserveResponse = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _searchserveResponse = (adb_searchserveResponse_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_searchserveResponse_t));

            if(NULL == _searchserveResponse)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_searchserveResponse, 0, sizeof(adb_searchserveResponse_t));

            _searchserveResponse->property_Type = axutil_strdup(env, "adb_searchserveResponse");
            _searchserveResponse->property_return  = NULL;
                  _searchserveResponse->is_valid_return  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "searchserveResponse",
                        "http://searchengine",
                        NULL);
                _searchserveResponse->qname = qname;
            

            return _searchserveResponse;
        }

        adb_searchserveResponse_t* AXIS2_CALL
        adb_searchserveResponse_create_with_values(
            const axutil_env_t *env,
                axutil_array_list_t* _return)
        {
            adb_searchserveResponse_t* adb_obj = NULL;
            axis2_status_t status = AXIS2_SUCCESS;

            adb_obj = adb_searchserveResponse_create(env);

            
              status = adb_searchserveResponse_set_return(
                                     adb_obj,
                                     env,
                                     _return);
              if(status == AXIS2_FAILURE) {
                  adb_searchserveResponse_free (adb_obj, env);
                  return NULL;
              }
            

            return adb_obj;
        }
      
        axutil_array_list_t* AXIS2_CALL
                adb_searchserveResponse_free_popping_value(
                        adb_searchserveResponse_t* _searchserveResponse,
                        const axutil_env_t *env)
                {
                    axutil_array_list_t* value;

                    
                    
                    value = _searchserveResponse->property_return;

                    _searchserveResponse->property_return = (axutil_array_list_t*)NULL;
                    adb_searchserveResponse_free(_searchserveResponse, env);

                    return value;
                }
            

        axis2_status_t AXIS2_CALL
        adb_searchserveResponse_free(
                adb_searchserveResponse_t* _searchserveResponse,
                const axutil_env_t *env)
        {
            
            
            return adb_searchserveResponse_free_obj(
                _searchserveResponse,
                env);
            
        }

        axis2_status_t AXIS2_CALL
        adb_searchserveResponse_free_obj(
                adb_searchserveResponse_t* _searchserveResponse,
                const axutil_env_t *env)
        {
            
                int i = 0;
                int count = 0;
                void *element = NULL;
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_FAILURE);

            if (_searchserveResponse->property_Type != NULL)
            {
              AXIS2_FREE(env->allocator, _searchserveResponse->property_Type);
            }

            adb_searchserveResponse_reset_return(_searchserveResponse, env);
            
              if(_searchserveResponse->qname)
              {
                  axutil_qname_free (_searchserveResponse->qname, env);
                  _searchserveResponse->qname = NULL;
              }
            

            if(_searchserveResponse)
            {
                AXIS2_FREE(env->allocator, _searchserveResponse);
                _searchserveResponse = NULL;
            }

            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_searchserveResponse_deserialize(
                adb_searchserveResponse_t* _searchserveResponse,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
            
            
            return adb_searchserveResponse_deserialize_obj(
                _searchserveResponse,
                env,
                dp_parent,
                dp_is_early_node_valid,
                dont_care_minoccurs);
            
        }

        axis2_status_t AXIS2_CALL
        adb_searchserveResponse_deserialize_obj(
                adb_searchserveResponse_t* _searchserveResponse,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
          
              void *element = NULL;
           
             const axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
               int i = 0;
               axutil_array_list_t *arr_list = NULL;
            
               int sequence_broken = 0;
               axiom_node_t *tmp_node = NULL;
            
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for searchserveResponse : "
                            "NULL element can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _searchserveResponse-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for searchserveResponse : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_searchserveResponse-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    
                    /*
                     * building return array
                     */
                       arr_list = axutil_array_list_create(env, 10);
                   

                     
                     /*
                      * building return element
                      */
                     
                     
                     
                                    element_qname = axutil_qname_create(env, "return", "http://searchengine", NULL);
                                  
                               
                               for (i = 0, sequence_broken = 0, current_node = first_node; !sequence_broken && current_node != NULL;) 
                                             
                               {
                                  if(axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                  {
                                     current_node =axiom_node_get_next_sibling(current_node, env);
                                     is_early_node_valid = AXIS2_FALSE;
                                     continue;
                                  }
                                  
                                  current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                  qname = axiom_element_get_qname(current_element, env, current_node);

                                  if (adb_SearchResult_is_particle() ||  
                                    (current_node && current_element && (axutil_qname_equals(element_qname, env, qname))))
                                  {
                                  
                                      if( current_node && current_element && (axutil_qname_equals(element_qname, env, qname)))
                                      {
                                          is_early_node_valid = AXIS2_TRUE;
                                      }
                                      
                                     
                                          element = (void*)axis2_extension_mapper_create_from_node(env, &current_node, "adb_SearchResult");
                                          
                                          status =  adb_SearchResult_deserialize((adb_SearchResult_t*)element, env,
                                                                                 &current_node, &is_early_node_valid, AXIS2_FALSE);
                                          
                                          if(AXIS2_FAILURE ==  status)
                                          {
                                              AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building element return ");
                                          }
                                          else
                                          {
                                            axutil_array_list_add_at(arr_list, env, i, element);
                                          }
                                        
                                     if(AXIS2_FAILURE ==  status)
                                     {
                                         AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for return ");
                                         if(element_qname)
                                         {
                                            axutil_qname_free(element_qname, env);
                                         }
                                         if(arr_list)
                                         {
                                            axutil_array_list_free(arr_list, env);
                                         }
                                         return AXIS2_FAILURE;
                                     }

                                     i ++;
                                    current_node = axiom_node_get_next_sibling(current_node, env);
                                  }
                                  else
                                  {
                                      is_early_node_valid = AXIS2_FALSE;
                                      sequence_broken = 1;
                                  }
                                  
                               }

                               
                                   if (i < 0)
                                   {
                                     /* found element out of order */
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "return (@minOccurs = '0') only have %d elements", i);
                                     if(element_qname)
                                     {
                                        axutil_qname_free(element_qname, env);
                                     }
                                     if(arr_list)
                                     {
                                        axutil_array_list_free(arr_list, env);
                                     }
                                     return AXIS2_FAILURE;
                                   }
                               

                               if(0 == axutil_array_list_size(arr_list,env))
                               {
                                    axutil_array_list_free(arr_list, env);
                               }
                               else
                               {
                                    status = adb_searchserveResponse_set_return(_searchserveResponse, env,
                                                                   arr_list);
                               }

                             
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_searchserveResponse_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_searchserveResponse_declare_parent_namespaces(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_searchserveResponse_serialize(
                adb_searchserveResponse_t* _searchserveResponse,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
                return adb_searchserveResponse_serialize_obj(
                    _searchserveResponse, env, parent, parent_element, parent_tag_closed, namespaces, next_ns_index);
            
        }

        axiom_node_t* AXIS2_CALL
        adb_searchserveResponse_serialize_obj(
                adb_searchserveResponse_t* _searchserveResponse,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
         
         axiom_node_t* current_node = NULL;
         int tag_closed = 0;
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
               int i = 0;
               int count = 0;
               void *element = NULL;
             
                    axis2_char_t text_value_1[ADB_DEFAULT_DIGIT_LIMIT];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _searchserveResponse, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://searchengine",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://searchengine", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "searchserveResponse", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://searchengine", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://searchengine", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://searchengine",
                                            p_prefix));
                       }
                      

                   if (!_searchserveResponse->is_valid_return)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("return"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("return")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     /*
                      * Parsing return array
                      */
                     if (_searchserveResponse->property_return != NULL)
                     {
                        

                            sprintf(start_input_str, "<%s%sreturn",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                         start_input_str_len = axutil_strlen(start_input_str);

                         sprintf(end_input_str, "</%s%sreturn>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                         end_input_str_len = axutil_strlen(end_input_str);

                         count = axutil_array_list_size(_searchserveResponse->property_return, env);
                         for(i = 0; i < count; i ++)
                         {
                            element = axutil_array_list_get(_searchserveResponse->property_return, env, i);

                            if(NULL == element) 
                            {
                                continue;
                            }
                    
                     
                     /*
                      * parsing return element
                      */

                    
                     
                            if(!adb_SearchResult_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            adb_SearchResult_serialize((adb_SearchResult_t*)element, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_SearchResult_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_SearchResult_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                         }
                     }
                   
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, env); hi; hi = axutil_hash_next(env, hi)) 
                       {
                           axutil_hash_this(hi, NULL, NULL, &val);
                           AXIS2_FREE(env->allocator, val);
                       }
                       axutil_hash_free(namespaces, env);
                   }
                

            return parent;
        }


        

            /**
             * Getter for return by  Property Number 1
             */
            axutil_array_list_t* AXIS2_CALL
            adb_searchserveResponse_get_property1(
                adb_searchserveResponse_t* _searchserveResponse,
                const axutil_env_t *env)
            {
                return adb_searchserveResponse_get_return(_searchserveResponse,
                                             env);
            }

            /**
             * getter for return.
             */
            axutil_array_list_t* AXIS2_CALL
            adb_searchserveResponse_get_return(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _searchserveResponse, NULL);
                  

                return _searchserveResponse->property_return;
             }

            /**
             * setter for return
             */
            axis2_status_t AXIS2_CALL
            adb_searchserveResponse_set_return(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env,
                    axutil_array_list_t*  arg_return)
             {
                
                 int size = 0;
                 int i = 0;
                 axis2_bool_t non_nil_exists = AXIS2_FALSE;
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_FAILURE);
                
                if(_searchserveResponse->is_valid_return &&
                        arg_return == _searchserveResponse->property_return)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                 size = axutil_array_list_size(arg_return, env);
                 
                 if (size < 0)
                 {
                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "return has less than minOccurs(0)");
                     return AXIS2_FAILURE;
                 }
                 for(i = 0; i < size; i ++ )
                 {
                     if(NULL != axutil_array_list_get(arg_return, env, i))
                     {
                         non_nil_exists = AXIS2_TRUE;
                         break;
                     }
                 }

                 adb_searchserveResponse_reset_return(_searchserveResponse, env);

                
                if(NULL == arg_return)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _searchserveResponse->property_return = arg_return;
                        if(non_nil_exists)
                        {
                            _searchserveResponse->is_valid_return = AXIS2_TRUE;
                        }
                        
                    
                return AXIS2_SUCCESS;
             }

            
            /**
             * Get ith element of return.
             */
            adb_SearchResult_t* AXIS2_CALL
            adb_searchserveResponse_get_return_at(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env, int i)
            {
                adb_SearchResult_t* ret_val;

                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _searchserveResponse, NULL);
                  

                if(_searchserveResponse->property_return == NULL)
                {
                    return (adb_SearchResult_t*)0;
                }
                ret_val = (adb_SearchResult_t*)axutil_array_list_get(_searchserveResponse->property_return, env, i);
                
                    return ret_val;
                  
            }

            /**
             * Set the ith element of return.
             */
            axis2_status_t AXIS2_CALL
            adb_searchserveResponse_set_return_at(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env, int i,
                    adb_SearchResult_t* arg_return)
            {
                void *element = NULL;
                int size = 0;
                int j;
                int non_nil_count;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_FAILURE);
                
                if( _searchserveResponse->is_valid_return &&
                    _searchserveResponse->property_return &&
                
                    arg_return == (adb_SearchResult_t*)axutil_array_list_get(_searchserveResponse->property_return, env, i))
                  
                {
                    
                    return AXIS2_SUCCESS; 
                }

                
                    if(NULL != arg_return)
                    {
                        non_nil_exists = AXIS2_TRUE;
                    }
                    else {
                        if(_searchserveResponse->property_return != NULL)
                        {
                            size = axutil_array_list_size(_searchserveResponse->property_return, env);
                            for(j = 0, non_nil_count = 0; j < size; j ++ )
                            {
                                if(i == j) continue; 
                                if(NULL != axutil_array_list_get(_searchserveResponse->property_return, env, i))
                                {
                                    non_nil_count ++;
                                    non_nil_exists = AXIS2_TRUE;
                                    if(non_nil_count >= 0)
                                    {
                                        break;
                                    }
                                }
                            }

                        
                        }
                    }
                  

                if(_searchserveResponse->property_return == NULL)
                {
                    _searchserveResponse->property_return = axutil_array_list_create(env, 10);
                }
                
                /* check whether there already exist an element */
                element = axutil_array_list_get(_searchserveResponse->property_return, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_SearchResult_free((adb_SearchResult_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _searchserveResponse->is_valid_return = AXIS2_FALSE;
                        axutil_array_list_set(_searchserveResponse->property_return , env, i, NULL);
                        
                        return AXIS2_SUCCESS;
                    }
                
                   axutil_array_list_set(_searchserveResponse->property_return , env, i, arg_return);
                  _searchserveResponse->is_valid_return = AXIS2_TRUE;
                
                return AXIS2_SUCCESS;
            }

            /**
             * Add to return.
             */
            axis2_status_t AXIS2_CALL
            adb_searchserveResponse_add_return(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env,
                    adb_SearchResult_t* arg_return)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_FAILURE);

                
                    if(NULL == arg_return)
                    {
                      
                           return AXIS2_SUCCESS; 
                        
                    }
                  

                if(_searchserveResponse->property_return == NULL)
                {
                    _searchserveResponse->property_return = axutil_array_list_create(env, 10);
                }
                if(_searchserveResponse->property_return == NULL)
                {
                    AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Failed in allocatting memory for return");
                    return AXIS2_FAILURE;
                    
                }
                
                   axutil_array_list_add(_searchserveResponse->property_return , env, arg_return);
                  _searchserveResponse->is_valid_return = AXIS2_TRUE;
                return AXIS2_SUCCESS;
             }

            /**
             * Get the size of the return array.
             */
            int AXIS2_CALL
            adb_searchserveResponse_sizeof_return(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env)
            {
                AXIS2_ENV_CHECK(env, -1);
                AXIS2_PARAM_CHECK(env->error, _searchserveResponse, -1);
                if(_searchserveResponse->property_return == NULL)
                {
                    return 0;
                }
                return axutil_array_list_size(_searchserveResponse->property_return, env);
            }

            /**
             * remove the ith element, same as set_nil_at.
             */
            axis2_status_t AXIS2_CALL
            adb_searchserveResponse_remove_return_at(
                    adb_searchserveResponse_t* _searchserveResponse,
                    const axutil_env_t *env, int i)
            {
                return adb_searchserveResponse_set_return_nil_at(_searchserveResponse, env, i);
            }

            

           /**
            * resetter for return
            */
           axis2_status_t AXIS2_CALL
           adb_searchserveResponse_reset_return(
                   adb_searchserveResponse_t* _searchserveResponse,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_FAILURE);
               

               
                  if (_searchserveResponse->property_return != NULL)
                  {
                      count = axutil_array_list_size(_searchserveResponse->property_return, env);
                      for(i = 0; i < count; i ++)
                      {
                         element = axutil_array_list_get(_searchserveResponse->property_return, env, i);
                
            
                
                if(element != NULL)
                {
                   
                   adb_SearchResult_free((adb_SearchResult_t*)element, env);
                     element = NULL;
                }
            
                
                
                
                      }
                      axutil_array_list_free(_searchserveResponse->property_return, env);
                  }
                _searchserveResponse->is_valid_return = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether return is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_searchserveResponse_is_return_nil(
                   adb_searchserveResponse_t* _searchserveResponse,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_TRUE);
               
               return !_searchserveResponse->is_valid_return;
           }

           /**
            * Set return to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_searchserveResponse_set_return_nil(
                   adb_searchserveResponse_t* _searchserveResponse,
                   const axutil_env_t *env)
           {
               return adb_searchserveResponse_reset_return(_searchserveResponse, env);
           }

           
           /**
            * Check whether return is nill at i
            */
           axis2_bool_t AXIS2_CALL
           adb_searchserveResponse_is_return_nil_at(
                   adb_searchserveResponse_t* _searchserveResponse,
                   const axutil_env_t *env, int i)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_TRUE);
               
               return (_searchserveResponse->is_valid_return == AXIS2_FALSE ||
                        NULL == _searchserveResponse->property_return || 
                        NULL == axutil_array_list_get(_searchserveResponse->property_return, env, i));
           }

           /**
            * Set return to nill at i
            */
           axis2_status_t AXIS2_CALL
           adb_searchserveResponse_set_return_nil_at(
                   adb_searchserveResponse_t* _searchserveResponse,
                   const axutil_env_t *env, int i)
           {
                void *element = NULL;
                int size = 0;
                int j;
                axis2_bool_t non_nil_exists = AXIS2_FALSE;

                int k = 0;

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _searchserveResponse, AXIS2_FAILURE);

                if(_searchserveResponse->property_return == NULL ||
                            _searchserveResponse->is_valid_return == AXIS2_FALSE)
                {
                    
                    non_nil_exists = AXIS2_FALSE;
                }
                else
                {
                    size = axutil_array_list_size(_searchserveResponse->property_return, env);
                    for(j = 0, k = 0; j < size; j ++ )
                    {
                        if(i == j) continue; 
                        if(NULL != axutil_array_list_get(_searchserveResponse->property_return, env, i))
                        {
                            k ++;
                            non_nil_exists = AXIS2_TRUE;
                            if( k >= 0)
                            {
                                break;
                            }
                        }
                    }
                }
                

                if( k < 0)
                {
                       AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Size of the array of return is beinng set to be smaller than the specificed number of minOccurs(0)");
                       return AXIS2_FAILURE;
                }
 
                if(_searchserveResponse->property_return == NULL)
                {
                    _searchserveResponse->is_valid_return = AXIS2_FALSE;
                    
                    return AXIS2_SUCCESS;
                }

                /* check whether there already exist an element */
                element = axutil_array_list_get(_searchserveResponse->property_return, env, i);
                if(NULL != element)
                {
                  
                  
                  adb_SearchResult_free((adb_SearchResult_t*)element, env);
                     
                }

                
                    if(!non_nil_exists)
                    {
                        
                        _searchserveResponse->is_valid_return = AXIS2_FALSE;
                        axutil_array_list_set(_searchserveResponse->property_return , env, i, NULL);
                        return AXIS2_SUCCESS;
                    }
                

                
                axutil_array_list_set(_searchserveResponse->property_return , env, i, NULL);
                
                return AXIS2_SUCCESS;

           }

           

