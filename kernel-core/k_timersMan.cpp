/*@!Encoding:1252*/
variables{}



/**===========================================================================================================================**/
/**************************                             CANCEL TIMERS                           ********************************/
/**===========================================================================================================================**/
void Cancel_All_Timers(){
  //stop all timers from application layer
  cancelTimer(t_2500ms_);
  cancelTimer(t_2000ms_); 
  cancelTimer(t_1500ms_);
  cancelTimer(t_1000ms_);
  cancelTimer(t_750ms_);
  cancelTimer(t_700ms_);
  cancelTimer(t_500ms_);
  cancelTimer(t_450ms_);
  cancelTimer(t_400ms_);
  cancelTimer(t_350ms_);
  cancelTimer(t_300ms_);
  cancelTimer(t_250ms_);
  cancelTimer(t_200ms_);
  cancelTimer(t_150ms_);
  cancelTimer(t_100ms_);
  cancelTimer(t_50ms_);
  cancelTimer(t_10ms_);
  cancelTimer(t_vin);

  //stop all timers from diangostic layer
  cancelTimer(t_tester_present);
  cancelTimer(t_stop_messages_gateway);
  cancelTimer(t_stop_messages_cluster);
  cancelTimer(t_stop_messages_display);
  cancelTimer(t_stop_messages_cluster);
  cancelTimer(t_stop_messages_lidar);
  cancelTimer(t_stop_messages_hu); 
}
/**___________________________________________________________________________________________________________________________**/



/**===========================================================================================================================**/
/**************************                          DIAGNOSTIC LAYER                           ********************************/
/**===========================================================================================================================**/
/**
    T E S T E R   P R E S E N T
*/
on timer t_tester_present{
    if (_ON_ == _GATEWAY_TARGET_TESTER_PRESENT){
        //entering extended session
        write("******************************");
        write("    TESTER_PRESENT >>> GTW    ");
        write("******************************");
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(0) = 0x02; 
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(1) = 0x3E;
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(2) = 0x00;
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(3) = 0x00;
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(4) = 0x00;
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(5) = 0x00;
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(6) = 0x00;
        MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(7) = 0x00;
        output(MY_DIAGNOSTIC_REQUEST_GATEWAY);     
    }
    if (_ON_ == _CLUSTER_TARGET_TESTER_PRESENT){
        //entering extended session
        write("******************************");
        write("    ESTER_PRESENT >>> CLSTR   ");
        write("******************************");
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(0) = 0x02; 
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(1) = 0x3E;
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(2) = 0x00;
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(3) = 0x00;
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(4) = 0x00;
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(5) = 0x00;
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(6) = 0x00;
        MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(7) = 0x00;
        output(MY_DIAGNOSTIC_REQUEST_CLUSTER); 
    }
    if (_ON_ == _DISPLAY_TARGET_TESTER_PRESENT){
        //entering extended session
        write("******************************");
        write("  TESTER_PRESENT >>> DSPLY    ");
        write("******************************");
        //MY_DIAGNOSTIC_REQUEST_BCM.DataLength = 8;
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(0) = 0x02; 
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(1) = 0x3E;
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(2) = 0x00;
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(3) = 0x00;
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(4) = 0x00;
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(5) = 0x00;
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(6) = 0x00;
        MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(7) = 0x00;
        output(MY_DIAGNOSTIC_REQUEST_DISPLAY);     
    }
    if (_ON_ == _LIDAR_TARGET_TESTER_PRESENT){
        //entering extended session
        write("******************************");
        write("  TESTER_PRESENT >>> LIDR     ");
        write("******************************");
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(0) = 0x02; 
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(1) = 0x3E;
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(2) = 0x00;
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(3) = 0x00;
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(4) = 0x00;
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(5) = 0x00;
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(6) = 0x00;
        MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(7) = 0x00;
        output(MY_DIAGNOSTIC_REQUEST_LIDAR);     
    }
    if (_ON_ == _LIDAR_TARGET_TESTER_PRESENT){
        //entering extended session
        write("******************************");
        write("  TESTER_PRESENT >>> HU       ");
        write("******************************");
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(0) = 0x02; 
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(1) = 0x3E;
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(2) = 0x00;
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(3) = 0x00;
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(4) = 0x00;
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(5) = 0x00;
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(6) = 0x00;
        MY_DIAGNOSTIC_REQUEST_HU.BYTE(7) = 0x00;
        output(MY_DIAGNOSTIC_REQUEST_LIDAR);     
    }
}




