/*@!Encoding:1252*/
variables{}
/*===========================================================*/
/*=========       ECU & TIME TARGET CONTROLLER       ========*/
/*===========================================================*/
void Matrix(ecu){
    switch(ecu){
        case _GATEWAY_:{
                         StartSimulation(_GATEWAY_, _10ms_);
                         StartSimulation(_GATEWAY_, _50ms_);
                         break;
                       }
    }
}

/*=_________________________________________________________=*/



/*===========================================================*/
/*=========       ECU & TIME TARGET CONTROLLER       ========*/
/*===========================================================*/
void StartSimulation(char ecu, long time){
    write(" WELCOME, TO THE MATRIX !");
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                        G A T E W A Y
    * * *  * * * * * * * * * * * * * * * * * * * * * * * * * */
    if(_GATEWAY_ == ecu){    

    if(_OFF_ == _GATEWAY_flag_stop){                                            //GATEWAY_FLAG_STOP as default = _off_. See the file 'k_config.can' for more details.
        setTimerCyclic(t_stop_messages_gateway, _T_STOP_MSG_);                  //Starting a timer to enable the service 0x28 UDS PROTOCOL in order to shut up this ECU into CAN bus
    }   

    switch(time){                                                               //check what time was previous selected by user (received by 'time' argument)
            case _10ms_:{                                                       //if 10 milseseconds are choosed, thus .:.
                    _GATEWAY_target_10 = _ENABLED_;                             //enable bcm flag to informe it to another function (to timer schedule ctrl)                                                        
                    //check_timer_10ms = isTimerActive(t_10ms) ;                //Another ECU can being using the 10ms thread time, so:
                    if( isTimerActive(t_10ms) ){                                //Verify if this 'setTimer' is already running to prevent loss of sync
                        write("Timer already previous set by user!");           //Informe it to user in the serial console (trace)
                    }
                    else{                                                       //otherwise, is the 1st time that this time will be set.
                        write("CLUSTER 10ms message will be send!\n");          //Informe it to user in the serial console (trace)
                        setTimerCyclic(t_10ms, _10ms_);                         //thus, make do it! Enable the Cyclic timer to interrupt event for each 10 ms
                    }            
                    break;                                                      //get out this loop!
            }//end case _10ms_ 


            case _VIN_TIMER_:{                                                       
            _GATEWAY_target_VIN = _ENABLED_;                           
            if( isTimerActive(_VIN_TIMER_) ){                         
                write("Timer already previous set by user!");      
            }
            else{                 
                write("_GATEWAY_ 50ms message will be send!\n");    
                setTimerCyclic(t_vin, _VIN_TIMER_);                   
            }          
            break;                                            
            }//end case _VIN_TIMER_
            
            case _50ms_:{                                                       
                    _GATEWAY_target_50 = _ENABLED_;                           
                    if( isTimerActive(t_50ms) ){                         
                        write("Timer already previous set by user!");      
                    }
                    else{                 
                        write("_GATEWAY_ 50ms message will be send!\n");    
                        setTimerCyclic(t_50ms,_10ms_);                   
                    }          
                    break;                                            
            }//end case _50ms_      

            
            case _100ms_:{                                                
                _GATEWAY_target_100 = _ENABLED_;                                 
                if( isTimerActive(t_100ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{       
                    write("_GATEWAY_ 100ms message will be send!\n");  
                    setTimerCyclic(t_100ms_,_100ms_);                   
                }         
                break;                                              
            }//end case _100ms_ 


            case _150ms_:{                                                
                _GATEWAY_target_150 = _ENABLED_;                                 
                if( isTimerActive(t_150ms_) ){                             
                }
                else{    
                    write("Timer already previous set by user!"); 
                    setTimerCyclic(t_150ms_,_150ms_);                   
                }         
                break;                                              
            }//end case _150ms_ 


            case _200ms_:{                                                
                _GATEWAY_target_200 = _ENABLED_;                          
                if( isTimerActive(t_200ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{     
                    write("_GATEWAY_ 200ms message will be send!\n");    
                    setTimerCyclic(t_200ms_,_200ms_);                   
                }         
                break;                                              
            }//end case _200ms_ 

            
            case _250ms_:{                                                
                _GATEWAY_target_250 = _ENABLED_;                          
                if( isTimerActive(t_250ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{
                    write("_GATEWAY_ 250ms message will be send!\n");
                    setTimerCyclic(t_250ms_,_250ms_);                   
                }         
                break;                                              
            }//end case _250ms_ 

            
            case _300ms_:{                                                
                _GATEWAY_target_300 = _ENABLED_;                                  
                if( isTimerActive(t_300ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{         
                    write("_GATEWAY_ 300ms message will be send!\n");   
                    setTimerCyclic(t_300ms_,_300ms_);                   
                }         
                break;                                              
            }//end case _300ms_ 

            
            case _400ms_:{                                                
                _GATEWAY_target_400 = _ENABLED_;                                   
                if( isTimerActive(t_400ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{  
                    write("_GATEWAY_ 100ms message will be send!\n");  
                    setTimerCyclic(t_400ms_,_400ms_);                   
                }         
                break;                                              
            }//end case _400ms_ 

            
            case _450ms_:{                                                
                _GATEWAY_target_450 = _ENABLED_;                          
                if( isTimerActive(t_450ms_) ){  
                    write("Timer already previous set by user!");      
                }
                else{   
                    write("_GATEWAY_ 450ms message will be send!\n"); 
                    setTimerCyclic(t_450ms_,_450ms_);                   
                }         
                break;                                              
            }//end case _100ms_ 

            
            case _500ms_:{                                                
                _GATEWAY_target_500 = _ENABLED_;                          
                if( isTimerActive(t_500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{
                    write("_GATEWAY_ 500ms message will be send!\n"); 
                    setTimerCyclic(t_500ms_,_500ms_);                   
                }         
                break;                                              
            }//end case _500ms_ 

            
            case _700ms_:{                                                
                _GATEWAY_target_700 = _ENABLED_;                                 
                if( isTimerActive(t_700ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{ 
                    write("_GATEWAY_ 700ms message will be send!\n");   
                    setTimerCyclic(t_700ms_,_700ms_);                   
                }         
                break;                                              
            }//end case _700ms_ 

            
            case _1000ms_:{                                                
                _GATEWAY_target_1000 = _ENABLED_;                          
                if( isTimerActive(t_1000ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{  
                    write("_GATEWAY_ 1000ms message will be send!\n");
                    setTimerCyclic(t_1000ms_,_1000ms_);                   
                }         
                break;                                              
            }//end case _1000ms_ 

            
            case _1500ms_:{                                                
                _GATEWAY_target_1500 = _ENABLED_;                          
                if( isTimerActive(t_1500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{                           
                    write("_GATEWAY_ 1500ms message will be send!\n"); 
                    setTimerCyclic(t_1500ms_,_1500ms_);                   
                }         
                break;                                              
            }//end case _1500ms_                                                

            
            case _2000ms_:{                                                
                _GATEWAY_target_2000 = _ENABLED_;                          
                if( isTimerActive(t_2000ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{ 
                    write("_GATEWAY_ 2000ms message will be send!\n"); 
                    setTimerCyclic(t_2000ms_,_2000ms_);                   
                }         
                break;                                              
            }//end case _2000ms_ 

            
            case _2500ms_:{                                                
                _GATEWAY_target_2500 = _ENABLED_;                                    
                if( isTimerActive(t_2500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{   
                    write("_GATEWAY_ 2500ms message will be send!\n"); 
                    setTimerCyclic(t_2500ms_,_2500ms_);                   
                }         
                break;                                              
            }//end case _2500ms_        

            
            default: break;
        }//end case 'x_ms'     
    }//if(_GATEWAY_ == ecu){}
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                        C L U S T E R
  * * *  * * * * * * * * * * * * * * * * * * * * * * * * * */
  if(_CLUSTER_ == ecu){    
     
    if(_OFF_ == _CLUSTER_flag_stop){                                            //CLUSTER_FLAG_STOP as default = _off_. See the file 'k_config.can' for more details.
        setTimerCyclic(t_stop_messages_cluster, _T_STOP_MSG_);                  //Starting a timer to enable the service 0x28 UDS PROTOCOL in order to shut up this ECU into CAN bus
    }   

    switch(time){                                                               //check what time was previous selected by user (received by 'time' argument)
          case _10ms_:{                                                         //if 10 milseseconds are choosed, thus .:.
                    _CLUSTER_target_10 = _ENABLED_;                             //enable bcm flag to informe it to another function (to timer schedule ctrl)                                                        
                    //check_timer_10ms = isTimerActive(t_10ms) ;                //Another ECU can being using the 10ms thread time, so:
                    if( isTimerActive(t_10ms) ){                                //Verify if this 'setTimer' is already running to prevent loss of sync
                      write("Timer already previous set by user!");             //Informe it to user in the serial console (trace)
                    }
                    else{                                                       //otherwise, is the 1st time that this time will be set.
                      write("CLUSTER 10ms message will be send!\n");            //Informe it to user in the serial console (trace)
                      setTimerCyclic(t_10ms, _10ms_);                           //thus, make do it! Enable the Cyclic timer to interrupt event for each 10 ms
                    }            
                    break;                                                      //get out this loop!
          }//end case _10ms_ 

          
          case _50ms_:{                                                       
                    _CLUSTER_target_50 = _ENABLED_;                           
                    if( isTimerActive(t_50ms) ){                         
                      write("Timer already previous set by user!");      
                    }
                    else{                 
                      write("_IPC_ 50ms message will be send!\n");    
                      setTimerCyclic(t_50ms,_10ms_);                   
                    }          
                    break;                                            
          }//end case _50ms_      

          
          case _100ms_:{                                                
                _CLUSTER_target_100 = _ENABLED_;                                 
                if( isTimerActive(t_100ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{       
                  write("_IPC_ 100ms message will be send!\n");  
                  setTimerCyclic(t_100ms_,_100ms_);                   
                }         
                break;                                              
          }//end case _100ms_ 


          case _150ms_:{                                                
                _CLUSTER_target_150 = _ENABLED_;                                 
                if( isTimerActive(t_150ms_) ){                             
                }
                else{    
                  write("Timer already previous set by user!"); 
                  setTimerCyclic(t_150ms_,_150ms_);                   
                }         
                break;                                              
          }//end case _150ms_ 


          case _200ms_:{                                                
                _CLUSTER_target_200 = _ENABLED_;                          
                if( isTimerActive(t_200ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{     
                  write("_IPC_ 200ms message will be send!\n");    
                  setTimerCyclic(t_200ms_,_200ms_);                   
                }         
                break;                                              
          }//end case _200ms_ 

          
          case _250ms_:{                                                
                _CLUSTER_target_250 = _ENABLED_;                          
                if( isTimerActive(t_250ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{
                  write("_IPC_ 250ms message will be send!\n");
                  setTimerCyclic(t_250ms_,_250ms_);                   
                }         
                break;                                              
          }//end case _250ms_ 

          
          case _300ms_:{                                                
                _CLUSTER_target_300 = _ENABLED_;                                  
                if( isTimerActive(t_300ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{         
                  write("_IPC_ 300ms message will be send!\n");   
                  setTimerCyclic(t_300ms_,_300ms_);                   
                }         
                break;                                              
          }//end case _300ms_ 

          
          case _400ms_:{                                                
                _CLUSTER_target_400 = _ENABLED_;                                   
                if( isTimerActive(t_400ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{  
                  write("_IPC_ 100ms message will be send!\n");  
                  setTimerCyclic(t_400ms_,_400ms_);                   
                }         
                break;                                              
          }//end case _400ms_ 

          
          case _450ms_:{                                                
                _CLUSTER_target_450 = _ENABLED_;                          
                if( isTimerActive(t_450ms_) ){  
                  write("Timer already previous set by user!");      
                }
                else{   
                  write("_IPC_ 450ms message will be send!\n"); 
                  setTimerCyclic(t_450ms_,_450ms_);                   
                }         
                break;                                              
          }//end case _100ms_ 

          
          case _500ms_:{                                                
                _CLUSTER_target_500 = _ENABLED_;                          
                if( isTimerActive(t_500ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{
                  write("_IPC_ 500ms message will be send!\n"); 
                  setTimerCyclic(t_500ms_,_500ms_);                   
                }         
                break;                                              
          }//end case _500ms_ 

          
          case _700ms_:{                                                
                _CLUSTER_target_700 = _ENABLED_;                                 
                if( isTimerActive(t_700ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{ 
                  write("_IPC_ 700ms message will be send!\n");   
                  setTimerCyclic(t_700ms_,_700ms_);                   
                }         
                break;                                              
          }//end case _700ms_ 

          
          case _1000ms_:{                                                
                _CLUSTER_target_1000 = _ENABLED_;                          
                if( isTimerActive(t_1000ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{  
                  write("_IPC_ 1000ms message will be send!\n");
                  setTimerCyclic(t_1000ms_,_1000ms_);                   
                }         
                break;                                              
          }//end case _1000ms_ 

          
          case _1500ms_:{                                                
                _CLUSTER_target_1500 = _ENABLED_;                          
                if( isTimerActive(t_1500ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{                           
                  write("_IPC_ 1500ms message will be send!\n"); 
                  setTimerCyclic(t_1500ms_,_1500ms_);                   
                }         
                break;                                              
          }//end case _1500ms_                                                

          
          case _2000ms_:{                                                
                _CLUSTER_target_2000 = _ENABLED_;                          
                if( isTimerActive(t_2000ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{ 
                  write("_IPC_ 2000ms message will be send!\n"); 
                  setTimerCyclic(t_2000ms_,_2000ms_);                   
                }         
                break;                                              
          }//end case _2000ms_ 

          
          case _2500ms_:{                                                
                _CLUSTER_target_2500 = _ENABLED_;                                    
                if( isTimerActive(t_2500ms_) ){                        
                  write("Timer already previous set by user!");      
                }
                else{   
                  write("_IPC_ 2500ms message will be send!\n"); 
                  setTimerCyclic(t_2500ms_,_2500ms_);                   
                }         
                break;                                              
          }//end case _2500ms_        

          
          default: break;
      }//end case 'x_ms'     
  }//if(_CLUSTER_ == ecu){}
  /* * * * * * * * * * * * * * * * * * * * * * * * * * * * */


    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                        D I S P L A Y
    * * *  * * * * * * * * * * * * * * * * * * * * * * * * * */
    if(_DISPLAY_ == ecu){    

        if(_OFF_ == _DISPLAY_flag_stop){                                            //DISPLAY_FLAG_STOP as default = _off_. See the file 'k_config.can' for more details.
            setTimerCyclic(t_stop_messages_DISPLAY, _T_STOP_MSG_);                  //Starting a timer to enable the service 0x28 UDS PROTOCOL in order to shut up this ECU into CAN bus
        }   

    switch(time){                                                               //check what time was previous selected by user (received by 'time' argument)
            case _10ms_:{                                                         //if 10 milseseconds are choosed, thus .:.
                    _DISPLAY_target_10 = _ENABLED_;                             //enable bcm flag to informe it to another function (to timer schedule ctrl)                                                        
                    //check_timer_10ms = isTimerActive(t_10ms) ;                //Another ECU can being using the 10ms thread time, so:
                    if( isTimerActive(t_10ms) ){                                //Verify if this 'setTimer' is already running to prevent loss of sync
                        write("Timer already previous set by user!");             //Informe it to user in the serial console (trace)
                    }
                    else{                                                       //otherwise, is the 1st time that this time will be set.
                        write("CLUSTER 10ms message will be send!\n");            //Informe it to user in the serial console (trace)
                        setTimerCyclic(t_10ms, _10ms_);                           //thus, make do it! Enable the Cyclic timer to interrupt event for each 10 ms
                    }            
                    break;                                                      //get out this loop!
            }//end case _10ms_ 

            
            case _50ms_:{                                                       
                    _DISPLAY_target_50 = _ENABLED_;                           
                    if( isTimerActive(t_50ms) ){                         
                        write("Timer already previous set by user!");      
                    }
                    else{                 
                        write("_DISPLAY_ 50ms message will be send!\n");    
                        setTimerCyclic(t_50ms,_10ms_);                   
                    }          
                    break;                                            
            }//end case _50ms_      

            
            case _100ms_:{                                                
                _DISPLAY_target_100 = _ENABLED_;                                 
                if( isTimerActive(t_100ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{       
                    write("_DISPLAY_ 100ms message will be send!\n");  
                    setTimerCyclic(t_100ms_,_100ms_);                   
                }         
                break;                                              
            }//end case _100ms_ 


            case _150ms_:{                                                
                _DISPLAY_target_150 = _ENABLED_;                                 
                if( isTimerActive(t_150ms_) ){                             
                }
                else{    
                    write("Timer already previous set by user!"); 
                    setTimerCyclic(t_150ms_,_150ms_);                   
                }         
                break;                                              
            }//end case _150ms_ 


            case _200ms_:{                                                
                _DISPLAY_target_200 = _ENABLED_;                          
                if( isTimerActive(t_200ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{     
                    write("_DISPLAY_ 200ms message will be send!\n");    
                    setTimerCyclic(t_200ms_,_200ms_);                   
                }         
                break;                                              
            }//end case _200ms_ 

            
            case _250ms_:{                                                
                _DISPLAY_target_250 = _ENABLED_;                          
                if( isTimerActive(t_250ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{
                    write("_DISPLAY_ 250ms message will be send!\n");
                    setTimerCyclic(t_250ms_,_250ms_);                   
                }         
                break;                                              
            }//end case _250ms_ 

            
            case _300ms_:{                                                
                _DISPLAY_target_300 = _ENABLED_;                                  
                if( isTimerActive(t_300ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{         
                    write("_DISPLAY_ 300ms message will be send!\n");   
                    setTimerCyclic(t_300ms_,_300ms_);                   
                }         
                break;                                              
            }//end case _300ms_ 

            
            case _400ms_:{                                                
                _DISPLAY_target_400 = _ENABLED_;                                   
                if( isTimerActive(t_400ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{  
                    write("_DISPLAY_ 100ms message will be send!\n");  
                    setTimerCyclic(t_400ms_,_400ms_);                   
                }         
                break;                                              
            }//end case _400ms_ 

            
            case _450ms_:{                                                
                _DISPLAY_target_450 = _ENABLED_;                          
                if( isTimerActive(t_450ms_) ){  
                    write("Timer already previous set by user!");      
                }
                else{   
                    write("_DISPLAY_ 450ms message will be send!\n"); 
                    setTimerCyclic(t_450ms_,_450ms_);                   
                }         
                break;                                              
            }//end case _100ms_ 

            
            case _500ms_:{                                                
                _DISPLAY_target_500 = _ENABLED_;                          
                if( isTimerActive(t_500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{
                    write("_DISPLAY_ 500ms message will be send!\n"); 
                    setTimerCyclic(t_500ms_,_500ms_);                   
                }         
                break;                                              
            }//end case _500ms_ 

            
            case _700ms_:{                                                
                _DISPLAY_target_700 = _ENABLED_;                                 
                if( isTimerActive(t_700ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{ 
                    write("_DISPLAY_ 700ms message will be send!\n");   
                    setTimerCyclic(t_700ms_,_700ms_);                   
                }         
                break;                                              
            }//end case _700ms_ 

            
            case _1000ms_:{                                                
                _DISPLAY_target_1000 = _ENABLED_;                          
                if( isTimerActive(t_1000ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{  
                    write("_DISPLAY_ 1000ms message will be send!\n");
                    setTimerCyclic(t_1000ms_,_1000ms_);                   
                }         
                break;                                              
            }//end case _1000ms_ 

            
            case _1500ms_:{                                                
                _DISPLAY_target_1500 = _ENABLED_;                          
                if( isTimerActive(t_1500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{                           
                    write("_DISPLAY_ 1500ms message will be send!\n"); 
                    setTimerCyclic(t_1500ms_,_1500ms_);                   
                }         
                break;                                              
            }//end case _1500ms_                                                

            
            case _2000ms_:{                                                
                _DISPLAY_target_2000 = _ENABLED_;                          
                if( isTimerActive(t_2000ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{ 
                    write("_DISPLAY_ 2000ms message will be send!\n"); 
                    setTimerCyclic(t_2000ms_,_2000ms_);                   
                }         
                break;                                              
            }//end case _2000ms_ 

            
            case _2500ms_:{                                                
                _DISPLAY_target_2500 = _ENABLED_;                                    
                if( isTimerActive(t_2500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{   
                    write("_DISPLAY_ 2500ms message will be send!\n"); 
                    setTimerCyclic(t_2500ms_,_2500ms_);                   
                }         
                break;                                              
            }//end case _2500ms_        

            
            default: break;
        }//end case 'x_ms'     
    }//if(_DISPLAY_ == ecu){}
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * */



    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                            L I D A R
    * * *  * * * * * * * * * * * * * * * * * * * * * * * * * */
    if(_LIDAR_ == ecu){    

        if(_OFF_ == _LIDAR_flag_stop){                                            //LIDAR_FLAG_STOP as default = _off_. See the file 'k_config.can' for more details.
            setTimerCyclic(t_stop_messages_LIDAR, _T_STOP_MSG_);                  //Starting a timer to enable the service 0x28 UDS PROTOCOL in order to shut up this ECU into CAN bus
        }   

    switch(time){                                                               //check what time was previous selected by user (received by 'time' argument)
            case _10ms_:{                                                         //if 10 milseseconds are choosed, thus .:.
                    _LIDAR_target_10 = _ENABLED_;                               //enable bcm flag to informe it to another function (to timer schedule ctrl)                                                        
                    //check_timer_10ms = isTimerActive(t_10ms) ;                //Another ECU can being using the 10ms thread time, so:
                    if( isTimerActive(t_10ms) ){                                //Verify if this 'setTimer' is already running to prevent loss of sync
                        write("Timer already previous set by user!");             //Informe it to user in the serial console (trace)
                    }
                    else{                                                       //otherwise, is the 1st time that this time will be set.
                        write("CLUSTER 10ms message will be send!\n");            //Informe it to user in the serial console (trace)
                        setTimerCyclic(t_10ms, _10ms_);                           //thus, make do it! Enable the Cyclic timer to interrupt event for each 10 ms
                    }            
                    break;                                                      //get out this loop!
            }//end case _10ms_ 

            
            case _50ms_:{                                                       
                    _LIDAR_target_50 = _ENABLED_;                           
                    if( isTimerActive(t_50ms) ){                         
                        write("Timer already previous set by user!");      
                    }
                    else{                 
                        write("_LIDAR_ 50ms message will be send!\n");    
                        setTimerCyclic(t_50ms,_10ms_);                   
                    }          
                    break;                                            
            }//end case _50ms_      

            
            case _100ms_:{                                                
                _LIDAR_target_100 = _ENABLED_;                                 
                if( isTimerActive(t_100ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{       
                    write("_LIDAR_ 100ms message will be send!\n");  
                    setTimerCyclic(t_100ms_,_100ms_);                   
                }         
                break;                                              
            }//end case _100ms_ 


            case _150ms_:{                                                
                _LIDAR_target_150 = _ENABLED_;                                 
                if( isTimerActive(t_150ms_) ){                             
                }
                else{    
                    write("Timer already previous set by user!"); 
                    setTimerCyclic(t_150ms_,_150ms_);                   
                }         
                break;                                              
            }//end case _150ms_ 


            case _200ms_:{                                                
                _LIDAR_target_200 = _ENABLED_;                          
                if( isTimerActive(t_200ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{     
                    write("_LIDAR_ 200ms message will be send!\n");    
                    setTimerCyclic(t_200ms_,_200ms_);                   
                }         
                break;                                              
            }//end case _200ms_ 

            
            case _250ms_:{                                                
                _LIDAR_target_250 = _ENABLED_;                          
                if( isTimerActive(t_250ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{
                    write("_LIDAR_ 250ms message will be send!\n");
                    setTimerCyclic(t_250ms_,_250ms_);                   
                }         
                break;                                              
            }//end case _250ms_ 

            
            case _300ms_:{                                                
                _LIDAR_target_300 = _ENABLED_;                                  
                if( isTimerActive(t_300ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{         
                    write("_LIDAR_ 300ms message will be send!\n");   
                    setTimerCyclic(t_300ms_,_300ms_);                   
                }         
                break;                                              
            }//end case _300ms_ 

            
            case _400ms_:{                                                
                _LIDAR_target_400 = _ENABLED_;                                   
                if( isTimerActive(t_400ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{  
                    write("_LIDAR_ 100ms message will be send!\n");  
                    setTimerCyclic(t_400ms_,_400ms_);                   
                }         
                break;                                              
            }//end case _400ms_ 

            
            case _450ms_:{                                                
                _LIDAR_target_450 = _ENABLED_;                          
                if( isTimerActive(t_450ms_) ){  
                    write("Timer already previous set by user!");      
                }
                else{   
                    write("_LIDAR_ 450ms message will be send!\n"); 
                    setTimerCyclic(t_450ms_,_450ms_);                   
                }         
                break;                                              
            }//end case _100ms_ 

            
            case _500ms_:{                                                
                _LIDAR_target_500 = _ENABLED_;                          
                if( isTimerActive(t_500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{
                    write("_LIDAR_ 500ms message will be send!\n"); 
                    setTimerCyclic(t_500ms_,_500ms_);                   
                }         
                break;                                              
            }//end case _500ms_ 

            
            case _700ms_:{                                                
                _LIDAR_target_700 = _ENABLED_;                                 
                if( isTimerActive(t_700ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{ 
                    write("_LIDAR_ 700ms message will be send!\n");   
                    setTimerCyclic(t_700ms_,_700ms_);                   
                }         
                break;                                              
            }//end case _700ms_ 

            
            case _1000ms_:{                                                
                _LIDAR_target_1000 = _ENABLED_;                          
                if( isTimerActive(t_1000ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{  
                    write("_LIDAR_ 1000ms message will be send!\n");
                    setTimerCyclic(t_1000ms_,_1000ms_);                   
                }         
                break;                                              
            }//end case _1000ms_ 

            
            case _1500ms_:{                                                
                _LIDAR_target_1500 = _ENABLED_;                          
                if( isTimerActive(t_1500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{                           
                    write("_LIDAR_ 1500ms message will be send!\n"); 
                    setTimerCyclic(t_1500ms_,_1500ms_);                   
                }         
                break;                                              
            }//end case _1500ms_                                                

            
            case _2000ms_:{                                                
                _LIDAR_target_2000 = _ENABLED_;                          
                if( isTimerActive(t_2000ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{ 
                    write("_LIDAR_ 2000ms message will be send!\n"); 
                    setTimerCyclic(t_2000ms_,_2000ms_);                   
                }         
                break;                                              
            }//end case _2000ms_ 

            
            case _2500ms_:{                                                
                _LIDAR_target_2500 = _ENABLED_;                                    
                if( isTimerActive(t_2500ms_) ){                        
                    write("Timer already previous set by user!");      
                }
                else{   
                    write("_LIDAR_ 2500ms message will be send!\n"); 
                    setTimerCyclic(t_2500ms_,_2500ms_);                   
                }         
                break;                                              
            }//end case _2500ms_        

            
            default: break;
        }//end case 'x_ms'     
    }//if(_LIDAR_ == ecu){}
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * */


    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                        H E A D   U N I T 
    * * *  * * * * * * * * * * * * * * * * * * * * * * * * * */
    if(_HU_ == ecu){    

        if(_OFF_ == _HU_flag_stop){                                            //HU_FLAG_STOP as default = _off_. See the file 'k_config.can' for more details.
            setTimerCyclic(t_stop_messages_HU, _T_STOP_MSG_);                  //Starting a timer to enable the service 0x28 UDS PROTOCOL in order to shut up this ECU into CAN bus
        }   

        switch(time){                                                               //check what time was previous selected by user (received by 'time' argument)
                case _10ms_:{                                                         //if 10 milseseconds are choosed, thus .:.
                        _HU_target_10 = _ENABLED_;                               //enable bcm flag to informe it to another function (to timer schedule ctrl)                                                        
                        //check_timer_10ms = isTimerActive(t_10ms) ;                //Another ECU can being using the 10ms thread time, so:
                        if( isTimerActive(t_10ms) ){                                //Verify if this 'setTimer' is already running to prevent loss of sync
                            write("Timer already previous set by user!");             //Informe it to user in the serial console (trace)
                        }
                        else{                                                       //otherwise, is the 1st time that this time will be set.
                            write("CLUSTER 10ms message will be send!\n");            //Informe it to user in the serial console (trace)
                            setTimerCyclic(t_10ms, _10ms_);                           //thus, make do it! Enable the Cyclic timer to interrupt event for each 10 ms
                        }            
                        break;                                                      //get out this loop!
                }//end case _10ms_ 

                
                case _50ms_:{                                                       
                        _HU_target_50 = _ENABLED_;                           
                        if( isTimerActive(t_50ms) ){                         
                            write("Timer already previous set by user!");      
                        }
                        else{                 
                            write("_HU_ 50ms message will be send!\n");    
                            setTimerCyclic(t_50ms,_10ms_);                   
                        }          
                        break;                                            
                }//end case _50ms_      

                
                case _100ms_:{                                                
                    _HU_target_100 = _ENABLED_;                                 
                    if( isTimerActive(t_100ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{       
                        write("_HU_ 100ms message will be send!\n");  
                        setTimerCyclic(t_100ms_,_100ms_);                   
                    }         
                    break;                                              
                }//end case _100ms_ 


                case _150ms_:{                                                
                    _HU_target_150 = _ENABLED_;                                 
                    if( isTimerActive(t_150ms_) ){                             
                    }
                    else{    
                        write("Timer already previous set by user!"); 
                        setTimerCyclic(t_150ms_,_150ms_);                   
                    }         
                    break;                                              
                }//end case _150ms_ 


                case _200ms_:{                                                
                    _HU_target_200 = _ENABLED_;                          
                    if( isTimerActive(t_200ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{     
                        write("_HU_ 200ms message will be send!\n");    
                        setTimerCyclic(t_200ms_,_200ms_);                   
                    }         
                    break;                                              
                }//end case _200ms_ 

                
                case _250ms_:{                                                
                    _HU_target_250 = _ENABLED_;                          
                    if( isTimerActive(t_250ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{
                        write("_HU_ 250ms message will be send!\n");
                        setTimerCyclic(t_250ms_,_250ms_);                   
                    }         
                    break;                                              
                }//end case _250ms_ 

                
                case _300ms_:{                                                
                    _HU_target_300 = _ENABLED_;                                  
                    if( isTimerActive(t_300ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{         
                        write("_HU_ 300ms message will be send!\n");   
                        setTimerCyclic(t_300ms_,_300ms_);                   
                    }         
                    break;                                              
                }//end case _300ms_ 

                
                case _400ms_:{                                                
                    _HU_target_400 = _ENABLED_;                                   
                    if( isTimerActive(t_400ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{  
                        write("_HU_ 100ms message will be send!\n");  
                        setTimerCyclic(t_400ms_,_400ms_);                   
                    }         
                    break;                                              
                }//end case _400ms_ 

                
                case _450ms_:{                                                
                    _HU_target_450 = _ENABLED_;                          
                    if( isTimerActive(t_450ms_) ){  
                        write("Timer already previous set by user!");      
                    }
                    else{   
                        write("_HU_ 450ms message will be send!\n"); 
                        setTimerCyclic(t_450ms_,_450ms_);                   
                    }         
                    break;                                              
                }//end case _100ms_ 

                
                case _500ms_:{                                                
                    _HU_target_500 = _ENABLED_;                          
                    if( isTimerActive(t_500ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{
                        write("_HU_ 500ms message will be send!\n"); 
                        setTimerCyclic(t_500ms_,_500ms_);                   
                    }         
                    break;                                              
                }//end case _500ms_ 

                
                case _700ms_:{                                                
                    _HU_target_700 = _ENABLED_;                                 
                    if( isTimerActive(t_700ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{ 
                        write("_HU_ 700ms message will be send!\n");   
                        setTimerCyclic(t_700ms_,_700ms_);                   
                    }         
                    break;                                              
                }//end case _700ms_ 

                
                case _1000ms_:{                                                
                    _HU_target_1000 = _ENABLED_;                          
                    if( isTimerActive(t_1000ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{  
                        write("_HU_ 1000ms message will be send!\n");
                        setTimerCyclic(t_1000ms_,_1000ms_);                   
                    }         
                    break;                                              
                }//end case _1000ms_ 

                
                case _1500ms_:{                                                
                    _HU_target_1500 = _ENABLED_;                          
                    if( isTimerActive(t_1500ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{                           
                        write("_HU_ 1500ms message will be send!\n"); 
                        setTimerCyclic(t_1500ms_,_1500ms_);                   
                    }         
                    break;                                              
                }//end case _1500ms_                                                

                
                case _2000ms_:{                                                
                    _HU_target_2000 = _ENABLED_;                          
                    if( isTimerActive(t_2000ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{ 
                        write("_HU_ 2000ms message will be send!\n"); 
                        setTimerCyclic(t_2000ms_,_2000ms_);                   
                    }         
                    break;                                              
                }//end case _2000ms_ 

                
                case _2500ms_:{                                                
                    _HU_target_2500 = _ENABLED_;                                    
                    if( isTimerActive(t_2500ms_) ){                        
                        write("Timer already previous set by user!");      
                    }
                    else{   
                        write("_HU_ 2500ms message will be send!\n"); 
                        setTimerCyclic(t_2500ms_,_2500ms_);                   
                    }         
                    break;                                              
                }//end case _2500ms_        

                
                default: break;
        }//end case 'x_ms'     
    }//if(_HU_ == ecu){}
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

}//END StartSimulation()
  