/**
    SHUT UP THE TARGET ECU UNDER 0x28 ISO14229 (UDS PROTOCOL)
    ps.: If ecu not get extended session, please change the default value to _EXTENDED_SESSION_ over k_config.can file
    also, start this machine state directaly in the state (_EXTENDED_SESSION_). I don't know the reason but, for some ecus, somehow this approach work better.
*/
//G A T E W A Y
on timer t_stop_messages_gateway{
  if (_OFF_ == _GATEWAY_flag_stop){                                              //as default (see file k_config.can), this flag is set as OFF. So, when this function will invoked, the condition will be True
      switch(_GATEWAY_diag_case){                                                  //ECU_diag_case is previously set as _DEFAULT_SESSION_ (check the same file as well)
          case _DEFAULT_SESSION_ :{                                                //so, in the first loop of cyclic timer 't_stop_messages_ecu', I'll send $1001
                                    //entering DEFAULT session
                                    write("\nDEFAULT SESSION\n");
                                    //MY_DIAGNOSTIC_REQUEST_GATEWAY.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_GATEWAY);          //Sending $1001
                                    _GATEWAY_diag_case = _EXTENDED_SESSION_;       //Chaning the flag value. In the next loop we need to enter in the extended session.
                                    break;                                         
          }
          case _EXTENDED_SESSION_ :{                                              
                                    write("\nEXTENDED SESSION\n");                  //Now, the flag was previously set as _EXTENDED_SESSION_ (due the last loop event)
                                    //MY_DIAGNOSTIC_REQUEST_GATEWAY.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(2) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_GATEWAY);          //sending $1003
                                    _GATEWAY_diag_case = _TESTER_PRESENT_;          //On the next loop, I have to send the tester_present event (3e 00)
                                    break;                                       
          }    
          case _TESTER_PRESENT_ :{          
                                    //enable the tester present service             //Setting another cyclic timer (to the tester present to be sent periodicaly as well)
                                    write("GATEWAY TESTER PRESENT");              
                                    _GATEWAY_target_tester_present = _ON_;          //setting the Tester_Present flag as _ON_ to this ECU 
                                    
                                    if( isTimerActive(t_tester_present) ){                        
                                        write("TESTER PRESENT MACHINE already previously set by user!");      //if this timer is already running, I have nothing to do...
                                    }
                                    else{                                                                     //otherwise, I have to set this cyclic timer with the time value previously configured on k_configure.can file
                                        setTimerCyclic(t_tester_present, _T_TESTER_PRESENT_);                 //inicio o timer ciclico de tester present              
                                    }   

                                    //MY_DIAGNOSTIC_REQUEST_CLUSTER.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(0) = 0x02;                               
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(1) = 0x3e; 
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(2) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_GATEWAY);                                   //Sending $3e00 
                                    _GATEWAY_diag_case = _STOP_MESSAGE_;                                     //Finaly I have to send the message to shut up the ECU in the next loop. So, I have to change the flag value           
            
          }
          case _STOP_MESSAGE_ :{                              
                                    //sending 28 01 03 (stop all messages)
                                    write("GATEWAY, Please, SHUT UP!!!!");                                  //In the last loop of this machine of states I have to send 28 01 03 so shut up the target ecu
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(0) = 0x03; 
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(1) = 0x28; 
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(3) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_GATEWAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_GATEWAY);                                  //sending $280103
                                   
                                    _GATEWAY_flag_stop = _ON_;                                              //cleaning the flag to enable another call in the futere
                                    _GATEWAY_diag_case = _DEFAULT_SESSION_;                                 //changing this other flag to their default value
                                    break;                                         
          }

          default:                {
                                    _GATEWAY_flag_stop = _ON_; 
                                    _GATEWAY_diag_case = _DEFAULT_SESSION_;
                                    cancelTimer(t_stop_messages_gateway);                                   //if something get wrong, I have to cancel I timers to guarantee that no one message will be sent.
                                    break;
          }//end default
      }//end _GATEWAY_diag_case  
   }//end  _GATEWAY_flag_stop
}//on timer (t_stop_messages_gateway)


//C L U S T E R
on timer t_stop_messages_cluster{
  if (_OFF_ == _CLUSTER_flag_stop){                                                //as default (see file k_config.can), this flag is set as OFF. So, when this function will invoked, the condition will be True
      switch(_CLUSTER_diag_case){                                                  //ECU_diag_case is previously set as _DEFAULT_SESSION_ (check the same file as well)
          case _DEFAULT_SESSION_ :{                                                //so, in the first loop of cyclic timer 't_stop_messages_ecu', I'll send $1001
                                    //entering DEFAULT session
                                    write("\nDEFAULT SESSION\n");
                                    //MY_DIAGNOSTIC_REQUEST_CLUSTER.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_CLUSTER);          //Sending $1001
                                    _CLUSTER_diag_case = _EXTENDED_SESSION_;       //Chaning the flag value. In the next loop we need to enter in the extended session.
                                    break;                                         
          }
          case _EXTENDED_SESSION_ :{                                              
                                    write("\nEXTENDED SESSION\n");                  //Now, the flag was previously set as _EXTENDED_SESSION_ (due the last loop event)
                                    //MY_DIAGNOSTIC_REQUEST_CLUSTER.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(2) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_CLUSTER);          //sending $1003
                                    _CLUSTER_diag_case = _TESTER_PRESENT_;          //On the next loop, I have to send the tester_present event (3e 00)
                                    break;                                       
          }    
          case _TESTER_PRESENT_ :{          
                                    //enable the tester present service             //Setting another cyclic timer (to the tester present to be sent periodicaly as well)
                                    write("CLUSTER TESTER PRESENT");              
                                    _CLUSTER_target_tester_present = _ON_;          //setting the Tester_Present flag as _ON_ to this ECU 
                                    
                                    if( isTimerActive(t_tester_present) ){                        
                                        write("TESTER PRESENT MACHINE already previously set by user!");      //if this timer is already running, I have nothing to do...
                                    }
                                    else{                                                                     //otherwise, I have to set this cyclic timer with the time value previously configured on k_configure.can file
                                        setTimerCyclic(t_tester_present, _T_TESTER_PRESENT_);                 //inicio o timer ciclico de tester present              
                                    }   

                                    //MY_DIAGNOSTIC_REQUEST_CLUSTER.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(0) = 0x02;                               
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(1) = 0x3e; 
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(2) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_CLUSTER);                                   //Sending $3e00 
                                    _CLUSTER_diag_case = _STOP_MESSAGE_;                                     //Finaly I have to send the message to shut up the ECU in the next loop. So, I have to change the flag value           
            
          }
          case _STOP_MESSAGE_ :{                              
                                    //sending 28 01 03 (stop all messages)
                                    write("CLUSTER, Please, SHUT UP!!!!");                                  //In the last loop of this machine of states I have to send 28 01 03 so shut up the target ecu
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(0) = 0x03; 
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(1) = 0x28; 
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(3) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_CLUSTER.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_CLUSTER);                                  //sending $280103
                                   
                                    _CLUSTER_flag_stop = _ON_;                                              //cleaning the flag to enable another call in the futere
                                    _CLUSTER_diag_case = _DEFAULT_SESSION_;                                 //changing this other flag to their default value
                                    break;                                         
          }

          default:                {
                                    _CLUSTER_flag_stop = _ON_; 
                                    _CLUSTER_diag_case = _DEFAULT_SESSION_;
                                    cancelTimer(t_stop_messages_cluster);                                   //if something get wrong, I have to cancel I timers to guarantee that no one message will be sent.
                                    break;
          }//end default
      }//end _CLUSTER_diag_case  
   }//end  _CLUSTER_flag_stop
}//on timer (t_stop_messages_cluster)


//D I S P L A Y
on timer t_stop_messages_display{
  if (_OFF_ == _DISPLAY_flag_stop){                                                //as default (see file k_config.can), this flag is set as OFF. So, when this function will invoked, the condition will be True
      switch(_DISPLAY_diag_case){                                                  //ECU_diag_case is previously set as _DEFAULT_SESSION_ (check the same file as well)
          case _DEFAULT_SESSION_ :{                                                //so, in the first loop of cyclic timer 't_stop_messages_ecu', I'll send $1001
                                    //entering DEFAULT session
                                    write("\nDEFAULT SESSION\n");
                                    //MY_DIAGNOSTIC_REQUEST_DISPLAY.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_DISPLAY);          //Sending $1001
                                    _DISPLAY_diag_case = _EXTENDED_SESSION_;        //Chaning the flag value. In the next loop we need to enter in the extended session.
                                    break;                                         
          }
          case _EXTENDED_SESSION_ :{                                              
                                    write("\nEXTENDED SESSION\n");                  //Now, the flag was previously set as _EXTENDED_SESSION_ (due the last loop event)
                                    //MY_DIAGNOSTIC_REQUEST_DISPLAY.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(2) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_DISPLAY);          //sending $1003
                                    _DISPLAY_diag_case = _TESTER_PRESENT_;          //On the next loop, I have to send the tester_present event (3e 00)
                                    break;                                       
          }    
          case _TESTER_PRESENT_ :{          
                                    //enable the tester present service             //Setting another cyclic timer (to the tester present to be sent periodicaly as well)
                                    write("DISPLAY TESTER PRESENT");              
                                    _DISPLAY_target_tester_present = _ON_;          //setting the Tester_Present flag as _ON_ to this ECU 
                                    
                                    if( isTimerActive(t_tester_present) ){                        
                                        write("TESTER PRESENT MACHINE already previously set by user!");      //if this timer is already running, I have nothing to do...
                                    }
                                    else{                                                                     //otherwise, I have to set this cyclic timer with the time value previously configured on k_configure.can file
                                        setTimerCyclic(t_tester_present, _T_TESTER_PRESENT_);                 //inicio o timer ciclico de tester present              
                                    }   

                                    //MY_DIAGNOSTIC_REQUEST_CLUSTER.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(0) = 0x02;                               
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(1) = 0x3e; 
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(2) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_DISPLAY);                                   //Sending $3e00 
                                    _DISPLAY_diag_case = _STOP_MESSAGE_;                                     //Finaly I have to send the message to shut up the ECU in the next loop. So, I have to change the flag value           
            
          }
          case _STOP_MESSAGE_ :{                              
                                    //sending 28 01 03 (stop all messages)
                                    write("CLUSTER, Please, SHUT UP!!!!");                                  //In the last loop of this machine of states I have to send 28 01 03 so shut up the target ecu
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(0) = 0x03; 
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(1) = 0x28; 
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(3) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_DISPLAY.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_DISPLAY);                                  //sending $280103
                                   
                                    _DISPLAY_flag_stop = _ON_;                                              //cleaning the flag to enable another call in the futere
                                    _DISPLAY_diag_case = _DEFAULT_SESSION_;                                 //changing this other flag to their default value
                                    break;                                         
          }

          default:                {
                                    _DISPLAY_flag_stop = _ON_; 
                                    _DISPLAY_diag_case = _DEFAULT_SESSION_;
                                    cancelTimer(t_stop_messages_display);                                   //if something get wrong, I have to cancel I timers to guarantee that no one message will be sent.
                                    break;
          }//end default
      }//end _DISPLAY_diag_case  
   }//end  _DISPLAY_flag_stop
}//on timer (t_stop_messages_display)


//L I D A R
on timer t_stop_messages_lidar{
  if (_OFF_ == _LIDAR_flag_stop){                                                //as default (see file k_config.can), this flag is set as OFF. So, when this function will invoked, the condition will be True
      switch(_LIDAR_diag_case){                                                  //ECU_diag_case is previously set as _DEFAULT_SESSION_ (check the same file as well)
          case _DEFAULT_SESSION_ :{                                                //so, in the first loop of cyclic timer 't_stop_messages_ecu', I'll send $1001
                                    //entering DEFAULT session
                                    write("\nDEFAULT SESSION\n");
                                    //MY_DIAGNOSTIC_REQUEST_LIDAR.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_LIDAR);          //Sending $1001
                                    _LIDAR_diag_case = _EXTENDED_SESSION_;        //Chaning the flag value. In the next loop we need to enter in the extended session.
                                    break;                                         
          }
          case _EXTENDED_SESSION_ :{                                              
                                    write("\nEXTENDED SESSION\n");                  //Now, the flag was previously set as _EXTENDED_SESSION_ (due the last loop event)
                                    //MY_DIAGNOSTIC_REQUEST_LIDAR.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(2) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_LIDAR);          //sending $1003
                                    LIDAR_diag_case = _TESTER_PRESENT_;          //On the next loop, I have to send the tester_present event (3e 00)
                                    break;                                       
          }    
          case _TESTER_PRESENT_ :{          
                                    //enable the tester present service             //Setting another cyclic timer (to the tester present to be sent periodicaly as well)
                                    write("LIDAR TESTER PRESENT");              
                                    _LIDAR_target_tester_present = _ON_;          //setting the Tester_Present flag as _ON_ to this ECU 
                                    
                                    if( isTimerActive(t_tester_present) ){                        
                                        write("TESTER PRESENT MACHINE already previously set by user!");      //if this timer is already running, I have nothing to do...
                                    }
                                    else{                                                                     //otherwise, I have to set this cyclic timer with the time value previously configured on k_configure.can file
                                        setTimerCyclic(t_tester_present, _T_TESTER_PRESENT_);                 //inicio o timer ciclico de tester present              
                                    }   

                                    //MY_DIAGNOSTIC_REQUEST_LIDAR.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(0) = 0x02;                               
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(1) = 0x3e; 
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(2) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_LIDAR);                                   //Sending $3e00 
                                    _LIDAR_diag_case = _STOP_MESSAGE_;                                     //Finaly I have to send the message to shut up the ECU in the next loop. So, I have to change the flag value           
            
          }
          case _STOP_MESSAGE_ :{                              
                                    //sending 28 01 03 (stop all messages)
                                    write("LIDAR, Please, SHUT UP!!!!");                                  //In the last loop of this machine of states I have to send 28 01 03 so shut up the target ecu
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(0) = 0x03; 
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(1) = 0x28; 
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(3) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_LIDAR.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_LIDAR;                                  //sending $280103
                                   
                                    _LIDAR_flag_stop = _ON_;                                              //cleaning the flag to enable another call in the futere
                                    _LIDAR_diag_case = _DEFAULT_SESSION_;                                 //changing this other flag to their default value
                                    break;                                         
          }

          default:                {
                                    _LIDAR_flag_stop = _ON_; 
                                    _LIDAR_diag_case = _DEFAULT_SESSION_;
                                    cancelTimer(t_stop_messages_lidar);                                   //if something get wrong, I have to cancel I timers to guarantee that no one message will be sent.
                                    break;
          }//end default
      }//end _LIDAR_diag_case  
   }//end  _LIDAR_flag_stop
}//on timer (t_stop_messages_lidar)


//H E A D   U N I T
on timer t_stop_messages_lidar{
  if (_OFF_ == _HU_flag_stop){                                                //as default (see file k_config.can), this flag is set as OFF. So, when this function will invoked, the condition will be True
      switch(_HU_diag_case){                                                  //ECU_diag_case is previously set as _DEFAULT_SESSION_ (check the same file as well)
          case _DEFAULT_SESSION_ :{                                                //so, in the first loop of cyclic timer 't_stop_messages_ecu', I'll send $1001
                                    //entering DEFAULT session
                                    write("\nDEFAULT SESSION\n");
                                    //MY_DIAGNOSTIC_REQUEST_HU.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_HU);          //Sending $1001
                                    _HU_diag_case = _EXTENDED_SESSION_;        //Chaning the flag value. In the next loop we need to enter in the extended session.
                                    break;                                         
          }
          case _EXTENDED_SESSION_ :{                                              
                                    write("\nEXTENDED SESSION\n");                  //Now, the flag was previously set as _EXTENDED_SESSION_ (due the last loop event)
                                    //MY_DIAGNOSTIC_REQUEST_HU.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(0) = 0x02; 
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(1) = 0x10; 
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(2) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_HU);          //sending $1003
                                    _HU_diag_case = _TESTER_PRESENT_;          //On the next loop, I have to send the tester_present event (3e 00)
                                    break;                                       
          }    
          case _TESTER_PRESENT_ :{          
                                    //enable the tester present service             //Setting another cyclic timer (to the tester present to be sent periodicaly as well)
                                    write("HU TESTER PRESENT");              
                                    _HU_target_tester_present = _ON_;          //setting the Tester_Present flag as _ON_ to this ECU 
                                    
                                    if( isTimerActive(t_tester_present) ){                        
                                        write("TESTER PRESENT MACHINE already previously set by user!");      //if this timer is already running, I have nothing to do...
                                    }
                                    else{                                                                     //otherwise, I have to set this cyclic timer with the time value previously configured on k_configure.can file
                                        setTimerCyclic(t_tester_present, _T_TESTER_PRESENT_);                 //inicio o timer ciclico de tester present              
                                    }   

                                    //MY_DIAGNOSTIC_REQUEST_HU.dlc = 3;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(0) = 0x02;                               
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(1) = 0x3e; 
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(2) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(3) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_HU);                                   //Sending $3e00 
                                    _HU_diag_case = _STOP_MESSAGE_;                                     //Finaly I have to send the message to shut up the ECU in the next loop. So, I have to change the flag value           
            
          }
          case _STOP_MESSAGE_ :{                              
                                    //sending 28 01 03 (stop all messages)
                                    write("HU, Please, SHUT UP!!!!");                                  //In the last loop of this machine of states I have to send 28 01 03 so shut up the target ecu
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(0) = 0x03; 
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(1) = 0x28; 
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(2) = 0x01;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(3) = 0x03;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(4) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(5) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(6) = 0x00;
                                    MY_DIAGNOSTIC_REQUEST_HU.BYTE(7) = 0x00;
                                    output(MY_DIAGNOSTIC_REQUEST_HU);                                  //sending $280103
                                   
                                    _HU_flag_stop = _ON_;                                              //cleaning the flag to enable another call in the futere
                                    _HU_diag_case = _DEFAULT_SESSION_;                                 //changing this other flag to their default value
                                    break;                                         
          }

          default:                {
                                    _HU_flag_stop = _ON_; 
                                    _HU_diag_case = _DEFAULT_SESSION_;
                                    cancelTimer(t_stop_messages_hu);                                   //if something get wrong, I have to cancel I timers to guarantee that no one message will be sent.
                                    break;
          }//end default
      }//end _HU_diag_case  
   }//end  _HU_flag_stop
}//on timer (t_stop_messages_hu)

/**___________________________________________________________________________________________________________________________**/






/**===========================================================================================================================**/
/**************************               T I M E R   S C H E D U L E   C O N T R O L           ********************************/
/**===========================================================================================================================**/
/* * * * * * * * *
  10 miliseconds
* * * * * * * * */
on timer t_10ms{                                        //When the overflow time to timer 't_10ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_10){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                        //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_10){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_10){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_10){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_10){                                                                                                        
        output();
    }
}//end on timer t_10ms


/* * * * * * * * *
  50 miliseconds
* * * * * * * * */
on timer t_50ms{                                        //When the overflow time to timer 't_50ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_50){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                        //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_50){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_50){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_50){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_50){                                                                                                        
        output();
    }
}//end on timer t_50ms


/* * * * * * * * *
  100 miliseconds
* * * * * * * * */
on timer t_100ms{                                        //When the overflow time to timer 't_100s' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_100){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output(MY_CAN1_BRAKE_STS);
        output(MY_CAN2_CHIMES);
        output(MY_CAN2_BRAKE_STS);
    }
    if(_ENABLED_ == _CLUSTER_TARGET_100){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_100){                                                       
        output(MY_CAN2_DISPLAY_STATUS);
        output(MY_CAN2_DISPLAY_THEFT);
    }
    if(_ENABLED_ == _LIDAR_TARGET_100){                                                                                                       
        output(MY_CAN1_CRASH_WARNING);
        output(MY_CAN2_CRASH_WARNING);
    }
    if(_ENABLED_ == _HU_TARGET_100){                                                                                                        
        output(MY_CAN2_HU_CHIMES);
        output(MY_CAN2_HU_STATUS);
    }
}//end on timer t_100ms


/* * * * * * * * *
  150 miliseconds
* * * * * * * * */
on timer t_150ms{                                        //When the overflow time to timer 't_150ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_150){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_150){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_150){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_150){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_150){                                                                                                        
        output();
    }
}//end on timer t_150ms


/* * * * * * * * *
  200 miliseconds
* * * * * * * * */
on timer t_200ms{                                        //When the overflow time to timer 't_200ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_200){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_200){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_200){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_200){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_200){                                                                                                        
        output();
    }
}//end on timer t_200ms


/* * * * * * * * *
  250 miliseconds
* * * * * * * * */
on timer t_250ms{                                        //When the overflow time to timer 't_250ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_250){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_250){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_250){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_250){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_250){                                                                                                        
        output();
    }
}//end on timer t_250ms


/* * * * * * * * *
  300 miliseconds
* * * * * * * * */
on timer t_300ms{                                        //When the overflow time to timer 't_300ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_300){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_300){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_300){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_300){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_300){                                                                                                        
        output();
    }
}//end on timer t_300ms


/* * * * * * * * *
  350 miliseconds
* * * * * * * * */
on timer t_350ms{                                        //When the overflow time to timer 't_350ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_350){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_350){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_350){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_350){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_350){                                                                                                        
        output();
    }
}//end on timer t_350ms


/* * * * * * * * *
  400 miliseconds
* * * * * * * * */
on timer t_400ms{                                        //When the overflow time to timer 't_400ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_400){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_400){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_400){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_400){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_400){                                                                                                        
        output();
    }
}//end on timer t_400ms


/* * * * * * * * *
  450 miliseconds
* * * * * * * * */
on timer t_450ms{                                        //When the overflow time to timer 't_450ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_450){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_450){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_450){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_450){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_450){                                                                                                        
        output();
    }
}//end on timer t_450ms


/* * * * * * * * *
  500 miliseconds
* * * * * * * * */
on timer t_500ms{                                        //When the overflow time to timer 't_500ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_500){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output(MY_CAN1_VIN);
        output(MY_CAN1_SPEED);
        output(MY_CAN1_RPM);
        output(MY_CAN2_VIN);
        output(MY_CAN2_SPEED);
    }
    if(_ENABLED_ == _CLUSTER_TARGET_500){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_500){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_500){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_500){                                                                                                        
        output();
    }
}//end on timer t_500ms


/* * * * * * * * *
  700 miliseconds
* * * * * * * * */
on timer t_700ms{                                        //When the overflow time to timer 't_700ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_700){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_700){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_700){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_700){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_700){                                                                                                        
        output();
    }
}//end on timer t_700ms


/* * * * * * * * *
  750 miliseconds
* * * * * * * * */
on timer t_750ms{                                        //When the overflow time to timer 't_750ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_750){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                         //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_750){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_750){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_750){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_750){                                                                                                        
        output();
    }
}//end on timer t_750ms


/* * * * * * * * *
  1000 miliseconds
* * * * * * * * */
on timer t_1000ms{                                        //When the overflow time to timer 't_1000ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_1000){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                          //and perform your routine (sent the message)!

        output(MY_CAN1_GATEWAY_STS_DOORS);
        output(MY_CAN2_GATEWAY_STS_DOORS);
    }
    if(_ENABLED_ == _CLUSTER_TARGET_1000){                                                                                                        
        output(MY_CAN1_ODOMETER);
        output(MY_CAN1_TRIP_STATUS);
        output(MY_CAN2_TRIP_STATUS);
    }
    if(_ENABLED_ == _DISPLAY_TARGET_1000){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_1000){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_1000){                                                                                                        
        output();
    }
}//end on timer t_1000ms


/* * * * * * * * *
  1500 miliseconds
* * * * * * * * */
on timer t_1500ms{                                        //When the overflow time to timer 't_1500ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_1500){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                          //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_1500){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_1500){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_1500){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_1500){                                                                                                        
        output();
    }
}//end on timer t_1500ms


/* * * * * * * * *
  2000 miliseconds
* * * * * * * * */
on timer t_2000ms{                                        //When the overflow time to timer 't_2000ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_2000){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                          //and perform your routine (sent the message)!

        output(MY_CAN1_GATEWAY_STS_ENG);
        output(MY_CAN2_GATEWAY_STS_ENG)
    }
    if(_ENABLED_ == _CLUSTER_TARGET_2000){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_2000){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_2000){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_2000){                                                                                                        
        output();
    }
}//end on timer t_2000ms


/* * * * * * * * *
  2500 miliseconds
* * * * * * * * */
on timer t_2500ms{                                        //When the overflow time to timer 't_2500ms' occurs, so.:.
    if(_ENABLED_ == _GATEWAY_TARGET_2500){                //verify which ECU_TARGET are enabled, in this case: gateway was ENABLED?                                           
                                                          //and perform your routine (sent the message)!

        output();
    }
    if(_ENABLED_ == _CLUSTER_TARGET_2500){                                                                                                        
        output();
    }
    if(_ENABLED_ == _DISPLAY_TARGET_2500){                                                       
        output();
    }
    if(_ENABLED_ == _LIDAR_TARGET_2500){                                                                                                       
        output();
    }
    if(_ENABLED_ == _HU_TARGET_2500){                                                                                                        
        output();
    }
}//end on timer t_2500ms


/* * * * * * * * *
  t vin miliseconds
* * * * * * * * */
on timer t_vin{                                            //When the overflow time to timer 't_vin' occurs, so.:.
    switch(vin_part_can1){
        case 0:{
            MY_CAN1_VIN.BYTE(0) = 0x00;
            MY_CAN1_VIN.BYTE(1) = 0x00;
            MY_CAN1_VIN.BYTE(2) = 0x00;
            MY_CAN1_VIN.BYTE(3) = 0x00;
            MY_CAN1_VIN.BYTE(4) = 0x00;
            MY_CAN1_VIN.BYTE(5) = 0x00;
            MY_CAN1_VIN.BYTE(6) = 0x00;
            MY_CAN1_VIN.BYTE(7) = 0x00;
            vin_part_can1 = 0x01;
            break;
        }
        case 1:{
            MY_CAN1_VIN.BYTE(0) = 0x00;
            MY_CAN1_VIN.BYTE(1) = 0x00;
            MY_CAN1_VIN.BYTE(2) = 0x00;
            MY_CAN1_VIN.BYTE(3) = 0x00;
            MY_CAN1_VIN.BYTE(4) = 0x00;
            MY_CAN1_VIN.BYTE(5) = 0x00;
            MY_CAN1_VIN.BYTE(6) = 0x00;
            MY_CAN1_VIN.BYTE(7) = 0x00;
            vin_part_can1 = 0x02;
            break;
        }
        case 2:{
            MY_CAN1_VIN.BYTE(0) = 0x00;
            MY_CAN1_VIN.BYTE(1) = 0x00;
            MY_CAN1_VIN.BYTE(2) = 0x00;
            MY_CAN1_VIN.BYTE(3) = 0x00;
            MY_CAN1_VIN.BYTE(4) = 0x00;
            MY_CAN1_VIN.BYTE(5) = 0x00;
            MY_CAN1_VIN.BYTE(6) = 0x00;
            MY_CAN1_VIN.BYTE(7) = 0x00;
            vin_part_can1 = 0x00;
            break;
        }

    switch(vin_part_can2){
        case 0:{
            MY_CAN2_VIN.BYTE(0) = 0x00;
            MY_CAN2_VIN.BYTE(1) = 0x00;
            MY_CAN2_VIN.BYTE(2) = 0x00;
            MY_CAN2_VIN.BYTE(3) = 0x00;
            MY_CAN2_VIN.BYTE(4) = 0x00;
            MY_CAN2_VIN.BYTE(5) = 0x00;
            MY_CAN2_VIN.BYTE(6) = 0x00;
            MY_CAN2_VIN.BYTE(7) = 0x00;
            vin_part_can2 = 0x01;
            break;
        }
        case 1:{
            MY_CAN2_VIN.BYTE(0) = 0x00;
            MY_CAN2_VIN.BYTE(1) = 0x00;
            MY_CAN2_VIN.BYTE(2) = 0x00;
            MY_CAN2_VIN.BYTE(3) = 0x00;
            MY_CAN2_VIN.BYTE(4) = 0x00;
            MY_CAN2_VIN.BYTE(5) = 0x00;
            MY_CAN2_VIN.BYTE(6) = 0x00;
            MY_CAN2_VIN.BYTE(7) = 0x00;
            vin_part_can2 = 0x02;
            break;
        }
        case 2:{
            MY_CAN2_VIN.BYTE(0) = 0x00;
            MY_CAN2_VIN.BYTE(1) = 0x00;
            MY_CAN2_VIN.BYTE(2) = 0x00;
            MY_CAN2_VIN.BYTE(3) = 0x00;
            MY_CAN2_VIN.BYTE(4) = 0x00;
            MY_CAN2_VIN.BYTE(5) = 0x00;
            MY_CAN2_VIN.BYTE(6) = 0x00;
            MY_CAN2_VIN.BYTE(7) = 0x00;
            vin_part_can2 = 0x00;
            break;
        }
        output(MY_CAN2_VIN);
    }
}//end on timer t_vin
/**___________________________________________________________________________________________________________________________**/